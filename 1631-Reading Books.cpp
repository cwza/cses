#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
If the largest number is greater than the sum of other numbers, then the answer is 2*(largest number)
else the answer is the sum of all numbers
*/

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> arr(n);
    for(int i = 0; i < n; ++i) cin >> arr[i];
    
    nth_element(arr.begin(), arr.end()-1, arr.end());
    ll largest = arr[n-1];
    ll sum = accumulate(arr.begin(), arr.end(), (ll)0);
    ll sumOthers = sum - largest;
    if(largest > sumOthers) cout << 2*largest;
    else cout << sum;
}