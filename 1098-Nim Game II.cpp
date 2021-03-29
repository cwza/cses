#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
grundy(0) = 0
grundy(1) = 1
grundy(2) = 2
grundy(3) = 3
grundy(4) = 0
grundy(5) = 1
grundy(6) = 2
grundy(7) = 3
...
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
            ans ^= x%4;
        }
        if(ans==0) cout << "second\n";
        else cout << "first\n";
    }
}