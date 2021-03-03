#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
Greedyly choose the smallest duration first,
The optimal solution is independent of deadline!!!
*/

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<ll, ll>> arr(n); // [(duration, deadline)]
    for(int i = 0; i < n; ++i) cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end());

    ll cur = 0, ans = 0;
    for(auto [duration, deadline] : arr) {
        cur += duration;
        ans += deadline - cur;
    }
    cout << ans;
}