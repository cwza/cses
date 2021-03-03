#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    map<int, int> s; // {value: index}
    for(int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        int target = x - val;
        if(s.count(target)) {
            cout << s[target]+1 << " " << i+1;
            return 0;
        }
        s[val] = i;
    }
    cout << "IMPOSSIBLE";
}