#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
Binary Index Tree
*/
int n, q;
const int maxN = 2e5;
int x[maxN+1];
ll tree[maxN+1];

void add(int idx, int delta) {
    // add delta to x[idx]
    while(idx <= n) {
        tree[idx] += delta;
        idx += idx & -idx;
    }
}

ll sum(int idx) {
    // return sum of range [1, idx] in x
    ll s = 0;
    while(idx >= 1) {
        s += tree[idx];
        idx -= idx & -idx;
    }
    return s;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    cin >> n >> q;
    for(int i = 1; i <= n; ++i) {
        cin >> x[i];
        add(i, x[i]);
    }
    while(q--) {
        int type, a, b;
        cin >> type >> a >> b;
        if(type == 1) {
            add(a, b - x[a]);
            x[a] = b;
        } else {
            cout << sum(b) - sum(a-1) << "\n";
        }
    }
}


/*
Segment Tree
*/
// int n, q;
// const int maxN = 2e5;
// int x[maxN+1];

// struct node {
//     ll s;
// };
// node tree[1<<19];

// void build(int i = 1, int l = 1, int r = n) {
//     if(l == r) {
//         tree[i].s = x[l];
//         return;
//     }
//     int mid = l + (r-l)/2;
//     build(2*i, l, mid);
//     build(2*i+1, mid+1, r);
//     tree[i].s = tree[2*i].s + tree[2*i+1].s; // change
// }

// void update(int idx, int val, int i = 1, int l = 1, int r = n) {
//     if(l == r) {
//         x[idx] = val;
//         tree[i].s = val;
//         return;
//     }
//     int mid = l + (r-l)/2;
//     if(idx >= l && idx <= mid) {
//         update(idx, val, 2*i, l, mid);
//     } else {
//         update(idx, val, 2*i+1, mid+1, r);
//     }
//     tree[i].s = tree[2*i].s + tree[2*i+1].s; // change
// }

// ll query(int x, int y, int i = 1, int l = 1, int r = n) {
//     if(x > r || y < l) { // [x, y] completely not overlap with [l, r]
//         return 0; // change
//     }
//     if(x <= l && y >= r) { // [x, y] completely cover [l, r]
//         return tree[i].s;
//     }
//     int mid = l + (r-l)/2;
//     ll v1 = query(x, y, 2*i, l, mid);
//     ll v2 = query(x, y, 2*i+1, mid+1, r);
//     return v1 + v2; // change
// }

// int main() {
//     ios::sync_with_stdio(0); 
//     cin.tie(0);

//     cin >> n >> q;
//     for(int i = 1; i <= n; ++i) {
//         cin >> x[i];
//     }
//     build();
//     while(q--) {
//         int type, a, b;
//         cin >> type >> a >> b;
//         if(type == 1) {
//             update(a, b);
//         } else {
//             cout << query(a, b) << "\n";
//         }
//     }
// }