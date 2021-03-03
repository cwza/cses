#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
Cycle Detection
*/

int n, m;
const int maxN = 1e5;
vector<int> adj[maxN+1]; // u: [v, ...]
int visited[maxN+1]; // 0: init, 1: visiting, 2: visited
int parent[maxN+1];

void dfs(int u) {
    for(int v : adj[u]) {
        if(visited[v]==0) {
            visited[v] = 1;
            parent[v] = u;
            dfs(v);
            visited[v] = 2;
        } else if(visited[v]==1) {
            vector<int> ans; ans.push_back(v);
            int cur = u;
            while(cur!=v) {
                ans.push_back(cur);
                cur = parent[cur];
            }
            ans.push_back(v);
            reverse(ans.begin(), ans.end());
            cout << ans.size() << "\n";
            for(int node : ans) cout << node << " ";
            exit(0);
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

    for(int u = 1; u <= n; ++u) {
        if(visited[u]==0) {
            visited[u] = 1;
            dfs(u);
            visited[u] = 2;
        }
    }
    cout << "IMPOSSIBLE";
}