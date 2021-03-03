#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
Swiping Line:
Step 1- take input in a  vector which contain pair of int and bool and insert arrival time as true and leaving time as false.
Step 2- sort the vector.
stem 3- iterate over vector and when you found true update max if max > ans 
step 4- else if you strike false update ans as ans-1
*/

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int n;
    cin >> n;
    vector<pi> arr;
    for(int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        arr.push_back(make_pair(a, 1));
        arr.push_back(make_pair(b, -1));
    }
    sort(arr.begin(), arr.end());
    int cur = 0, ans = 0;
    for(auto [_, t] : arr) {
        cur += t;
        ans = max(ans, cur);
    }
    cout << ans;
}