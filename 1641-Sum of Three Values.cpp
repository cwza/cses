#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;


// ////////////////////   Use HashMap will TLE   ////////////////////////
// pi twoSum(vi &arr, int start, int end, int sum) {
//     map<int, int> s; // val, index
//     for(int i = start; i < end; ++i) {
//         int num2 = arr[i];
//         int target = sum - num2;
//         if(s.count(target)) return make_pair(i, s[target]);
//         s[num2] = i;
//     }
//     return make_pair(-1, -1);
// }

// int main() {
//     ios::sync_with_stdio(0); 
//     cin.tie(0);

//     int n, x;
//     cin >> n >> x;
//     if(n < 3) {
//         cout << "IMPOSSIBLE";
//         return 0;
//     }
//     vi arr(n);
//     for(int i = 0; i < n; ++i) cin >> arr[i];

//     for(int i = 0; i <= n-3; ++i) {
//         int num1 = arr[i];
//         int sum = x - num1;
//         if(sum <= 0) continue;
//         auto [j, k] = twoSum(arr, i+1, n, sum);
//         if(j==-1) continue;
//         cout << i+1 << " " << j+1 << " " << k+1;
//         return 0;
//     }
//     cout << "IMPOSSIBLE";
// }

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    if(n < 3) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    vector<pi> arr(n); // value, idx
    for(int i = 0; i < n; ++i) {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr.begin(), arr.end());

    for(int i = 0; i <= n-3; ++i) {
        auto [num1, num1Idx] = arr[i];
        int sum = x - num1;
        if(sum <= 0) continue;

        int l = i+1, r = n-1;
        while(l < r) {
            auto [num2, num2Idx] = arr[l];
            auto [num3, num3Idx] = arr[r];
            if(num2+num3 == sum) {
                cout << num1Idx+1 << " " << num2Idx+1 << " " << num3Idx+1;
                return 0;
            }
            else if(num2+num3 > sum) r--;
            else l++;
        }
    }
    cout << "IMPOSSIBLE";
}