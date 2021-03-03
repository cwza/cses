#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

int n, q;
const int maxN = 2e5;
int x[maxN+1];

struct node {
    ll s, lz;
};
node tree[1<<19];

void lzRangeUpdate(int x, int y, int delta, int i = 1, int l = 1, int r = n) {
    // Update tree[i] to the latest value, and propagate lz to its children
    if(tree[i].lz != 0) {
        tree[i].s += tree[i].lz;
        if(l != r) { // if not leaf, we propagate lz to children
            tree[2*i].lz += tree[i].lz;
            tree[2*i+1].lz += tree[i].lz;
        }
        tree[i].lz = 0;
    }
    if(x > r || y < l) { // [x, y] completely not overlap with [l, r]
        return;
    }
    if(x <= l && y >= r) { // [x, y] completely cover [l, r]
        tree[i].s += delta; // update tree[i]
        if(l != r) { // if not leaf, we propagate delta to children's lz
            tree[2*i].lz += delta;
            tree[2*i+1].lz += delta;
        }
        return;
    }
    // [x, y] partially overlap with [l, r]
    int mid = l + (r-l)/2;
    lzRangeUpdate(x, y, delta, 2*i, l, mid);
    lzRangeUpdate(x, y, delta, 2*i+1, mid+1, r); 
    tree[i].s = tree[2*i].s + tree[2*i+1].s;
}

ll lzRangeQuery(int x, int y, int i = 1, int l = 1, int r = n) {
    // Update tree[i] to the latest value, and propagate lz to its children
    if(tree[i].lz != 0) {
        tree[i].s += tree[i].lz;
        if(l != r) {
            tree[2*i].lz += tree[i].lz;
            tree[2*i+1].lz += tree[i].lz;
        }
        tree[i].lz = 0;
    }
    if(x > r || y < l) { // [x, y] completely not overlap with [l, r]
        return 0;
    }
    if(x <= l && y >= r) { // [x, y] completely cover [l, r]
        return tree[i].s;
    }
    // [x, y] partially overlap with [l, r]
    int mid = l + (r-l)/2;
    ll v1 = lzRangeQuery(x, y, 2*i, l, mid);
    ll v2 = lzRangeQuery(x, y, 2*i+1, mid+1, r);
    return v1 + v2;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    cin >> n >> q;
    for(int i = 1; i <= n; ++i) {
        cin >> x[i];
        lzRangeUpdate(i, i, x[i]);
    }
    while(q--) {
        int type, a, b, c;
        cin >> type;
        if(type==1) {
            cin >> a >> b >> c;
            lzRangeUpdate(a, b, c);
        } else {
            cin >> a;
            cout << lzRangeQuery(a, a) << "\n";
        }
    }
}