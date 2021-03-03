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
//     multiset<int> s;
//     int ans = 0;
//     while(n--) {
//         int a;
//         cin >> a;
//         auto iter = s.upper_bound(a);
//         if(iter==s.end()) { // not found
//             ans++;
//         } else { // found
//             s.erase(iter);
//         }
//         s.insert(a);
//     }
//     cout << ans;
// }

/////////////   Exactly the patience sort problem but the condition is not greater than and equal is only greater than   ///////////////
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int n;
    cin >> n;

    vi dp;
    while(n--) {
        int a;
        cin >> a;
        auto iter = upper_bound(dp.begin(), dp.end(), a);
        if(iter==dp.end()) {
            dp.push_back(a);
        } else {
            *iter = a;
        }
    }
    cout << dp.size();
}