#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
https://www.youtube.com/watch?v=2Epc8xZObIc
*/

int n, m;
const int maxN = 2500, maxM = 5000;
const ll inf = 1e18, ninf = -inf;
array<int, 3> edges[maxM]; // (u, v, w)
ll d[maxN+1];

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = {a, b, -c};
    }
    fill(d, d+maxN+1, inf);
    d[1] = 0;

    // Run Bellman-Ford
    for(int i = 0; i < n-1; ++i) {
        for(auto [u, v, w] : edges) {
            if(d[u]==inf) continue;
            if(d[v] > d[u] + w) {
                d[v] = d[u] + w;
            }
        }
    }
    for(int i = 0; i < n-1; ++i) {
        for(auto [u, v, w] : edges) {
            if(d[u]==inf) continue;
            if(d[v] > d[u] + w) {
                d[v] = ninf;
            }
        }
    }
    if(d[n] == ninf) cout << -1;
    else cout << -d[n];
}