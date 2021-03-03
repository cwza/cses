#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
Find Min-Cut
*/

struct edge {
    int u, v, rei;
    ll cap;
};

int n, m;
const int maxN = 500, maxM = 1000;
vector<int> adj[maxN];
edge edges[2*maxM]; 
bool visited[maxN];

void dfs(int u) {
    for(int ei : adj[u]) {
        auto [_, v, rei, cap] = edges[ei];
        if(!visited[v] && cap > 0) {
            visited[v] = true;
            dfs(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0, u, v; i < m; ++i) {
        cin >> u >> v; u--; v--;
        edges[2*i] = {u, v, 2*i+1, 1};
        edges[2*i+1] = {v, u, 2*i, 1};
        adj[u].push_back(2*i);
        adj[v].push_back(2*i+1);
    }

    // Max-Flow
    ll maxFlow = 0;
    while(true) {
        queue<int> q; q.push(0);
        fill(visited, visited+n, false); visited[0] = true;
        int d[n]; fill(d, d+n, 1e9); d[0] = 0;
        int p[n]; fill(p, p+n, -1);
        while(q.size()) {
            int u = q.front(); q.pop();
            for(int ei : adj[u]) {
                auto [_, v, rei, cap] = edges[ei];
                if(!visited[v] && cap > 0) {
                    visited[v] = true;
                    if(d[u]==1e9) continue;
                    d[v] = d[u] + 1;
                    p[v] = ei;
                    q.push(v);
                }
            }
        }
        if(d[n-1]==1e9) break;
        int v = n-1;
        ll flow = 1e18;
        while(v) {
            int ei = p[v];
            auto [u, _, rei, cap] = edges[ei];
            flow = min(flow, cap);
            v = u;
        }
        maxFlow += flow;
        v = n-1;
        while(v) {
            int ei = p[v];
            edge &nEdge = edges[ei];
            edge &rEdge = edges[nEdge.rei];
            nEdge.cap -= flow;
            rEdge.cap += flow;
            v = nEdge.u;
        }
    }
    cout << maxFlow << "\n";

    // Find Min-Cut
    // The min-cut edges are u->v that u is reachable from source by positive edges and v is not, and the remain capacity from u to v is 0 
    fill(visited, visited+n, false); visited[0] = true;
    dfs(0);
    for(int i = 0; i < 2*m; ++i) {
        auto [u, v, _, cap] = edges[i];
        if(visited[u] && !visited[v] && cap==0) {
            cout << u+1 << " " << v+1 << "\n";
        }
    }
}