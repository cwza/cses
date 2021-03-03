#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

void helper(int n, int start, int end, int tmp, vector<pi> &ans) {
    if(n==1) {
        ans.push_back(make_pair(start, end));
        return;
    }
    helper(n-1, start, tmp, end, ans);
    ans.push_back(make_pair(start, end));
    helper(n-1, tmp, end, start, ans);
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    int n;
    cin >> n;

    vector<pi> ans;
    helper(n, 1, 3, 2, ans);
    cout << ans.size() << "\n";
    for(auto [from, to] : ans) cout << from << " " << to << "\n";
}