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
We want to find a to let b % n = 0.
             b % n = 0
         (c-a) % n = 0
 ((c%n)-(a%n)) % n = 0
 Define cx = c%n, ax = a%n
     (cx - ax) % n = 0
=> Find ax = cx
*/

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int n;
    cin >> n;
    map<ll, int> counter; // {prefix_sum%n: freq}
    ll curSum = 0, ans = 0;
    for(int i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        curSum = (curSum + a%n + n) % n; // +n to handle curSum may be negative
        if(curSum==0) ans++;
        ans += counter[curSum];
        counter[curSum]++;
    }
    cout << ans;
}