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
int ans = 0;

void dfs1(int u, int p) {
    for(int v : adj[u]) {
        if(v == p) continue;
        dfs1(v, u);
        d[u] = max(d[u], d[v]+1);
    }
}

void dfs2(int u, int p) {
    vector<int> childD;
    for(int v : adj[u]) {
        if(v == p) continue;
        childD.push_back(d[v]);
    }
    sort(childD.begin(), childD.end(), greater<int>());
    int tmp = 0;
    for(int i = 0; i < 2 && i < childD.size(); ++i) {
        tmp += childD[i] + 1;
    }
    ans = max(ans, tmp);
    for(int v : adj[u]) {
        if(v == p) continue;
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

    dfs1(0, -1);
    dfs2(0, -1);

    cout << ans;
}