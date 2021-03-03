#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
dp[0] = 0
dp[i] = min(dp[i-coin] for coin in coins)
*/

int M = 1e6+1;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    vi coins(n);
    for(int i = 0; i < n; ++i) cin >> coins[i];

    vi dp(x+1, M); dp[0] = 0;
    for(int i = 1; i <= x; ++i) {
        for(int coin : coins) {
            if(i-coin >= 0) dp[i] = min(dp[i], dp[i-coin]);
        }
        dp[i]++;
    }
    if(dp[x] == M+1) cout << -1;
    else cout << dp[x];
}