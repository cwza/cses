#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

int n, m, q;
const int maxN = 500;
const ll inf = 1e18;
ll d[maxN+1][maxN+1]; // Shortest Distance Between Nodes

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    // Initialize d
    fill(&d[0][0], &d[0][0]+(maxN+1)*(maxN+1), inf); // Init to +inf
    cin >> n >> m >> q; // Set d[u][v] from adjacency matrix
    for(int i = 1; i <= m; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);
        d[b][a] = min(d[b][a], c);
    }
    for(int i = 1; i <= n; ++i) d[i][i] = 0; // Set d[u][u] to 0

    // Run Floyed-Warshall
    for(int k = 1; k <= n; ++k) {
        for(int u = 1; u <= n; ++u) {
            for(int v = 1; v <= n; ++v) {
                if(d[u][k]==inf || d[k][v]==inf) continue;
                if(d[u][v] > d[u][k] + d[k][v]) {
                    d[u][v] = d[u][k] + d[k][v];
                }
            }
        }
    }

    for(int i = 0; i < q; ++i) {
        int u, v;
        cin >> u >> v;
        if(d[u][v] >= 1e18) cout << -1 << "\n";
        else cout << d[u][v] << "\n";
    }
}