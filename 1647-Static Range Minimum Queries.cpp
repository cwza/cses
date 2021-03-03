#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
Segment Tree
*/

int n, q;
const int maxN = 2e5;
int x[maxN+1];

struct node {
    ll mn;
};
node tree[1<<19];

void buildTree(int i = 1, int l = 1, int r = n) {
    if(l == r) {
        tree[i].mn = {x[l]};
        return;
    }
    int mid = l + (r-l)/2;
    buildTree(2*i, l, mid);
    buildTree(2*i+1, mid+1, r);
    tree[i].mn = min(tree[2*i].mn, tree[2*i+1].mn); // change
}

void update(int idx, int val, int i = 1, int l = 1, int r = n) {
    if(l == r) {
        x[idx] = val;
        tree[i].mn = val;
        return;
    }
    int mid = l + (r-l)/2;
    if(idx>=l && idx <= mid) {
        update(idx, val, 2*i, l, mid);
    } else {
        update(idx, val, 2*i+1, mid+1, r);
    }
    tree[i].mn = min(tree[2*i].mn, tree[2*i+1].mn); // change
}

ll query(int x, int y, int i = 1, int l = 1, int r = n) {
    if(x > r || y < l) { // [x, y] completely not overlap with [l, r]
        return 1e18; // change
    }
    if(x <= l && y >= r) { // [x, y] completely cover [l, r]
        return tree[i].mn;
    }
    int mid = l + (r-l)/2;
    ll v1 = query(x, y, 2*i, l, mid);
    ll v2 = query(x, y, 2*i+1, mid+1, r);
    return min(v1, v2); // change
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    cin >> n >> q;
    for(int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    buildTree();
    while(q--) {
        int x, y;
        cin >> x >> y;
        cout << query(x, y) << "\n";
    }

}