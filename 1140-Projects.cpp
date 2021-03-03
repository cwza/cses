#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
https://www.youtube.com/watch?v=MJn3ogwsUbo&feature=youtu.be
0/1 Knapsack + Schedule
*/

const int maxN = 2e5;
array<int, 3> arr[maxN+1]; // (end, start, reward)
int n;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> arr[i][1] >> arr[i][0] >> arr[i][2];
    }
    sort(arr+1, arr+n+1);
    
    set<array<ll, 2>> dp; // (end, max_reward_before)
    dp.insert({0, 0});
    for(int i = 1; i <= n; ++i) {
        auto iter = dp.lower_bound({arr[i][1]});
        iter--;
        //                    not take ith  ,    take ith
        ll maxReward = max((*dp.rbegin())[1], arr[i][2]+(*iter)[1]);
        dp.insert({arr[i][0], maxReward});
    }
    cout << (*dp.rbegin())[1];
}