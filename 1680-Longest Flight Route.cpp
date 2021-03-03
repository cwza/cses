#include <bits/stdc++.h>
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef array<ll, 2> al2;

/////////////////////////// set all weight = -1 then run relax by topological sort order ///////////////////////////
// int n, m;
// const int maxN = 1e5;
// const ll inf = 1e18;
// vector<int> adj[maxN+1]; // u: [v, ...]
// bool visited[maxN+1];
// vector<int> topo;
// ll d[maxN+1];
// int parent[maxN+1];

// void dfs(int u) {
//     for(int v : adj[u]) {
//         if(!visited[v]) {
//             visited[v] = true;
//             dfs(v);
//             topo.push_back(v);
//         }
//     }
// }

// int main() {
//     ios::sync_with_stdio(0); 
//     cin.tie(0);

//     cin >> n >> m;
//     for(int i = 1; i <= m; ++i) {
//         int a, b;
//         cin >> a >> b;
//         adj[a].push_back(b);
//     }

//     // Find Topological Sort
//     for(int u = 1; u <= n; ++u) {
//         if(!visited[u]) {
//             visited[u] = true;
//             dfs(u);
//             topo.push_back(u);
//         }
//     }
//     reverse(topo.begin(), topo.end());

//     // Relax by topological order
//     fill(d, d+maxN+1, inf); d[1] = 0;
//     for(int u : topo) {
//         for(int v : adj[u]) {
//             if(d[u]==inf) continue;
//             if(d[v] > d[u] - 1) { // weight is all -1
//                 d[v] = d[u] - 1;
//                 parent[v] = u;
//             }
//         }
//     }

//     // Backtrack by parent to print answer
//     if(d[n]==inf) {
//         cout << "IMPOSSIBLE";
//         return 0;
//     }
//     vector<int> ans;
//     int cur = n;
//     while(cur!=0) {
//         ans.push_back(cur);
//         cur = parent[cur];
//     }
//     reverse(ans.begin(), ans.end());
//     cout << ans.size() << "\n";
//     for(int u : ans) cout << u << " ";
// }



///////////////////////////  push dp by topological sort order  /////////////////////
int n, m;
const int maxN = 1e5;
const ll ninf = -1e18;
vector<int> adj[maxN+1]; // u: [v, ...]
bool visited[maxN+1];
vector<int> topo;
ll dp[maxN+1]; // Distance from 0 to others
int parent[maxN+1];

void dfs(int u) {
    for(int v : adj[u]) {
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
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    // Find Topological Sort
    for(int u = 1; u <= n; ++u) {
        if(!visited[u]) {
            visited[u] = true;
            dfs(u);
            topo.push_back(u);
        }
    }
    reverse(topo.begin(), topo.end());

    // DP by topological order
    fill(dp, dp+maxN+1, ninf); dp[1] = 0;
    for(int u : topo) {
        for(int v : adj[u]) {
            if(dp[u] == ninf) continue;
            if(dp[u]+1 > dp[v]) {
                dp[v] = max(dp[v], dp[u]+1);
                parent[v] = u;
            }
        }
    }
    
    // Backtrack by parent to print answer
    if(dp[n]==ninf) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    vector<int> ans;
    int cur = n;
    while(cur!=1) {
        ans.push_back(cur);
        cur = parent[cur];
    }
    ans.push_back(cur);
    reverse(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(int u : ans) cout << u << " ";
}



///////////////////////////  push dp by dfs end time order  /////////////////////////
// int n, m;
// const int maxN = 1e5;
// const ll ninf = -1e18;
// vector<int> adj[maxN+1]; // u: [v, ...]
// bool visited[maxN+1];
// ll dp[maxN+1]; // dp[i]: Distance from node i to node n
// int parent[maxN+1];

// void dfs(int u) {
//     for(int v : adj[u]) {
//         if(!visited[v]) {
//             visited[v] = true;
//             dfs(v);
//         }
//         if(dp[v]==ninf) continue;
//         if(dp[u] < dp[v] + 1) {
//             dp[u] = dp[v] + 1;
//             parent[u] = v;
//         }
//     }
// }

// int main() {
//     ios::sync_with_stdio(0); 
//     cin.tie(0);

//     cin >> n >> m;
//     for(int i = 1; i <= m; ++i) {
//         int a, b;
//         cin >> a >> b;
//         adj[a].push_back(b);
//     }

//     // dp by dfs end time order
//     fill(dp, dp+maxN+1, ninf); dp[n] = 0;
//     for(int u = 1; u <= n; ++u) {
//         if(!visited[u]) {
//             visited[u] = true;
//             dfs(u);
//         }
//     }

//     // Backtrack by parent to print answer
//     if(dp[1]==ninf) {
//         cout << "IMPOSSIBLE";
//         return 0;
//     }
//     vector<int> ans;
//     int cur = 1;
//     while(cur!=n) {
//         ans.push_back(cur);
//         cur = parent[cur];
//     }
//     ans.push_back(cur);
//     cout << ans.size() << "\n";
//     for(int u : ans) cout << u << " ";
// }

