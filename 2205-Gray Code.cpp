#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;


/////////////  Solution1: (i>>1^i)  ///////////////
// int main() {
//     ios::sync_with_stdio(0); 
//     cin.tie(0);

//     int n;
//     cin >> n;

//     for(int i = 0; i < 1<<n; i++) {
//         // (i>>1^i) transform from binary to gray code, see wiki
//         cout << bitset<16>((i>>1)^i).to_string().substr(16-n, n) << "\n";
//     }
// }

////////////  Solution2: dfs  ////////////////
// void dfs(string &ans, unordered_set<string> &done) {
//     cout << ans << "\n";
//     done.insert(ans);
//     for(int i = ans.size()-1; i >= 0; --i) { // flip from right
//         ans[i] = ans[i]=='0' ? '1' : '0'; // flip
//         if(done.count(ans)) {
//             ans[i] = ans[i]=='0' ? '1' : '0';
//             continue;
//         }
//         dfs(ans, done);
//         ans[i] = ans[i]=='0' ? '1' : '0';
//     }
// }
// int main() {
//     ios::sync_with_stdio(0); 
//     cin.tie(0);

//     int n;
//     cin >> n;

//     string ans(n, '0');
//     unordered_set<string> done;
//     dfs(ans, done);
// }

/////////////  Solution3: Mirror   ////////////////
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int n;
    cin >> n;

    vector<string> ans;
    ans.push_back(string(n, '0'));

    cout << ans[0] << "\n";
    for(int i = n-1; i >= 0; --i) {
        int sz = ans.size();
        for(int j = sz-1; j >= 0; --j) {
            string tmp = string(ans[j]);
            tmp[i] = '1';
            ans.push_back(tmp);
            cout << tmp << "\n";
        }
    }
}