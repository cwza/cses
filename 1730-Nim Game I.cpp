#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
The grundy number of x is just x
So directly take xor of x's
*/


int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int ans = 0;
        while(n--) {
            int x;
            cin >> x;
            ans ^= x;
        }
        if(ans==0) cout << "second\n";
        else cout << "first\n";
    }
}