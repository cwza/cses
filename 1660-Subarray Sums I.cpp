#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
Exactly the same as 1661
*/

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    map<ll, int> counter; // {prefix_sum: freq}
    counter[0] = 1;
    ll curSum = 0, ans = 0;
    for(int i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        curSum += a;
        ans += counter[curSum-x];
        counter[curSum]++;
    }
    cout << ans;
}