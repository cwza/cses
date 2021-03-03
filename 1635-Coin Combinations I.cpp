#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
dp[0] = 1
dp[i] = sum(dp[i-coin] for coin in coins)
Very like 1634 Minimizing Coins
*/

const int mod = 1e9+7, mxN = 1e6;
int coins[mxN];
ll dp[mxN+1] = {0};

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    // vi coins(n);
    for(int i = 0; i < n; ++i) cin >> coins[i];

    // vector<ll> dp(x+1, 0); 
    dp[0] = 1;
    for(int i = 1; i <= x; ++i) {
        for(int j = 0; j < n; ++j) {
            if(i-coins[j] >= 0) dp[i] += dp[i-coins[j]] % mod;
        }
        dp[i] %= mod;
    }
    cout << dp[x];
}