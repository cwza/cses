#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
0/1 knapsack problem to produce target = n*(n+1)/4
*/

const ll maxN = 500, maxX = 501*500/4, M = 1e9+7;
ll dp[maxX+1];
ll n;


long long modInv(long long b, long long M){
    // return inv(b) % M
    long long ex = M-2;
    if (b==1) return 1;
    long long r = 1;
    while (ex) {
        if (ex&1)r=(r * b)%M;
        ex = ex >> 1;
        b = (b * b)%M;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    cin >> n;
    ll s = (n+1)*n/2;
    if(s%2) {
        cout << 0;
        return 0;
    }

    ll m = s / 2;
    for(ll i = 0; i <= n; ++i) { 
        for(ll x = m; x >= 0; --x) {
            if(x==0) dp[x] = 1;
            else if(x-i>=0) dp[x] = (dp[x] + dp[x-i]) % M;
            else dp[x] = dp[x] % M;
        }
    }
    // The answer is dp[m] / 2, because two group can change
    // We need dp[m]/2 % M, We need modulo inverse...
    cout << (dp[m] * modInv(2, M)) % M ;
}