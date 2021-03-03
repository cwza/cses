#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

////////////  Sort + Self check duplicate by one loop  ///////////////
// int main() {
//     ios::sync_with_stdio(0); 
//     cin.tie(0);

//     int n;
//     cin >> n;

//     int nums[n];
//     for(int i = 0; i < n; ++i) cin >> nums[i];
//     sort(nums, nums+n);
//     int ans = 0, prev = 0;
//     for(int i = 0; i < n; ++i) {
//         if(nums[i] == prev) {
//             prev = nums[i];
//             continue;
//         }
//         ans++;
//         prev = nums[i];
//     }
//     cout << ans;
// }

////////////////  Use Set   ///////////////
// int main() {
//     ios::sync_with_stdio(0); 
//     cin.tie(0);

//     int n;
//     cin >> n;
//     set<int> s; // unordered_set will get TLE!!!
//     while(n--) {
//         int num;
//         cin >> num;
//         s.insert(num);
//     }
//     cout << s.size();
// }

///////////////////  Sort + unique  ///////////////
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int n;
    cin >> n;
    int nums[n];
    for(int i = 0; i < n; ++i) cin >> nums[i];
    sort(nums, nums+n);
    auto iter = unique(nums, nums+n);
    cout << iter - nums;
}