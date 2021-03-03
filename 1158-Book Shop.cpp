#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
Standard 0/1 knapsack problem
dp[i][j] = max(dp[i-1][j], price[i]+dp[i-1][j-weight[i]])
dp[0][j] = 0
dp[i][0] = 0
*/

// 2-D Space
// const int mxN = 1000, mxW = 1e5;
// int weight[mxN+1], price[mxN+1];
// int dp[mxN+1][mxW+1];

// int main() {
//     ios::sync_with_stdio(0); 
//     cin.tie(0);

//     int n, W;
//     cin >> n >> W;

//     for(int i = 1; i <= n; ++i) cin >> weight[i];
//     for(int i = 1; i <= n; ++i) cin >> price[i];

//     for(int i = 0; i <= n; ++i) {
//         for(int j = 0; j <= W; ++j) {
//             if(i==0 || j==0) dp[i][j] = 0;
//             else if(j-weight[i] < 0) dp[i][j] = dp[i-1][j];
//             else dp[i][j] = max(dp[i-1][j], price[i]+dp[i-1][j-weight[i]]);
//         }
//     }
//     cout << dp[n][W];
// }

// 1-D Space
const int mxN = 1000, mxW = 1e5;
int weight[mxN+1], price[mxN+1];
int dp[mxW+1];

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int n, W;
    cin >> n >> W;
    for(int i = 1; i <= n; ++i) cin >> weight[i];
    for(int i = 1; i <= n; ++i) cin >> price[i];

    for(int i = 0; i <= n; ++i) {
        for(int j = W; j >= 0; --j) {
            if(j==0) dp[j] = 0;
            else if(j-weight[i] < 0) dp[j] = dp[j];
            else dp[j] = max(dp[j], price[i]+dp[j-weight[i]]);
        }
    }
    cout << dp[W];
}