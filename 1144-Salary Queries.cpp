#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int n, q;
const int maxN = 2e5;
int x[maxN];

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    cin >> n >> q;
    oset<array<int, 2>> s;
    for(int i = 0; i < n; ++i) {
        cin >> x[i];
        s.insert({x[i], i});
    }

    while(q--) {
        char t;
        cin >> t;
        if(t=='!') {
            int k, v;
            cin >> k >> v; k--;
            s.erase({x[k], k});
            x[k] = v;
            s.insert({v, k});
        } else {
            int a, b;
            cin >> a >> b;
            cout << s.order_of_key({b+1}) - s.order_of_key({a}) << "\n";
        }
    }
}