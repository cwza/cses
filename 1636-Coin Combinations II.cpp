#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
Exactly same as 1635 Coin Combinations I, but just switch the order of the loops.
Because if you enforce that you can only take the coins in the certain order then the combinations will also be unique.
*/

const int mod = 1e9+7, mxN = 1e6;
int coins[mxN];
ll dp[mxN+1] = {0};

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    for(int i = 0; i < n; ++i) cin >> coins[i];

    dp[0] = 1;
    for(int j = 0; j < n; ++j) {
        for(int i = 1; i <= x; ++i) {
            if(i-coins[j] >= 0) dp[i] = (dp[i] + dp[i-coins[j]]) % mod;
        }
        // dp[j] %= mod;
    }
    cout << dp[x];
}