#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
 
#define LEFT(n) (2*n)
#define RIGHT(n) (2*n + 1)
#define all(v) (v).begin(), (v).end()
using namespace std;
 
const int MAX_N = 3e5 + 5;
multiset <int> current_chain;
vector <int> tree[MAX_N];
long long cost[MAX_N], best_CD[MAX_N];
int visited_time[MAX_N], at_time[MAX_N], chain_size[MAX_N], max_in_subtree[MAX_N];
int time_now = 0, no_of_vertices;
 
class merge_sort_tree
{
    public :
    
    vector <pair <int, int> > tree[4*MAX_N];
    vector <long long> suffix_max[4*MAX_N];
    
    void build(int n, int left, int right)
    {
        if(left == right)
        {   //cout << n << " corresponds to " << right << "\n";
            int v = at_time[left];
            tree[n].push_back(make_pair(cost[v], v));
            
            return;
        }
        
        int mid = (left + right)/2;
        build(LEFT(n), left, mid);
        build(RIGHT(n), mid + 1, right);
        
        merge(all(tree[LEFT(n)]), all(tree[RIGHT(n)]), back_inserter(tree[n]));
        
        //cout << "N = " << n << " L = " << left << " R = " << right << " Size = " << tree[n].size() << "\n";
    }
    
    //Return maximum element > Value
    int search(int n, int left, int right, int query_left, int query_right, int value)
    {
        if(query_right < left || right < query_left || right < left || query_right < query_left)
        {
            return 0;
        }
        
        if(query_left <= left && right <= query_right)
        {
            if(tree[n].empty() || tree[n].back().first <= value)
            {
                return 0;
            }
            
            int L = 0, R = tree[n].size() - 1;
            
            if(tree[n][L].first > value)
            {
                return suffix_max[n][L];
            }
            
            while(R - L > 1)
            {
                int M = (L + R)/2;
                
                if(tree[n][M].first > value)
                {
                    R = M;
                }
                else 
                {
                    L = M;
                }
            }
            
            //cout << "V = " << n << " Value = " << value << " N = " << n << " R = " << R << " Suffix Max = " << suffix_max[n][R] << "\n";
            return suffix_max[n][R];
        }
        
        int mid = (left + right)/2;
        int left_max = search(LEFT(n), left, mid, query_left, query_right, value);
        int right_max = search(RIGHT(n), mid + 1, right, query_left, query_right, value);
        
        /*if(value == 3)
        {
            cout << "LM = " << left_max << " and RM = " << right_max << "\n";
        }*/
        return max(left_max, right_max);
    }
    
    void build_suffix_max()
    {
        for(int i = 1; i < 4*no_of_vertices; i++)
        {
            if(tree[i].size() == 0)
            {
                continue;
            }
            
            suffix_max[i].resize(tree[i].size());
            
            suffix_max[i].back() = best_CD[tree[i].back().second];
            //cout << "Suffix Max " << i << " Node = " << tree[i].back().second << " j = " << tree[i].size() - 1 << " = " << suffix_max[i].back() << "\n";
            for(int j = tree[i].size() - 2; j >= 0; j--)
            {
                suffix_max[i][j] = max(suffix_max[i][j + 1], best_CD[tree[i][j].second]);
                //cout << "Suffix Max " << i << " j = " << j << " = " << suffix_max[i][j] << "\n";
            }
        }
    }
};
 
merge_sort_tree MT;
 
void dfs(int v, int parent)
{
    time_now++;
    visited_time[v] = time_now;
    at_time[time_now] = v;
    
    chain_size[v] = 1;
    max_in_subtree[v] = cost[v];
    
    for(int i = 0; i < tree[v].size(); i++)
    {
        int v_child = tree[v][i];
        
        if(v_child == parent) 
        {
            continue;
        }
        
        dfs(v_child, v);
        
        chain_size[v] += chain_size[v_child];
        max_in_subtree[v] = max(max_in_subtree[v], max_in_subtree[v_child]);
    }
}
 
long long dfs_answer(int v, int parent)
{
    current_chain.insert(cost[v]);
    
    long long answer = 0;
    
    auto best_A_ptr = current_chain.lower_bound(cost[v]);
    
    //V is B in our quadruple (A, B, C, D)
    if(best_A_ptr != current_chain.begin() && best_CD[v] != 0)
    {   
        long long best_CD_from_here = MT.search(1, 1, no_of_vertices, 
                                    visited_time[v] + 1, visited_time[v] + chain_size[v] - 1, cost[v]);
                                    
        if(best_CD_from_here != 0)
        {
            best_A_ptr--;
            
            int best_A = *best_A_ptr;
            
            answer = best_A + cost[v] + best_CD_from_here;
        }
        
        //cout << "A = " << *best_A_ptr << " B = " << v << " CD = " << best_CD_from_here << " Answer = " << answer << "\n";
        /*if(best_A_ptr != current_chain.begin())
        {
            int best_A = *best_A_ptr; //cout << "B = " << v << " A = " << best_A << "\n";
        
            long long best_CD_from_here = MT.search(1, 1, no_of_vertices, 
                                    visited_time[v] + 1, visited_time[v] + chain_size[v] - 1, cost[v]);
        
            //cout << "Best CD = " << best_CD_from_here << "\n";
            if(best_CD_from_here != 0)
            {
                answer = best_A + cost[v] + best_CD_from_here;
            }
        }*/
    }
    
    for(int i = 0; i < tree[v].size(); i++)
    {
        int v_child = tree[v][i];
        
        if(v_child == parent)
        {
            continue;
        }
        
        answer = max(answer,dfs_answer(v_child, v));
    }
    
    current_chain.erase(current_chain.find(cost[v]));
    
    //cout << "B = " << v << " Answer = " << answer << "\n";
    return answer;
}
 
int main() 
{
  scanf("%d", &no_of_vertices);
	
	for(int i = 1; i <= no_of_vertices; i++)
	{
	    scanf("%lld", &cost[i]);
	}
	
	int no_of_edges = no_of_vertices - 1;
	for(int i = 1; i <= no_of_edges; i++)
	{
	    int u, v;
	    scanf("%d %d", &u, &v);
	    
	    tree[u].push_back(v);
	    tree[v].push_back(u);
	}
	
	dfs(1, 0);
	
	for(int i = 1; i <= no_of_vertices; i++)
	{
	    best_CD[i] = (max_in_subtree[i] != cost[i] ? cost[i] + max_in_subtree[i] : 0);
	    
	    //cout << "i = " << i << " Best CD = " << best_CD[i] << "\n";
	}
	
	MT.build(1, 1, no_of_vertices);
	MT.build_suffix_max();
	
	long long answer = dfs_answer(1, 0);
	
	printf("%lld\n", answer);
	return 0;
}
