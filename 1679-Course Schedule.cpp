#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
Topological Sort
*/

int n, m;
const int maxN = 1e5;
vector<int> adj[maxN+1]; // u: [v, ...]
int visited[maxN+1]; // 0: init, 1: visiting, 2: visited
vector<int> ans;

void dfs(int u) {
    for(int v : adj[u]) {
        if(visited[v]==0) {
            visited[v] = 1;
            dfs(v);
            visited[v] = 2;
            ans.push_back(v);
        } else if(visited[v]==1) {
            cout << "IMPOSSIBLE";
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
            ans.push_back(u);
        }
    }
    reverse(ans.begin(), ans.end());
    for(int node : ans) cout << node << " ";
}