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

    ll ans = 1;
    while(n--) {
        ans = (ans * 2) % (int)(1e9+7);
    }
    cout << ans % (int)(1e9+7);
}