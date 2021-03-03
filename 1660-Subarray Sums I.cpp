#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
Sliding Window
*/

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    vector<ll> arr(n);
    for(int i = 0; i < n; ++i) cin >> arr[i];

    ll l = 0, total = 0, ans = 0;
    for(int r = 0; r < n; ++r) {
        total += arr[r];
        while(total > x) {
            total -= arr[l];
            l++;
        }
        if(total == x) ans++;
    }
    cout << ans;
}