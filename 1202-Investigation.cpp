#include <bits/stdc++.h>
#include <functional>
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef array<ll, 2> al2;


//////////////////////////  Modified Dijkstra  /////////////////////
// int n, m;
// const int maxN = 1e5, M = 1e9+7;
// const ll inf = 1e18;
// vector<array<int, 2>> adj[maxN+1]; // u: [(v, w), ...]
// bool visited[maxN+1];
// ll d[maxN+1];
// int numR[maxN+1], minF[maxN+1], maxF[maxN+1];

// int main() {
//     ios::sync_with_stdio(0); 
//     cin.tie(0);

//     cin >> n >> m;
//     for(int i = 1; i <= m; ++i) {
//         int a, b, c;
//         cin >> a >> b >> c;
//         adj[a].push_back({b, c});
//     }

//     fill(d, d+maxN+1, inf);
//     priority_queue<al2, vector<al2>, greater<al2>> pq;
//     pq.push({0, 1}); d[1] = 0; numR[1] = 1; minF[1] = 0; maxF[1] = 0;
//     while(pq.size()) {
//         auto [du, u] = pq.top(); pq.pop();
//         if(visited[u]) continue;
//         visited[u] = true;
//         for(auto [v, w] : adj[u]) {
//             if(du==inf || du+w > d[v]) {
//                 continue;
//             }
//             else if(du+w < d[v]) {
//                 d[v] = du+w; 
//                 numR[v] = numR[u]; 
//                 minF[v] = minF[u]+1; 
//                 maxF[v] = maxF[u]+1;
//                 pq.push({d[v], v});
//             }
//             else {
//                 d[v] = d[v]; 
//                 numR[v] = (numR[v]+numR[u])%M; 
//                 minF[v] = min(minF[v], minF[u]+1);
//                 maxF[v] = max(maxF[v], maxF[u]+1);
//                 pq.push({d[v], v});
//             }
//         }
//     }
//     cout << d[n] << " " << numR[n] << " " << minF[n] << " " << maxF[n];
// }



///////////////////////  Shortest Path Tree + DP  ////////////////////

int n, m;
const int maxN = 1e5, M = 1e9+7;
const ll inf = 1e18, ninf = -inf;
vector<array<int, 2>> oriAdj[maxN+1]; // u: [(v, w), ...]
vector<int> sptAdj[maxN+1]; // shortest path tree graph, u: [v, ...]
bool visited[maxN+1];
ll d[maxN+1]; // shortest path from 1 to others
vector<int> topo;
ll dp[maxN+1];

void dfs(int u) {
    for(int v : sptAdj[u]) {
        if(!visited[v]) {
            visited[v] = true;
            dfs(v);
            topo.push_back(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        oriAdj[a].push_back({b, c});
    }

    // Dijkstra to generate d[]
    fill(d, d+maxN+1, inf);
    priority_queue<al2, vector<al2>, greater<al2>> pq;
    pq.push({0, 1}); d[1] = 0;
    while(pq.size()) {
        auto [du, u] = pq.top(); pq.pop(); 
        if(visited[u]) continue;
        visited[u] = true;
        for(auto [v, w] : oriAdj[u]) {
            if(d[v] > du + w) {
                d[v] = du + w;
                pq.push({d[v], v});
            }
        }
    }
    cout << d[n] << " ";
    // Generate Shortest Path Graph which has no cycle
    for(int u = 1; u <= n; ++u) {
        for(auto [v, w] : oriAdj[u]) {
            if(d[u] + w == d[v]) {
                sptAdj[u].push_back(v);
            }
        }
    }
    // Find topological order
    fill(visited, visited+maxN+1, false);
    for(int u = 1; u <= n; ++u) {
        if(!visited[u]) {
            visited[u] = true;
            dfs(u);
            topo.push_back(u);
        }
    }
    reverse(topo.begin(), topo.end());
    // DP1: number of minimum-price routes from 1 to others
    dp[1] = 1;
    for(int u : topo) {
        for(int v : sptAdj[u]) {
            dp[v] = (dp[v] + dp[u]) % M;
        }
    }
    cout << dp[n] << " ";
    // DP2: the minimum number of flights in a minimum-price route from 1 to others
    fill(dp, dp+maxN+1, inf);
    dp[1] = 0;
    for(int u : topo) {
        for(int v : sptAdj[u]) {
            dp[v] = min(dp[v], dp[u]+1);
        }
    }
    cout << dp[n] << " ";
    // DP3: the maximum number of flights in a minimum-price route from 1 to others
    fill(dp, dp+maxN+1, ninf);
    dp[1] = 0;
    for(int u : topo) {
        for(int v : sptAdj[u]) {
            dp[v] = max(dp[v], dp[u]+1);
        }
    }
    cout << dp[n] << " ";
}