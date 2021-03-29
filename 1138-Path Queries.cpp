#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
Tree Traversal Array + Binary Index Tree with Difference Array Concept
Idea from CPH
    1
   . .
  2   3
     . .
    4   5

    0  1  2  3  4  5 (original index)
st     1  2  3  4  5 (index in binary index tree)
et     5  2  5  4  5
x      4  2  5  2  1
*/

int n, q;
const int maxN = 2e5;
vector<int> adj[maxN+1];
int x[maxN+1], st[maxN+1], et[maxN+1];
int t = 1;
ll tree[maxN+2];

void dfs(int u, int p) {
    st[u] = t++;
    for(int v : adj[u]) {
        if(v == p) continue;
        dfs(v, u);
    }
    et[u] = t-1;
}

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
    }
    for(int i = 1, u, v; i <= n-1; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
    for(int i = 1; i <= n; ++i) {
        add(st[i], x[i]);
        add(et[i]+1, -x[i]);
    }
    while(q--) {
        int qt;
        cin >> qt;
        if(qt == 1) {
            int a, b;
            cin >> a >> b;
            add(st[a], b-x[a]);
            add(et[a]+1, -(b-x[a]));
            x[a] = b;
        } else {
            int a;
            cin >> a;
            cout << sum(st[a]) << "\n";
        }
    }
}