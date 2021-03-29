#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

int n, q;
const int maxN = 2e5, maxS = 18;
vector<int> adj[maxN+1];
int level[maxN+1];
int anc[maxN+1][maxS];

void dfs1(int u, int p) {
    anc[u][0] = p;
    for(int i = 1; i < maxS; ++i) {
        anc[u][i] = anc[anc[u][i-1]][i-1];
    }
    for(int v : adj[u]) {
        if(v == p) continue;
        level[v] = level[u] + 1;
        dfs1(v, u);
    }
}

int lift(int u, int k) {
    for(int i = 0; i < maxS; ++i) {
        if((k>>i)&1) {
            u = anc[u][i];
        }
    }
    return u;
}

int lca(int u, int v) {
    if(level[u] < level[v]) swap(u, v);
    u = lift(u, level[u]-level[v]);
    if(u==v) return u;
    for(int i = maxS-1; i >= 0; --i) {
        if(anc[u][i] != anc[v][i]) {
            u = anc[u][i];
            v = anc[v][i];
        }
    }
    return anc[u][0];
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    cin >> n >> q;
    for(int i = 1, u, v; i <= n-1; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs1(1, 0);
    
    while(q--) {
        int u, v;
        cin >> u >> v;
        cout << level[u] + level[v] - 2*level[lca(u, v)] << "\n";
    }
}