#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int n;
    cin >> n;
    ll weight[n], ans = 0;
    for(int i = 0; i < n; ++i) {
        cin >> weight[i];
        ans += weight[i];
    }

    for(int b = 0; b < 1<<n; ++b) {
        ll g1Sum = 0, g2Sum = 0;
        for(int i = 0; i < n; ++i) {
            if(b&(1<<i)) g1Sum += weight[i];
            else g2Sum += weight[i];
        }
        ans = min(ans, abs(g1Sum-g2Sum));
    }
    cout << ans;
}