#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
This question equals count the number of 5 in the prime factors of n!
ex:  5! = (2^3 * 3 * 5). So count of trailing 0s is 1
ex: 11! = (2^8 * 3^4 * 5^2 * 7). So count of trailing 0s is 2
Trailing 0s in n! = Count of 5s in prime factors of n!
                  = floor(n/5) + floor(n/25) + floor(n/125) + ....
*/

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int n;
    cin >> n;
    ll ans = 0;
    for(ll i = 5; i <= n; i*=5) {
        ans += n/i;
    }
    cout << ans;
}