#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
C++ pb_ds ordered_set
tree structure automatically maintain the index
We can get index by value, and get value by index at O(logn)
*/

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int n;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    cin >> n;
    oset<array<int, 2>> s; // [(idx, val)]
    for(int i = 0, x; i < n; ++i) {
        cin >> x;
        s.insert({i, x});
    }

    while(n--) {
        int x;
        cin >> x; x--;
        auto iter = s.find_by_order(x);
        cout << (*iter)[1] << " ";
        s.erase(iter);
    }
}