#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
Cycle Detection on Undirected Graph
*/

const int maxN = 1e5;
vector<int> adj[maxN+1];
int n, m;
int parent[maxN+1];
bool visited[maxN+1];
vector<int> ans;

void dfs(int u, int p) {
    visited[u] = true;
    parent[u] = p;
    for(int v : adj[u]) {
        if(v==p) continue;
        if(visited[v]) {
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
        else {
            dfs(v, u);
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
        adj[b].push_back(a);
    }

    for(int i = 1; i <= n; ++i) {
        if(!visited[i]) {
            dfs(i, 0);
        }
    }
    cout << "IMPOSSIBLE";
}

