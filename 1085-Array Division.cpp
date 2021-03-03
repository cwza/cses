#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

// Binary Search

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for(int i = 0; i < n; ++i) cin >> arr[i];

    ll l = *max_element(arr.begin(), arr.end());
    ll r = accumulate(arr.begin(), arr.end(), (ll)0);
    while(l < r) {
        ll m = l + (r-l)/2;
        ll numDiv = 1, curSum = 0;
        for(int i = 0; i < arr.size(); ++i) {
            curSum += arr[i];
            if(curSum > m) {
                numDiv++;
                curSum = arr[i];
            }
        }
        if(numDiv <= k) r = m;
        else l = m + 1;
    }
    cout << l;
}