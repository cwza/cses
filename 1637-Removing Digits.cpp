#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
dp[0] = 0
dp[i] = min(dp[i-j]+1 for j in digits of i)
*/

const int mxN = 1e6;
int dp[mxN+1] = {0};

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; ++i) {
        dp[i] = 1e9;
        int i2 = i;
        while(i2) {
            dp[i] = min(dp[i], dp[i-i2%10]+1);
            i2 /= 10;
        }
    }
    cout << dp[n];
}