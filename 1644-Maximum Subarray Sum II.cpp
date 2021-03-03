#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
Prefix-Sum + Sliding Window
Please refer to 1643 Maximum Subarray Sum using Prefix-Sum
and https://www.geeksforgeeks.org/maximum-sum-subarray-of-size-range-l-r/
*/

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int n, a, b;
    cin >> n >> a >> b;
    vector<ll> prefix(n+1, 0);
    for(int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        prefix[i] = prefix[i-1] + a;
    }

    set<array<ll, 2>> s; // {[prefix_sum, idx]}
    s.insert({0, 0});
    ll ans = -2e18;
    for(int j = a; j <= n; ++j) {
        ans = max(ans, prefix[j]-(*s.begin())[0]);
        if(j>=b) s.erase({prefix[j-b], j-b});
        s.insert({prefix[j-a+1], j-a+1});
    }
    cout << ans;
}