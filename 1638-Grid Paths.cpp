#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

const int mxN = 1000, mod = 1e9+7;
string grid[mxN];
int dp[mxN][mxN] = {0};

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> grid[i];

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(grid[i][j]=='*') continue;
            else if(i==0 && j==0) dp[i][j] = 1;
            else if(i==0) dp[i][j] = (dp[i][j] + dp[i][j-1]) % mod;
            else if(j==0) dp[i][j] = (dp[i][j] + dp[i-1][j]) % mod;
            else dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
        }
    }
    cout << dp[n-1][n-1];
}