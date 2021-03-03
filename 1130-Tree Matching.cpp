#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
https://usaco.guide/gold/dp-trees?lang=cpp
*/

int n;
const int maxN = 2e5;
vector<int> adj[maxN];
int dp[maxN][2];

void dfs(int u, int p) {
    for(int v : adj[u]) {
        if(v == p) continue;
        dfs(v, u);
        dp[u][0] += max(dp[v][0], dp[v][1]);
    }
    for(int v: adj[u]) {
        if(v == p) continue;
        dp[u][1] = max(dp[u][1], 1+dp[v][0] + dp[u][0]-max(dp[v][0], dp[v][1]));
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    cin >> n;
    for(int i = 0, u, v; i < n-1; ++i) {
        cin >> u >> v; u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, -1);

    cout << max(dp[0][0], dp[0][1]);
}