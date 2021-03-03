#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

void helper(string &path, int counter[26], int n, vector<string> &ans) {
    if(path.size()==n) {
        ans.push_back(path);
    }
    for(int i = 0; i < 26; ++i) {
        if(counter[i] > 0) {
            path.push_back(i+'a');
            counter[i]--;
            helper(path, counter, n, ans);
            path.pop_back();
            counter[i]++;
        }
    }
}

// int main() {
//     ios::sync_with_stdio(0); 
//     cin.tie(0);

//     string s;
//     cin >> s;

//     int counter[26] = {0};
//     for(char ch : s) counter[ch-'a'] += 1;

//     string path; vector<string> ans;
//     helper(path, counter, s.size(), ans);

//     cout << ans.size() << "\n";
//     for(string t : ans) cout << t << "\n";
// }
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    string s;
    cin >> s;

    sort(s.begin(), s.end());
    vector<string> ans;
    do {
        ans.push_back(s);
    } while(next_permutation(s.begin(), s.end()));
    cout << ans.size() << "\n";
    for(string t : ans) cout << t << "\n";
}