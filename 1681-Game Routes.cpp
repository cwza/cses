#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

int n, m;
const int maxN = 1e5, M = 1e9+7;
vector<int> adj[maxN+1]; // u: [v, ...]
bool visited[maxN+1];
vector<int> topo;
int dp[maxN+1]; // number of ways from 1 to others

void dfs(int u) {
    for(int v : adj[u]) {
        if(!visited[v]) {
            visited[v] = true;
            dfs(v);
            topo.push_back(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    // Topological Sort
    for(int u = 1; u <= n; ++u) {
        if(!visited[u]) {
            visited[u] = true;
            dfs(u);
            topo.push_back(u);
        }
    }
    reverse(topo.begin(), topo.end());

    // Push DP
    dp[1] = 1;
    for(int u : topo) {
        for(int v : adj[u]) {
            dp[v] = (dp[v]+dp[u]) % M;
        }
    }

    cout << dp[n];
}