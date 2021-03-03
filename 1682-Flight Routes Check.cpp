#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
Strongly Connected Component
*/

int n, m;
const int maxN = 1e5;
vector<int> adj[maxN+1], radj[maxN+1];
bool visited[maxN+1];
stack<int> s;
int scc[maxN+1];

void dfs1(int u) {
    for(int v : adj[u]) {
        if(!visited[v]) {
            visited[v] = true;
            dfs1(v);
            s.push(v);
        }
    }
}

void dfs2(int s, int u) {
    for(int v : radj[u]) {
        if(!visited[v]) {
            visited[v] = true;
            scc[v] = s;
            dfs2(s, v);
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
        radj[b].push_back(a);
    }

    for(int u = 1; u <= n; ++u) {
        if(!visited[u]) {
            visited[u] = true;
            dfs1(u);
            s.push(u);
        }
    }

    fill(visited, visited+maxN+1, false);
    vector<int> roots;
    while(s.size()) {
        int u = s.top(); s.pop();
        if(!visited[u]) {
            visited[u] = true;
            scc[u] = u;
            roots.push_back(u);
            dfs2(u, u);
        }
    }
    if(roots.size()==1) {
        cout << "YES";
        return 0;
    }
    cout << "NO\n";
    cout << roots[1] << " " << roots[0];
}