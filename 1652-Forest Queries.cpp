#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
2D prefix sum

dp[i][j]: Number of trees inside (0, 0) to (i, j) 
dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + grid[i][j]
dp[0][0] = 0

(x1, y1), (x2, y2) => dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2] + dp[x1-1][y1-1]
*/

int n, q;
const int maxN = 1000;
string grid[maxN];
int dp[maxN+1][maxN+1];

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    cin >> n >> q;
    for(int i = 0; i < n; ++i) {
        cin >> grid[i];
        for(int j = 0; j < n; ++j) {
            if(grid[i][j]=='*') {
                dp[i+1][j+1] = 1;
            }
        }
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + dp[i][j];
        }
    } 

    while(q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2] + dp[x1-1][y1-1] << "\n";   
    }
}
