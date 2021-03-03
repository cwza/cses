#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
dp[0] = 1
dp[i] = dp[i-1] +...+ dp[i-6]
*/

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> dp(n+1); dp[0] = 1;

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= 6; ++j) {
            if(i-j >= 0) dp[i] += dp[i-j] % (ll)(1e9+7);
        }
        dp[i] = dp[i] % (ll)(1e9+7);
    }
    cout << dp[n];
}