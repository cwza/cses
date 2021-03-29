#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, q;

struct node {
    ll s, lz;
    bool mark;
};
node tree[1<<19];

void apply(int i, ll val, bool mark, int l, int r) {
    // update value and lazy
    if(mark) {
        tree[i].s = val*(r-l+1);
        tree[i].lz = val;
        tree[i].mark = true;
    } else {
        tree[i].s += val*(r-l+1);
        tree[i].lz += val;
    }
}

void push(int i, int l, int mid, int r) {
    // propagate from parent to children
    apply(2*i, tree[i].lz, tree[i].mark, l, mid);
    apply(2*i+1, tree[i].lz, tree[i].mark, mid+1, r);
    tree[i].lz = 0;
    tree[i].mark = false;
}


void update(int x, int y, ll val, bool mark, int i = 1, int l = 1, int r = n) {
    if(x > r || y < l) { // [x, y] completely not overlap with [l, r]
        return;
    }
    if(x <= l && y >= r) { // [x, y] completely cover [l, r]
        // Update value and lazy
        apply(i, val, mark, l, r);
        return;
    }
    // [x, y] partially overlap with [l, r]
    int mid = l + (r-l)/2;
    push(i, l, mid, r); // Propagate
    update(x, y, val, mark, 2*i, l, mid);
    update(x, y, val, mark, 2*i+1, mid+1, r); 
    tree[i].s = tree[2*i].s + tree[2*i+1].s;
}

ll query(int x, int y, int i = 1, int l = 1, int r = n) {
    if(x > r || y < l) { // [x, y] completely not overlap with [l, r]
        return 0;
    }
    if(x <= l && y >= r) { // [x, y] completely cover [l, r]
        return tree[i].s;
    }
    // [x, y] partially overlap with [l, r]
    int mid = l + (r-l)/2;
    push(i, l, mid, r); // Propagate
    ll v1 = query(x, y, 2*i, l, mid);
    ll v2 = query(x, y, 2*i+1, mid+1, r);
    return v1 + v2;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);

    cin >> n >> q;
    for(int i = 1, a; i <= n; ++i) {
        cin >> a;
        update(i, i, a, false);
    }
    while(q--) {
        int qt;
        cin >> qt;
        if(qt==1) {
            int a, b, x;
            cin >> a >> b >> x;
            update(a, b, x, false);
        } else if(qt==2) {
            int a, b, x;
            cin >> a >> b >> x;
            update(a, b, x, true);
        } else {
            int a, b;
            cin >> a >> b;
            cout << query(a, b) << "\n";
        }
    }
}