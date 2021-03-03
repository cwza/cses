#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
Maximum Bipartite Matching
Solution 1: DFS, Easy to implement but hard to understand
https://www.geeksforgeeks.org/maximum-bipartite-matching/

Idea:
u as applicant, v as job
for all u we do this:
  * We try to assign v to u
  * if v is free then assign it to u
  * if v has been assigned to some u' before, we ask if u' can take another job, if he can, then we reassign that job to u' and assign v to u
  * if u' can't find another free job, then we do not assign v to u
  * try another job
*/

int n, m, k;
const int maxN = 500, maxM = 500;
bool bpGraph[maxN][maxM]; // bpGraph[1][2] is true if boy1 want to dance with girl2
bool seen[maxM];
int assign[maxM]; // girl: boy

bool match(int u) {
    for(int v = 0; v < m; v++) {
        if(bpGraph[u][v]) {
            if(seen[v]) continue;
            seen[v] = true;
            if(assign[v]==-1 || match(assign[v])) {
                assign[v] = u;
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    cin >> n >> m >> k;
    for(int i = 0, u, v; i < k; ++i) {
        cin >> u >> v; u--; v--;
        bpGraph[u][v] = true;
    }

    int maxNumMatch = 0;
    fill(assign, assign+m, -1);
    for(int u = 0; u < n; ++u) {
        fill(seen, seen+m, false);
        if(match(u)) {
            maxNumMatch++;
        }
    } 

    cout << maxNumMatch << "\n";
    for(int i = 0; i < m; ++i) {
        if(assign[i]!=-1) {
            cout << assign[i]+1 << " " << i+1 << "\n";
        }
    }
}

/*
Solution 2: Max-Flow, Hard to implement but easy to understand
1. add source and sink, connect all boys to source and all girl to sink
2. Run max-flow
3. The edge that start from boy end with girl and capacity is 0 are answers
*/
// struct edge {
//     int u, v, rei;
//     ll cap;
// };

// int nboys, ngirls, k;
// int n, m;
// const int maxN = 1002, maxM = 2000;
// // const int maxN = 7, maxM = 9;
// vector<int> adj[maxN]; 
// edge edges[2*maxM];
// bool visited[maxN];


// int main() {
//     ios::sync_with_stdio(0); 
//     cin.tie(0);

//     // Generate graph, add source as index 0, sink as index nboys+ngirls+1
//     // map node 1 ~ nboys to boy, map node nboys+1 ~ nboys+ngirls to girl
//     // Connect each boy to source and each girl to sink
//     cin >> nboys >> ngirls >> k;
//     n = nboys + ngirls + 2;
//     m = nboys + k + ngirls;
//     for(int i = 0; i < nboys; ++i) {
//         int u = 0, v = i+1;
//         edges[2*i] = {u, v, 2*i+1, 1};
//         edges[2*i+1] = {v, u, 2*i, 0};
//         adj[u].push_back(2*i);
//         adj[v].push_back(2*i+1);
//     }
//     for(int j = 0, a, b; j < k; ++j) {
//         cin >> a >> b;
//         int i = nboys + j;
//         int u = a, v = nboys+b;
//         edges[2*i] = {u, v, 2*i+1, 1};
//         edges[2*i+1] = {v, u, 2*i, 0};
//         adj[u].push_back(2*i);
//         adj[v].push_back(2*i+1);
//     }
//     for(int j = 0; j < ngirls; ++j) {
//         int i = nboys + k + j;
//         int u = nboys + 1 + j;
//         int v = n - 1;
//         edges[2*i] = {u, v, 2*i+1, 1};
//         edges[2*i+1] = {v, u, 2*i, 0};
//         adj[u].push_back(2*i);
//         adj[v].push_back(2*i+1);
//     }

//     // Max-Flow
//     ll maxFlow = 0;
//     while(true) {
//         queue<int> q; q.push(0);
//         fill(visited, visited+n, false); visited[0] = true;
//         int d[n]; fill(d, d+n, 1e9); d[0] = 0;
//         int p[n]; fill(p, p+n, -1);
//         while(q.size()) {
//             int u = q.front(); q.pop();
//             for(int ei : adj[u]) {
//                 auto [_, v, rei, cap] = edges[ei];
//                 if(!visited[v] && cap > 0) {
//                     visited[v] = true;
//                     if(d[u]==1e9) continue;
//                     d[v] = d[u] + 1;
//                     p[v] = ei;
//                     q.push(v);
//                 }
//             }
//         }
//         if(d[n-1]==1e9) break;
//         int v = n-1;
//         ll flow = 1e18;
//         while(v) {
//             int ei = p[v];
//             auto [u, _, rei, cap] = edges[ei];
//             flow = min(flow, cap);
//             v = u;
//         }
//         maxFlow += flow;
//         v = n-1;
//         while(v) {
//             int ei = p[v];
//             edge &nEdge = edges[ei];
//             edge &rEdge = edges[nEdge.rei];
//             nEdge.cap -= flow;
//             rEdge.cap += flow;
//             v = nEdge.u;
//         }
//     }
//     cout << maxFlow << "\n";

//     // Check each edges between boy and girs if their capacity is 0, then that is answer
//     for(int j = 0; j < k; ++j) {
//         int i = nboys + j;
//         auto [u, v, _, cap] = edges[2*i];
//         if(cap==0) {
//             cout << u << " " << v-nboys << "\n";
//         }
//     }
// }