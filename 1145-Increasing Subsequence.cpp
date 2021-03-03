#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;


int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> s;
    for(int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        auto iter = lower_bound(s.begin(), s.end(), a);
        if(iter==s.end()) {
            s.push_back(a);
        } else {
            *iter = a;
        }
    }
    cout << s.size();
}