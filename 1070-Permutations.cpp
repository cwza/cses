#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;


// print all evens then all odds
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int n;
    cin >> n;
    if(n==1) {
        cout << 1;
        return 0;
    }
    if(n==2 || n==3) {
        cout << "NO SOLUTION";
        return 0;
    }

    for(int i = 2; i <= n; i+=2) cout << i << " ";
    for(int i = 1; i <= n; i+=2) cout << i << " ";
}