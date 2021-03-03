#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
https://www.youtube.com/watch?v=d1H5JylYG4I

Transition:
dp[i][x] = 0, if arr[i]!=0 and arr[i]!=x
dp[i][x] = dp[i-1][x-1] + dp[i-1][x] + dp[i-1][x], otherwise

Initialization:
dp[1][x] = 0, if arr[i]!=0 and arr[i]!=x
dp[1][x] = 1, otherwise 

Ans:
sum(dp[n][x], x=[1, m])
*/

const int maxN = 1e5, maxM = 100, mod = 1e9+7;
int arr[maxN];
int dp[maxN+1][maxM+1];

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> arr[i];

    for(int i = 1; i <= n; ++i) {
        for(int x = 1; x <= m; ++x) {
            if(i==1) {
                if(arr[i]!=0 && arr[i]!= x) dp[i][x] = 0;
                else dp[i][x] = 1;
            }
            else if(arr[i]!=0 && arr[i]!= x) dp[i][x] = 0;
            else {
                if(x-1>=1) dp[i][x] = (dp[i][x] + dp[i-1][x-1]) % mod; 
                dp[i][x] = (dp[i][x] + dp[i-1][x]) % mod; 
                if(x+1<=m) dp[i][x] = (dp[i][x] + dp[i-1][x+1]) % mod; 
            }
        }
    }
    int ans = 0;
    for(int x = 1; x <= m; ++x ) ans = (ans + dp[n][x]) % mod;
    cout << ans;
}