#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

int n;
const int maxN = 2e5;
vector<int> adj[maxN];
ll dp[maxN];

void dfs(int u) {
    dp[u] = 1;
    for(int v : adj[u]) {
        dfs(v);
        dp[u] += dp[v];
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    cin >> n;
    for(int i = 1, x; i < n; ++i) {
        cin >> x; x--;
        adj[x].push_back(i);
    }

    dfs(0);
    for(int i = 0; i < n; ++i) {
        cout << dp[i]-1 << " ";
    }
}