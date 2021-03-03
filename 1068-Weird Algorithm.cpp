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
    while(n != 1) {
        cout << n << " ";
        if(n&1) n = 3*n+1;
        else n /= 2;
    }
    cout << n;
}
