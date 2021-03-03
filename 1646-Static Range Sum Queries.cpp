#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
Prefix-Sum
*/

int n, q;
const int maxN = 2e5;
ll dp[maxN+1];

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    cin >> n >> q;
    for(int i = 1, x; i <= n; ++i) {
        cin >> x;
        dp[i] = dp[i-1] + x;
    }

    for(int i = 0, a, b; i < q; ++i) {
        cin >> a >> b;
        cout << dp[b] - dp[a-1] << "\n";
    }
}