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


// Prefix-Sum
// https://www.geeksforgeeks.org/maximum-subarray-sum-using-prefix-sum/
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int n;
    cin >> n;

    ll prefix = 0;
    ll prevMin = 0;
    ll ans = -1e18;
    for(int i = 0, a; i < n; ++i) {
        cin >> a;
        prefix += a;
        ans = max(ans, prefix - prevMin);
        prevMin = min(prevMin, prefix);
    }
    cout << ans;
}