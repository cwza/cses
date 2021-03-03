#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
always select the next possible event that ends as early as possible
*/

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int n;
    cin >> n;
    vector<pi> arr(n);
    for(int i = 0; i < n; ++i) cin >> arr[i].second >> arr[i].first;
    sort(arr.begin(), arr.end());

    int ans = 1;
    int prevEnd = arr[0].first;
    for(int i = 1; i < n; ++i) {
        auto [b, a] = arr[i];
        if(a >= prevEnd) {
            ans++;
            prevEnd = b;
        }
    }
    cout << ans;
}