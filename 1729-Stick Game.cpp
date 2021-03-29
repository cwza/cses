#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
const int maxN = 1e6;
bool dp[maxN+1];

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    cin >> n >> k;
    int ks[k];
    for(int i = 0; i < k; ++i) cin >> ks[i];

    for(int i = 1; i <= n; ++i) {
        // for(int j = 0; j < k && !dp[i]; ++j) {
        //     if(i-ks[j]<0) continue;
        //     if(!dp[i-ks[j]]) {
        //         dp[i] = true;
        //     }
        // }
        for(int j = 0; j < k; ++j) {
            if(i-ks[j]<0) continue;
            dp[i] |= !dp[i-ks[j]];
        }
    }
    for(int i = 1; i <= n; ++i) {
        if(dp[i]) cout << 'W';
        else cout << 'L';
    }
}