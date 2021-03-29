#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// map<vector<int>, bool> dp;
// void dfs(vector<int> p) {
//     if(p==vector<int>(p.size(), 0)) dp[p] = false;
//     if(dp.find(p)!=dp.end()) return;
//     for(int i = 0; i < p.size(); ++i) {
//         for(int j = 1; j <= p[i]; ++j) {
//             vector<int> p2 = p;
//             p2[i] -= j;
//             if(i!=0) p2[i-1] += j;
//             dfs(p2);
//             dp[p] |= !dp[p2];
//         }
//     }
// }

// int main() {
//     int n;
//     cin >> n;
//     vector<int> p(n);
//     for(int i = 0; i < n; ++i) cin >> p[i];
//     dfs(p);
//     cout << dp[p];
// }


int t;
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            int a;
            cin >> a;
            if(i%2==0) ans ^= a;
        }
        if(ans==0) cout << "second\n";
        else cout << "first\n";
    }
}