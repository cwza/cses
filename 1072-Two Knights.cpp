#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
If two knight attack each other then they will be in 2*3 rectangle or 3*2 rectangle. 
So the number of ways of placing them is (n-1)*(n-2)+(n-2)*(n-1). 
Also in each rectangle no ways of placing the knight is 2. So total ways of placing knight so that they attack each other will be 2*2*(n-1)*(n-2). 
So the number of ways such that knight do not attack each other will be n*n*(n*n-1)/2 — 4*(n-1)*(n-2)
*/

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int n;
    cin >> n;

    for(ll k = 1; k <= n; k++) {
        ll all = (k*k)*(k*k-1) / 2; // all ways to place 2 knights no matter they will attack each other or not
        ll attack = 2*2*(k-1)*(k-2); // ways that they will attack each other
        cout << all-attack << "\n";
    }
}