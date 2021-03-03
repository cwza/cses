#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
Competitive Programmer's Handbook
Ch16.3 Successor paths
dp:
          0 1 2 3 4 5 6 7 8 9 
succ(x,1)   3 5 7 6 2 2 1 6 3 
succ(x,2)   7 2 1 2 5 5 3 2 7 
succ(x,4)   3 2 7 2 5 5 1 2 3 
succ(x,8)   7 2 1 2 5 5 3 2 7

Sample Test Case
9 1
3 5 7 6 2 2 1 6 3
4 11
ans: 5
*/

int n, q;
const int maxN = 2e5;
int dp[31][maxN+1];

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    cin >> n >> q;
    for(int j = 1; j <= n; ++j) {
        cin >> dp[0][j];
    }

    for(int i = 1; i < 31; ++i) {
        for(int j = 1; j <= n; ++j) {
            dp[i][j] = dp[i-1][dp[i-1][j]];
        }
    }

    while(q--) {
        int x, k;
        cin >> x >> k;
        for(int i = 0; i < 31; ++i) {
            if((k>>i)&1) {
                x = dp[i][x];
            }
        }
        cout << x << "\n";
    }
}