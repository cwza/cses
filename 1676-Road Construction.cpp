#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
Disjoint-Set
*/

int n, m;
const int maxN = 1e5;
int link[maxN+1], sz[maxN+1];
int numComponent, sizeLargest;

int find(int x) {
    while(x != link[x]) x = link[x];
    return x;
}

bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x==y) return false;
    if(sz[x] < sz[y]) swap(x, y);
    link[y] = x;
    sz[x] += sz[y];
    numComponent--;
    sizeLargest = max(sizeLargest, sz[x]);
    return true;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    cin >> n >> m;
    numComponent = n;
    sizeLargest = 1;
    for(int i = 1; i <= n; ++i) {
        link[i] = i;
        sz[i] = 1;
    }

    while(m--) {
        int x, y;
        cin >> x >> y;
        unite(x, y);
        cout << numComponent << " " << sizeLargest << "\n";
    }
}