#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
Binary Index Tree with Difference Array Concept
*/
// int n, q;
// const int maxN = 2e5;
// // int x[maxN+1];
// ll tree[maxN+2];

// void add(int idx, int delta) {
//     // add delta to x[idx]
//     while(idx <= n) {
//         tree[idx] += delta;
//         idx += idx & -idx;
//     }
// }

// ll sum(int idx) {
//     // return sum of range [1, idx] in x
//     ll s = 0;
//     while(idx >= 1) {
//         s += tree[idx];
//         idx -= idx & -idx;
//     }
//     return s;
// }

// int main() {
//     ios::sync_with_stdio(0); 
//     cin.tie(0);

//     cin >> n >> q;
//     for(int i = 1, x; i <= n; ++i) {
//         cin >> x;
//         add(i, x);
//         add(i+1, -x);
//     }
//     while(q--) {
//         int qt;
//         cin >> qt;
//         if(qt==1) {
//             int a, b, u; // increase [a, b] by u
//             cin >> a >> b >> u;
//             add(a, u);
//             add(b+1, -u);
//         } else {
//             int k; // what is the value in position k;
//             cin >> k;
//             cout << sum(k) << "\n";
//         }
//     }
// }


/*
Segment Tree with Lazy Update
*/
int n, q;
const int maxN = 2e5;

struct node {
    ll s, lz;
};
node tree[1<<19];

void apply(int i, ll delta, int l, int r) {
    // update value and lazy
    tree[i].s += delta*(r-l+1);
    tree[i].lz += delta;
}

void push(int i, int l, int mid, int r) {
    // propagate from parent to children
    apply(2*i, tree[i].lz, l, mid);
    apply(2*i+1, tree[i].lz, mid+1, r);
    tree[i].lz = 0;
}


void update(int x, int y, ll delta, int i = 1, int l = 1, int r = n) {
    if(x > r || y < l) { // [x, y] completely not overlap with [l, r]
        return;
    }
    if(x <= l && y >= r) { // [x, y] completely cover [l, r]
        // Update value and lazy
        apply(i, delta, l, r);
        return;
    }
    // [x, y] partially overlap with [l, r]
    int mid = l + (r-l)/2;
    push(i, l, mid, r); // Propagate
    update(x, y, delta, 2*i, l, mid);
    update(x, y, delta, 2*i+1, mid+1, r); 
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

    cin >> n >> q;
    for(int i = 1, a; i <= n; ++i) {
        cin >> a;
        update(i, i, a);
    }
    while(q--) {
        int type, a, b, c;
        cin >> type;
        if(type==1) {
            cin >> a >> b >> c;
            update(a, b, c);
        } else {
            cin >> a;
            cout << query(a, a) << "\n";
        }
    }
}