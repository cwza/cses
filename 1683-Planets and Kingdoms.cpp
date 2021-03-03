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
vector<int> s;
int who[maxN+1];

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
            dfs2(root, v);
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
            s.push_back(u);
        }
    }

    fill(visited, visited+maxN+1, false);
    vector<int> roots;
    for(int i = s.size()-1; i >= 0; --i) {
        int u = s[i];
        if(!visited[u]) {
            visited[u] = true;
            who[u] = u;
            roots.push_back(u);
            dfs2(u, u);
        }
    }
    cout << roots.size() << "\n";
    map<int, int> table;
    for(int i = 0; i < roots.size(); ++i) {
        table[roots[i]] = i+1;
    }
    for(int u = 1; u <= n; ++u) cout << table[who[u]]<< " ";
}