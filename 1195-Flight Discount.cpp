#include <bits/stdc++.h>
#include <functional>
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef array<ll, 2> al2; // (d, v)

///////////////////// Dijkstra + DP  ///////////////////////
// int n, m;
// const int maxN = 1e5, maxM = 2e5;
// const ll inf = 1e18;
// vector<array<int, 2>> adj[maxN+1]; // [(node, w)]
// ll d[maxN+1], couponD[maxN+1]; // d: shortest dist from src to others with no coupon, couponD: shortest dist from src to others with coupon

// int main() {
//     ios::sync_with_stdio(0); 
//     cin.tie(0);

//     fill(d, d+maxN+1, inf); fill(couponD, couponD+maxN+1, inf);
//     cin >> n >> m;
//     for(int i = 1; i <= m; ++i) {
//         int a, b, c;
//         cin >> a >> b >> c;
//         adj[a].push_back({b, c});
//     }

//     // First dijkstra to generate d
//     priority_queue<al2, vector<al2>, greater<al2>> pq;
//     bool visited[maxN+1] = {0};
//     pq.push({0, 1}); d[1] = 0;
//     while(pq.size()) {
//         auto [curD, u] = pq.top(); pq.pop();
//         if(visited[u]) continue;
//         visited[u] = true;
//         for(auto [v, w] : adj[u]) {
//             if(d[u]==inf) continue;
//             if(d[v] > d[u] + w) {
//                 d[v] = d[u] + w;
//                 pq.push({d[v], v});
//             }
//         }
//     }

//     // Second dijkstra + DP to generate couponD
//     // consider use coupon on this w or not
//     pq = priority_queue<al2, vector<al2>, greater<al2>>();
//     fill(visited, visited+maxN+1, 0);
//     pq.push({0, 1}); couponD[1] = 0;
//     while(pq.size()) {
//         auto [curD, u] = pq.top(); pq.pop();
//         if(visited[u]) continue;
//         visited[u] = true;
//         for(auto [v, w] : adj[u]) {
//             if(d[u]==inf && couponD[u]==inf) continue;
//             // couponD[u]+w: use coupon on previous not w
//             // d[u]+(w/2): use coupon on this w not previous
//             ll tmp = min(couponD[u]+w, d[u]+(w/2));
//             if(couponD[v] > tmp) {
//                 couponD[v] = tmp;
//                 pq.push({couponD[v], v});
//             }
//         }
//     }

//     cout << couponD[n];
// }


//////////////////////  2 Dijkstra  /////////////////////
int n, m;
const int maxN = 1e5, maxM = 2e5;
const ll inf = 1e18;
vector<array<int, 2>> srcAdj[maxN+1], targAdj[maxN+1]; // [(v, w)]
ll srcD[maxN+1], targD[maxN+1]; // srcD: shortest dist from src to others, targD: shortest dist from targ to others.

void dijkstra(int src, vector<array<int, 2>> adj[maxN+1], ll d[maxN+1]) {
    priority_queue<al2, vector<al2>, greater<al2>> pq; // (d[v], v)
    bool visited[maxN+1] = {0};
    pq.push({0, src}); d[src] = 0;
    while(pq.size()) {
        auto [du, u] = pq.top(); pq.pop();
        if(visited[u]) continue;
        visited[u] = true;
        for(auto [v, w] : adj[u]) {
            if(d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    fill(srcD, srcD+maxN+1, inf); fill(targD, targD+maxN+1, inf);
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        srcAdj[a].push_back({b, c});
        targAdj[b].push_back({a, c});
    }    
    dijkstra(1, srcAdj, srcD);
    dijkstra(n, targAdj, targD);

    // Try to use coupon on each egeds, then take the smallest one 
    ll ans = inf;
    for(int u = 1; u <= n; ++u) {
        for(auto [v, w] : srcAdj[u]) {
            ans = min(ans, srcD[u] + w/2 + targD[v]);
        }
    }
    cout << ans;
}