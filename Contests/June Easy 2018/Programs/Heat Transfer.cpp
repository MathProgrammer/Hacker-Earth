#include <cstdio>
#include <cstring>

const int N = 105, MOD = 1e9 + 7;
int rows, columns;

void make_identity(long long I[][N])
{
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            I[i][j] = (i == j ? 1 : 0);
}

void copy(long long A[][N], long long B[][N])
{
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            B[i][j] = A[i][j];
}

void multiply(long long A[][N], long long B[][N])
{
    long long P[N][N];

    for(int row = 0; row < N; row++)
    {
        for(int column = 0; column < N; column++)
        {
            P[row][column] = 0;

            for(int i = 0; i < N; i++)
                P[row][column] += (A[row][i]*B[i][column])%MOD;

            P[row][column] %= MOD;
        }
    }

    copy(P, A);
}

void power(long long X[][N], long long power)
{
    long long result[N][N];

    make_identity(result);

    while(power)
    {
        if(power%2 == 1)
            multiply(result, X);

        multiply(X, X);
        power = power >> 1;
    }

    copy(result, X);
}

int get_index(int i, int j)
{
    return (columns*i + j);
}

int main()
{
	int k, seconds;
	scanf("%d %d %d %d", &rows, &columns, &k, &seconds);

	long long grid[N][N];
	for(int r = 0; r < rows; r++)
	    for(int c = 0; c < columns; c++)
	        scanf("%lld", &grid[r][c]);

    long long A[1][N];
    for(int r = 0; r < rows; r++)
        for(int c = 0; c < columns; c++)
            A[0][get_index(r, c)] = grid[r][c];

    long long matrix[N][N];
	for(int r = 0; r < rows; r++)
    {
        for(int c = 0; c < columns; c++)
        {
            int here_index = get_index(r, c);
            matrix[here_index][here_index] = 1;

            const int NO_OF_NEIGHBOURS = 4;
            int neighbour_x[4] = {-1, 0, 0, 1};
            int neighbour_y[4] = {0, 1, -1, 0};

            for(int i = 0; i < NO_OF_NEIGHBOURS; i++)
            {
                if(r + neighbour_x[i] < 0 || r + neighbour_x[i] >= rows || c + neighbour_y[i] < 0 || c + neighbour_y[i] >= columns)
                    continue;

                int neighbour_index = get_index(r + neighbour_x[i], c + neighbour_y[i]);

                matrix[here_index][here_index] += MOD - k; matrix[here_index][here_index] %= MOD;
                matrix[neighbour_index][here_index] += k; matrix[neighbour_index][here_index] %= MOD;
            }
        }
    }

    power(matrix, seconds);

    multiply(A, matrix);

    for(int i = 0; i < rows*columns; i++)
    {
        printf("%lld ", A[0][i]);

        if( (i + 1)%columns == 0) //End of row
            printf("\n");
    }

	return 0;
}


