#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
Very similar to 1164 Room Allocation
*/

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<pi> arr(n); // {(end, start)}
    for(int i = 0; i < n; ++i) cin >> arr[i].second >> arr[i].first;
    sort(arr.begin(), arr.end());

    set<pi> s; // {(end time, index)}
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        auto [end, start] = arr[i];
        auto iter = s.upper_bound(make_pair(start, i)); // Find the max end time that smaller than start
        if(iter != s.begin()) {
            iter--;
            s.erase(iter);
            s.insert(make_pair(end, i));
            ans++;
        } else if(s.size() < k) {
            s.insert(make_pair(end, i));
            ans++;
        }
    }
    cout << ans;
}