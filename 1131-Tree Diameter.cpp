#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

int n;
const int maxN = 2e5;
vector<int> adj[maxN];
int ans = 0;
int d[maxN];

void dfs(int u, int p) {
    for(int v : adj[u]) {
        if(v == p) continue;
        dfs(v, u);
        ans = max(ans, d[u]+d[v]+1);
        d[u] = max(d[u], d[v]+1);
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

    cout << ans;
}