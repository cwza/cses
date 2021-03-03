#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

// 1-D dp, dp[i] = max(dp[i-1]+arr[i], arr[i])
// const int mxN = 2e5;
// ll arr[mxN], dp[mxN];

// int main() {
//     ios::sync_with_stdio(0); 
//     cin.tie(0);

//     int n;
//     cin >> n;
//     for(int i = 0; i < n; ++i) cin >> arr[i];

//     dp[0] = arr[0];
//     for(int i = 1; i < n; ++i) {
//         dp[i] = max(dp[i-1]+arr[i], arr[i]);
//     }
//     cout << *max_element(dp, dp+n);
// }

// Space O(1) of above
// int main() {
//     ios::sync_with_stdio(0); 
//     cin.tie(0);

//     int n;
//     cin >> n;

//     ll ans = -1e18, prev = -1e18;
//     for(int i = 0; i < n; ++i) {
//         ll a;
//         cin >> a;
//         prev = max(prev+a, a);
//         ans = max(ans, prev);
//     }
//     cout << ans;
// }

// Prefix-Sum
// https://www.geeksforgeeks.org/maximum-subarray-sum-using-prefix-sum/
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> prefix(n+1, 0);
    for(int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        prefix[i] = prefix[i-1] + a;
    }

    ll curMinPrefix = prefix[0];
    ll ans = -2e18;
    for(int j = 1; j <= n; ++j) {
        ans = max(ans, prefix[j]-curMinPrefix);
        curMinPrefix = min(curMinPrefix, prefix[j]);
    }
    cout << ans;
}