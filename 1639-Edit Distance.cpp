#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
dp[i][j] = dp[i-1][j-1], if s1[i] == s2[j]
dp[i][j] = 1 + min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]), otherwise

dp[i][0] = i
dp[0][j] = j
*/
const int maxN = 5000, maxM = 5000;
ll dp[maxN+1][maxM+1];
string s1, s2;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    // s1.insert(s1.begin(), '0'); s2.insert(s2.begin(), '0');

    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= m; ++j) {
            if(i==0) dp[i][j] = j;
            else if(j==0) dp[i][j] = i;
            else if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1 + min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
        }
    }
    cout << dp[n][m];
}