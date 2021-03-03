#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
Run SCC to make graph be DAG, then run DP on it
*/

int n, m;
const int maxN = 1e5;
vector<int> adj[maxN+1], radj[maxN+1];
int coins[maxN+1];
vector<int> s;
bool visited[maxN+1];
int who[maxN+1];
vector<int> topo;
ll groupCoins[maxN+1];
set<int> sccAdj[maxN+1]; // Use set or you will got duplicated edges
ll dp[maxN+1];

void dfs1(int u) {
    for(int v : adj[u]) {
        if(!visited[v]) {
            visited[v] = true;
            dfs1(v);
            s.push_back(v);
        }
    }
}

void dfs2(int root, int u) {
    for(int v : radj[u]) {
        if(!visited[v]) {
            visited[v] = true;
            who[v] = root;
            groupCoins[root] += coins[v];
            dfs2(root, v);
        }
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> coins[i];
    for(int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }

    // SCC
    for(int u = 1; u <= n; ++u) {
        if(!visited[u]) {
            visited[u] = true;
            dfs1(u);
            s.push_back(u);
        }
    }
    fill(visited, visited+maxN+1, false);
    for(int i = s.size()-1; i >= 0; --i) {
        int u = s[i];
        if(!visited[u]) {
            visited[u] = true;
            who[u] = u;
            topo.push_back(u);
            groupCoins[u] += coins[u];
            dfs2(u, u);
        }
    }
    for(int u = 1; u <= n; ++u) {
        for(int v : adj[u]) {
            int uGroupId = who[u]; int vGroupId = who[v];
            if(uGroupId != vGroupId) {
                sccAdj[uGroupId].insert(vGroupId);
            }
        }
    }
    
    // DP
    copy(groupCoins, groupCoins+maxN+1, dp);
    ll ans = 0;
    for(int u : topo) {
        for(int v : sccAdj[u]) {
            dp[v] = max(dp[v], groupCoins[v]+dp[u]);
            ans = max(ans, dp[v]);
        }
    }

    cout << ans;
}