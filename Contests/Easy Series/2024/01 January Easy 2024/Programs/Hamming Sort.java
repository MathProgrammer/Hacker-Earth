import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;

class Hamming implements Comparable<Hamming>
{
    int value;
    int K; 

    Hamming(int k, int v)
    {
        K = k; 
        value = v;
    }

    private int no_of_bits(int n)
    {
        int bits = 0;
        while(n > 0)
        {
            bits += n%2; 
            n /= 2;
        }

        return bits;
    }

    private int hammingDistance(int n)
    {
        return no_of_bits(n^K);
    }

    public int compareTo(Hamming H)
    {
        if(hammingDistance(this.value) == hammingDistance(H.value))
        {
            return (this.value - H.value);
        }
        
        return hammingDistance(this.value) - hammingDistance(H.value);
    }
}

class TestClass 
{
    public static int gcd(int m, int n)
    {
        if(Math.min(m, n) == 0)
        {
            return Math.max(m, n);
        }

        return gcd(Math.max(m, n)%Math.min(m, n), Math.min(m, n));
    }

    public static void main(String args[] ) throws Exception 
    {
        Scanner s = new Scanner(System.in);
        int no_of_test_cases = s.nextInt(); 
        
        for(int t = 1; t <= no_of_test_cases; t++)
        {
            int no_of_elements = s.nextInt();
            int K = s.nextInt();
            ArrayList <Hamming> A = new ArrayList <Hamming>(); 
            for(int i = 0; i < no_of_elements; i++)
            {
                int value = s.nextInt(); 
                A.add(new Hamming(K, value));
            }

            Collections.sort(A);

            for(Hamming H : A)
            {
                System.out.print(H.value + " ");
            }

            System.out.println();
        }
    }
}

