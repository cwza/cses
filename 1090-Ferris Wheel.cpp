#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    vi arr(n);
    for(int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr.begin(), arr.end());

    int numPairs = 0; // We want to maximize number of pairs
    int i = 0, j = n-1;
    while(i<j) {
        while(i<j && arr[i]+arr[j]>x) j--; // We greedyly choose the max one
        if(i==j) break;
        numPairs++;
        i++;
        j--;
    }
    cout << n-numPairs;
}