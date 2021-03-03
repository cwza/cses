#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    ll n;
    cin >> n;
    ll total = 0;
    ll expected = (1+n)*n/2;
    ll a;
    for(int i = 1; i < n; i++) {
        cin >> a;
        total += a;
    }
    cout << expected - total;
}