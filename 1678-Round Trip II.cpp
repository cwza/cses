#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
Cycle Detection
*/

int n, m;
const int maxN = 1e5;
vector<int> adj[maxN+1]; // u: [v, ...]
bool visited[maxN+1], acting[maxN+1];
int parent[maxN+1];
vector<int> ans;

void dfs(int u) {
    visited[u] = true;
    acting[u] = true;
    for(int v : adj[u]) {
        if(acting[v]) {
            int cur = u;
            ans.push_back(v);
            while(cur!=v) {
                ans.push_back(cur);
                cur = parent[cur];
            }
            ans.push_back(v);
            cout << ans.size() << "\n";
            for(int i = ans.size()-1; i>=0; --i) cout << ans[i] << " ";
            exit(0);
        } 
        if(!visited[v]) {
            parent[v] = u;
            dfs(v);
        }
    }
    acting[u] = false;
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

    for(int u = 1; u <= n; ++u) {
        if(!visited[u]) {
            dfs(u);
        }
    }
    cout << "IMPOSSIBLE";
}