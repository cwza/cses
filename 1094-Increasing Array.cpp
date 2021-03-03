#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    ll n, prev, cur;
    cin >> n;
    cin >> prev;
    ll ans = 0;
    for(int i = 1; i < n; i++) {
        cin >> cur;
        if(cur < prev) {
            ans += prev - cur;
        }
        prev = max(prev, cur);
    }
    cout << ans;
}