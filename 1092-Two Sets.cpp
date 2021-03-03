#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
sum of each group is n*(n+1)/4, from this formula we know that our sum is either divided by n or divided by n+1
1. Divided by n:
    ex: n = 7, [1, 2, 3, 4, 5, 6, 7], sum of each group = 14
    v1 = [7, (1, 6)]
    v2 = [(2, 5), (3, 4)]
2. divided by n+1:
    ex: n = 8, [1, 2, 3, 4, 5, 6, 7, 8], sum of each group = 18
    v1 = [(1, 8), (2, 7)]
    v2 = [(3, 6), (4, 5)]
*/

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    ll n;
    cin >> n;    
    if(n*(n+1)/2 % 2 != 0) {
        cout << "NO";
        return 0;
    }

    ll sum = n*(n+1)/4, runSum = 0, target;
    vi v1, v2;
    if(sum % n == 0) {
        target = n;
        v1.push_back(n);
        runSum += n;
    } else {
        target = n + 1;
    }
    int i = 1;
    while(runSum < sum) {
        v1.push_back(i);
        v1.push_back(target-i);
        i++;
        runSum += target;
    }
    while(runSum < 2*sum) {
        v2.push_back(i);
        v2.push_back(target-i);
        i++;
        runSum += target;
    }
    cout << "YES\n";
    cout << v1.size() << "\n";
    for(int i = 0; i < v1.size(); ++i) cout << v1[i] << " ";
    cout << "\n";
    cout << v2.size() << "\n";
    for(int i = 0; i < v2.size(); ++i) cout << v2[i] << " ";
}