#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
Binary Lifting
*/
// Fill anc by DFS
int n, q;
const int maxN = 2e5;
const int maxS = 18;
vector<int> adj[maxN+1];
int anc[maxN+1][maxS];

void dfs(int u, int p) {
    anc[u][0] = p;
    for(int i = 1; i < maxS; ++i) {
        anc[u][i] = anc[anc[u][i-1]][i-1];
    }
    for(int v : adj[u]) {
        if(v == p) continue;
        dfs(v, u);
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    cin >> n >> q;
    for(int i = 2, a; i <= n; ++i) {
        cin >> a;
        adj[a].push_back(i);
    }

    dfs(1, 0);

    while(q--) {
        int u, k;
        cin >> u >> k;
        for(int i = 0; i < maxS; ++i) {
            if((k>>i)&1) {
                u = anc[u][i];
            }
        }
        if(u==0) cout << -1 << "\n";
        else cout << u << "\n";
    }
}

//// Fill anc by table dp
// int n, q;
// const int maxN = 2e5;
// const int maxS = 18;
// int anc[maxS][maxN+1];

// int main() {
//     ios::sync_with_stdio(0); 
//     cin.tie(0);

//     cin >> n >> q;
//     for(int i = 2, a; i <= n; ++i) {
//         cin >> a;
//         anc[0][i] = a;
//     }

//     while(q--) {
//         int u, k;
//         cin >> u >> k;
//         for(int i = 0; i < maxS; ++i) {
//             if((k>>i)&1) {
//                 u = anc[i][u];
//             }
//         }
//         if(u==0) cout << -1 << "\n";
//         else cout << u << "\n";
//     }
// }