#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
sum(i, j): arr[i]+arr[i+1]+...+arr[j]

dp[i][j] = max( arr[i] + (sum(i+1, j) - dp[i+1][j]), arr[j] + (sum(i, j-1) - dp[i][j-1]) )
dp[i][j] = arr[i], if i == j
*/
const int maxN = 5000;
ll dp[maxN+1][maxN+1], prefix[maxN+1];
int n;
int arr[maxN+1];

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> arr[i];
        prefix[i] = prefix[i-1] + arr[i];
    }

    for(int l = 1; l <= n; ++l) {
        for(int i = 1; i <= n-l+1; ++i) {
            int j = i + l - 1;
            if(i==j) dp[i][j] = arr[i];
            else {
                ll l = arr[i] + ( (prefix[j]-prefix[i])-dp[i+1][j] );
                ll r = arr[j] + ( prefix[j-1]-prefix[i-1]-dp[i][j-1] );
                dp[i][j] = max(l, r);
            }
        }
    }
    cout << dp[1][n];
}

