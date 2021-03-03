#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
Minimum-Spanning Tree by Disjoint-Set
*/

int n, m;
const int maxN = 1e5, maxM = 2e5;
array<int, 3> edges[maxM];  // [(w, u, v)]
int link[maxN+1], sz[maxN+1];

int find(int x) {
    while(x != link[x]) x = link[x];
    return x;
}

bool unite(int x, int y) {
    x = find(x); y = find(y);
    if(x==y) return false;
    if(sz[x] < sz[y]) swap(x, y);
    link[y] = x;
    sz[x] += sz[y];
    return true;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = {c, a, b};
    }
    for(int i = 1; i <= n; ++i) {
        link[i] = i;
        sz[i] = 1;
    }

    sort(edges, edges+m);
    int nTreeEdge = 0;
    ll ans = 0;
    for(auto [w, u, v] : edges) {
        if(unite(u, v)) {
            nTreeEdge++;
            ans += w;
        }
    }
    if(nTreeEdge != n-1) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    cout << ans;
}