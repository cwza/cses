#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
x: number of times that you take 2 from a and 1 from b
y: number of times that you take 2 from b and 1 from a
a = 2x + y
b = x + 2y
and x, y >= 0
===========>
2a - b = 3x
2b - a = 3y
and x, y >= 0
===========>
2a-b should be greater or equal to 0 and 2a-b should be dividible by 3
2b-a should be greater or equal to 0 and 2b-a should be dividible by 3
*/

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int n;
    cin >> n;   
    while(n--) {
        int a, b;
        cin >> a >> b;
        if(2*a-b>=0 && (2*a-b)%3==0 && 2*b-a>=0 && (2*b-a)%3==0) cout << "YES\n";
        else cout << "NO\n";
    }
}