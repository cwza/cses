#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
 a       b
---- ----------
      c
---------------

c: current prefix sum, a: previous prefix sum
We want to find a to let b = target.
    b = target
c - a = target
a = c - target
==> Find a = c-target
*/

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    map<ll, int> counter; // {prefix_sum: freq}
    ll curSum = 0, ans = 0;
    for(int i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        curSum += a;
        if(curSum == x) ans++;
        ans += counter[curSum-x];
        counter[curSum]++;
    }
    cout << ans;
}