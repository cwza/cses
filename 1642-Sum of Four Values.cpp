#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
This method only work if we only want one of the answer not all of them.
Use a HashMap to store {sum: (k, l)} for all index pair (k, l) => O(n^2)
Try all i, j pair and try to find is there any x-arr[i]-arr[j] in the HashMap
*/

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    if(n < 4) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    vi arr(n);
    for(int i = 0; i < n; ++i) cin >> arr[i];

    unordered_map<int, pi> table; // {sum: (idx3, idx4)}
    table.reserve(1<<20);
    for(int i = 0; i <= n-2; ++i) {
        int num1 = arr[i];
        for(int j = i+1; j < n; ++j) {
            int num2 = arr[j];
            int sum = x - num1 - num2;
            if(sum <= 0) continue;
            if(table.count(sum)) {
                auto [k, l] = table[sum];
                if(k == i || k == j || l == i || l == j) continue;
                cout << i+1 << " " << j+1 << " " << k+1 << " " << l+1;
                return 0;
            }
            table[num1+num2] = make_pair(i, j);
        }
    }
    cout << "IMPOSSIBLE";
}