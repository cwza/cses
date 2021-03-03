#include <bits/stdc++.h>
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef array<ll, 2> al2;

int n, m, k;
const int maxN = 1e5, maxM = 2e5;
vector<array<int, 2>> adj[maxN+1]; // u: [(v, w), ...]
vector<ll> d[maxN+1];

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    cin >> n >> m >> k;
    for(int i = 1; i <= m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    priority_queue<al2, vector<al2>, greater<al2>> pq; // (d[v], v)
    pq.push({0, 1});
    // Note that the correct order should be the order that pop out from the priority queue, so we need to update d[] after queue pop
    while(pq.size()) {
        auto [du, u] = pq.top(); pq.pop();
        if(d[u].size() >= k) continue;
        d[u].push_back(du);
        for(auto [v, w] : adj[u]) {
            pq.push({du+w, v});
        }
    }
    for(ll ans : d[n]) cout << ans << " ";
}