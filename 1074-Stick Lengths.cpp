#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

// int main() {
//     ios::sync_with_stdio(0); 
//     cin.tie(0);

//     int n;
//     cin >> n;
//     double arr[n];
//     for(int i = 0; i < n; ++i) cin >> arr[i];
//     sort(arr, arr+n);

//     double mid;
//     if(n&1) mid = arr[n/2];
//     else mid = (arr[n/2-1] + arr[n/2])/2;

//     double ans = 0;
//     for(int i = 0; i < n; ++i) {
//         ans += abs(arr[i]-mid);
//     }
//     cout << (ll)ans;
// }
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int n;
    cin >> n;
    double arr[n];
    for(int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr, arr+n);

    ll mid = arr[n/2];
    ll ans = 0;
    for(int i = 0; i < n; ++i) {
        ans += abs(arr[i]-mid);
    }
    cout << ans;
}