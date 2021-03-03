#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
https://www.youtube.com/watch?v=kZfm68XKC58
*/

int n, m;
const int maxN = 2500, maxM = 5000;
vector<array<int, 3>> edges;
ll d[maxN+1];
int parent[maxN+1];

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }
    // We add an additional node 0 and connect it to all other nodes with weight 0, because we need to use single source algorithm on unconnected graph.
    for(int i = 1; i <= n; ++i) edges.push_back({0, i, 0});



    // Bellman-Ford, Remember now we have n+1 nodes, so run n times relax
    for(int i = 0; i < n; ++i) {
        for(auto [u, v, w] : edges) {
            if(d[v] > d[u] + w) {
                d[v] = d[u] + w;
                parent[v] = u;
            }
        }
    }
    // (n+1)th relax to detect negative cycle
    int cycleStart = -1;
    for(auto [u, v, w] : edges) {
        if(d[v] > d[u] + w) {
            parent[v] = u;
            cycleStart = v;
        }
    }
    if(cycleStart==-1) {
        cout << "NO";
        return 0;
    }

    cout << "YES\n";
    // Run n times backtrace based on parent[] to find the node in negative cycle
    for(int i = 0; i < n; ++i) {
        cycleStart = parent[cycleStart];
    }
    // backtrace based on parent and cycle node from above to print all nodes in cycle.
    vector<int> ans;
    int cur = cycleStart;
    while(true) {
        ans.push_back(cur);
        cur = parent[cur];
        if(cur==cycleStart) break;
    }
    ans.push_back(cycleStart);
    reverse(ans.begin(), ans.end());
    for(int node : ans) cout << node << " ";
}