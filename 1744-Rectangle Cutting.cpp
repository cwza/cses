#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
                               Horizontally Cut                            Vertically Cut
dp[i][j] = min ( min(dp[k][j]+dp[i-k][j]+1 for k = [1, i-1]), min(dp[i][k]+dp[i][j-k]+1 for k = [1, j-1]) )
dp[i][j] = 0, if i==j
ans = dp[a][b]
*/

const int maxA = 500, maxB = 500;
int dp[maxA+1][maxB+1];
int a, b;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    cin >> a >> b;

    for(int i = 1; i <= a; ++i) {
        for(int j = 1; j <= b; ++j) {
            if(i==j) dp[i][j] = 0;
            else {
                dp[i][j] = 1e6;
                // Horizontally Cut
                for(int k = 1; k < i; ++k) dp[i][j] = min(dp[i][j], dp[k][j]+dp[i-k][j]+1);
                // Vertically Cut
                for(int k = 1; k < j; ++k) dp[i][j] = min(dp[i][j], dp[i][k]+dp[i][j-k]+1);
            }
        }
    }
    cout << dp[a][b];
}