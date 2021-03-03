#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

// Binary Search

bool g(vector<ll> &arr, ll m, ll target) {
    ll total = 0;
    for(ll x : arr) {
        total += m/x;
        if(total >= target) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    ll n, t;
    cin >> n >> t;
    vector<ll> arr(n);
    for(int i = 0; i < n; ++i) cin >> arr[i];

    ll l = 1, r = 1e18+1;
    while(l < r) {
        ll m = l + (r-l)/2;
        if(g(arr, m, t)) r = m;
        else l = m + 1;
    }
    cout << l;
}