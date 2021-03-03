#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
Bitset DP on Graph

https://www.youtube.com/watch?v=-JjA4BLQyqE
from start to i through nodes in S
dp[S][i] = sum([dp[S\{i}][x] for x in S and x->i have edge])

Time: O(2^n * n^2), Space: O(2^n * n)
Note that the number of edges is much larger than the number of nodes, so we use adjacency matrix instead of adjacency list
*/

int n, m;
const int maxN = 20, M = 1e9+7;
ll adj[maxN][maxN];
ll dp[1<<maxN][maxN];

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0, a, b; i < m; ++i) {
        cin >> a >> b; a--; b--;
        adj[a][b]++;
    }

    dp[1][0] = 1;
    for(int b = 2; b < (1<<n); ++b) {
        // Suppose n is 3, then we only need dp[1111][3], to compute dp[1111][3] we only need dp[0...][.], so we skip all dp[1...][.] instead of dp[1111][.]
        if( b&(1<<(n-1)) && b!=(1<<n)-1 ) continue; // Special Optimization, 
        for(int i = 0; i < n; ++i) {
            if(!(b&1<<i)) continue; // if i is not in S, dp[S][i] should be 0
            for(int x = 0; x < n; ++x) {
                if(!adj[x][i]) continue;  // we only need the x that x->i hase edge
                ll tmp = (adj[x][i] * dp[b&~(1<<i)][x]) % M; // Two nodes may have multiple edges
                dp[b][i] = (dp[b][i] + tmp) % M;
            }
        }
    }
    cout << dp[(1<<n)-1][n-1];
}