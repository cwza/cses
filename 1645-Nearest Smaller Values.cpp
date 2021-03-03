#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
Monotonic Deque
*/

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int n;
    cin >> n;
    vi arr(n);
    for(int i = 0; i < n; ++i) cin >> arr[i];

    deque<int> d;
    for(int i = 0; i < n; ++i) {
        while(d.size() && arr[d.back()]>=arr[i]) d.pop_back();
        if(d.size()) cout << d.back()+1 << " ";
        else cout << 0 << " ";
        d.push_back(i);
    }
}