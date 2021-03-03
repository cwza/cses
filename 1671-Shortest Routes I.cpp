#include <bits/stdc++.h>
#include <functional>
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef array<ll, 2> al2;

int n, m;
const int maxN = 1e5;
const ll inf = 1e18;
vector<array<int, 2>> adj[maxN+1]; // [(node, w)]
bool visited[maxN+1];
ll d[maxN+1]; 


int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    fill(d, d+maxN+1, inf);
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    // Run Dijkstra
    priority_queue<al2, vector<al2>, greater<al2>> pq; // [(dist, node)]
    pq.push({0, 1}); d[1] = 0;
    while(pq.size()) {
        auto [du, u] = pq.top(); pq.pop();
        if(visited[u]) continue;
        visited[u] = true;
        for(auto [v, w] : adj[u]) {
            if(d[u]==inf) continue;
            if(d[v] > d[u]+w){
                d[v] = d[u]+w;
                pq.push({d[v], v});
            }
        }
    }

    for(int i = 1; i <= n; ++i) cout << d[i] << " ";
}