#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
Binary Search + Max Segment Tree
O(m*logn*logn)
*/
// int n, m;
// const int maxN = 2e5;
// int x[maxN+1];

// struct node {
//     ll mx;
// };
// node tree[1<<19];

// void update(int idx, int val, int i = 1, int l = 1, int r = n) {
//     if(l == r) {
//         tree[i].mx = val;
//         x[idx] = val;
//         return;
//     }
//     int mid = l + (r-l)/2;
//     if(idx >= l && idx <= mid) {
//         update(idx, val, 2*i, l, mid);
//     } else {
//         update(idx, val, 2*i+1, mid+1, r);
//     }
//     tree[i].mx = max(tree[2*i].mx, tree[2*i+1].mx);
// }

// ll query(int x, int y, int i = 1, int l = 1, int r = n) {
//     if(x > r || y < l) {
//         return 0;
//     }
//     if(x <= l && y >= r) {
//         return tree[i].mx;
//     }
//     int mid = l + (r-l)/2;
//     ll v1 = query(x, y, 2*i, l, mid);
//     ll v2 = query(x, y, 2*i+1, mid+1, r);
//     return max(v1, v2);
// }

// int main() {
//     ios::sync_with_stdio(0); 
//     cin.tie(0);

//     cin >> n >> m;
//     for(int i = 1; i <= n; ++i) {
//         cin >> x[i];
//         update(i, x[i]);
//     }

//     while(m--) {
//         int a;
//         cin >> a;

//         int l = 1, r = n+1;
//         while(l < r) {
//             int mid = l + (r-l)/2;
//             if(query(1, mid) >= a) r = mid;
//             else l = mid + 1;
//         }
//         if(l==n+1) cout << "0 ";
//         else {
//             cout << l << " ";
//             update(l, x[l] - a);
//         }
//     }
// }


/*
Binary Search "in" Max SegmentTree
O(mlogn)
*/
int n, m;
const int maxN = 2e5;
int x[maxN+1];

struct node {
    ll mx;
};
node tree[1<<19];

void update(int idx, int val, int i = 1, int l = 1, int r = n) {
    if(l == r) {
        tree[i].mx = val;
        x[idx] = val;
        return;
    }
    int mid = l + (r-l)/2;
    if(idx >= l && idx <= mid) {
        update(idx, val, 2*i, l, mid);
    } else {
        update(idx, val, 2*i+1, mid+1, r);
    }
    tree[i].mx = max(tree[2*i].mx, tree[2*i+1].mx);
}

int query(int x, int i = 1, int l = 1, int r = n) {
    if(l == r) {
        return l;
    }
    int mid = l + (r-l)/2;
    if(tree[2*i].mx >= x) {
        return query(x, 2*i, l, mid);
    } else {
        return query(x, 2*i+1, mid+1, r);
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        cin >> x[i];
        update(i, x[i]);
    }

    while(m--) {
        int a;
        cin >> a;

        if(a > tree[1].mx) {
            cout << "0 ";
        }
        else {
            int idx = query(a);
            cout << idx << " ";
            update(idx, x[idx]-a);
        }
    }
}