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

    set<int> positionS; positionS.insert(0), positionS.insert(n); // positions of traffic light
    map<int, int> lengthM; lengthM[n]++; // {interval_length: freq}
    while(x--) {
        int a;
        cin >> a;
        int r = *positionS.upper_bound(a);
        int l = *(--positionS.lower_bound(a));
        positionS.insert(a);
        lengthM[r-l]--;
        if(lengthM[r-l]==0) lengthM.erase(r-l);
        lengthM[r-a]++;
        lengthM[a-l]++;
        cout << (*lengthM.rbegin()).first << " ";
    }
}