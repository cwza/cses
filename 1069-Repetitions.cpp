#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    string s;
    cin >> s;
    int l = 0;
    int ans = 0;
    for(int r = 1; r <= s.size(); r++) {
        if(s[r] != s[r-1]) {
            ans = max(ans, r-l);
            l = r;
        }
    }
    cout << ans;
}