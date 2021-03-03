#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
dp[i][x] = dp[i-1][x] or dp[i-1][x-coins[i]]
dp[0][0] = 1
dp[i][0] = 1
dp[0][x] = 0
*/

// 2-D Space
// const int maxN = 100, maxS = 100*1000;
// int arr[maxN+1], dp[maxN+1][maxS+1];
// int n;

// int main() {
//     ios::sync_with_stdio(0); 
//     cin.tie(0);

//     cin >> n;
//     int m = 0;
//     for(int i = 1; i <= n; ++i) {
//         cin >> arr[i];
//         m += arr[i];
//     }

//     for(int i = 0; i <= n; ++i) {
//         for(int x = 0; x <= m; ++x) {
//             if(x==0) dp[i][x] = 1;
//             else if(i==0) dp[i][x] = 0;
//             else if(x-arr[i]>=0) dp[i][x] = dp[i-1][x] || dp[i-1][x-arr[i]];
//             else dp[i][x] = dp[i-1][x];
//         }
//     }
//     vi ans;
//     for(int x = 1; x <= m; ++x) {
//         if(dp[n][x]==1) ans.push_back(x);
//     }
//     cout << ans.size() << "\n";
//     for(auto num : ans) cout << num << " ";
// }

// 1-D Space
const int maxN = 100, maxS = 100*1000;
int arr[maxN+1], dp[maxS+1];
int n;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    cin >> n;
    int m = 0;
    for(int i = 1; i <= n; ++i) {
        cin >> arr[i];
        m += arr[i];
    }

    for(int i = 0; i <= n; ++i) {
        for(int x = m; x >= 0; --x) {
            if(x==0) dp[x] = 1;
            else if(x-arr[i]>=0) dp[x] = dp[x] || dp[x-arr[i]];
            else dp[x] = dp[x];
        }
    }
    vi ans;
    for(int x = 1; x <= m; ++x) {
        if(dp[x]==1) ans.push_back(x);
    }
    cout << ans.size() << "\n";
    for(auto num : ans) cout << num << " ";   
}