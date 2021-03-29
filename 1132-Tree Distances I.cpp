#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
This alg is from CPH.
*/

int n;
const int maxN = 2e5;
vector<int> adj[maxN];
int d[maxN];
int ans[maxN];

void dfs1(int u, int p) {
    for(int v : adj[u]) {
        if(v == p) continue;
        dfs1(v, u);
        d[u] = max(d[u], d[v]+1);
    }
}

void dfs2(int u, int p, int pd) {
    ans[u] = max(d[u], pd);
    vector<array<int, 2>> a{{pd, -1}};
    for(int v: adj[u]) {
        if(v == p) continue;
        a.push_back({d[v]+1, v});
    }
    sort(a.begin(), a.end(), greater<array<int, 2>>());
    for(int v : adj[u]) {
        if(v == p) continue;
        if(a.size()==1) {
            dfs2(v, u, a[0][0]+1);
        }
        else {
            if(a[0][1] == v) dfs2(v, u, a[1][0]+1);
            else dfs2(v, u, a[0][0]+1);
        }
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

    dfs1(0, -1);
    dfs2(0, -1, 0);

    for(int i = 0; i < n; ++i) cout << ans[i] << " ";
}