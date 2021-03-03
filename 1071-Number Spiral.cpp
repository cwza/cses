#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    ll t;
    cin >> t;
    for(ll i = 0; i < t; i++) {
        ll x, y;
        cin >> y >> x;
        ll z = max(x, y);
        ll z2 = (z-1)*(z-1);
        if(z%2==0) {
            if(x==z) {
                cout << z2 + y << "\n";
            } else {
                cout << z2 + z + (z-x) << "\n";
            }
        } else {
            if(y==z) {
                cout << z2 + x << "\n";
            } else {
                cout << z2 + z + (z-y) << "\n";
            }
        }
    }
}