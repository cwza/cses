#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

// Sliding Window

const int mxn = 2e5;
int arr[mxn];

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> arr[i];

    int l = 0, ans = 0;
    set<int> s;
    for(int r = 0; r < n; ++r) {
        while(s.count(arr[r])) {
            s.erase(arr[l]);
            l++;
        }
        s.insert(arr[r]);
        ans = max(ans, r-l+1);
    }
    cout << ans;
}