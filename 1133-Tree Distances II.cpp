#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
https://usaco.guide/solutions/cses-1133?lang=cpp
*/

int n;
const int maxN = 2e5;
vector<int> adj[maxN];
int s[maxN]; // s[u]: number of nodes in u's subtree include u, root at 0
ll ans[maxN];

void dfs1(int u, int p, int d) {
    ans[0] += d;
    s[u] = 1;
    for(int v : adj[u]) {
        if(v == p) continue;
        dfs1(v, u, d+1);
        s[u] += s[v];
    }
}

void dfs2(int u, int p) {
    for(int v : adj[u]) {
        if(v == p) continue;
        ans[v] = ans[u] - s[v] + n-s[v];
        dfs2(v, u);
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

    dfs1(0, -1, 0);
    dfs2(0, -1);

    for(int i = 0; i < n; ++i) cout << ans[i] << " ";
}