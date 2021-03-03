#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

// int main() {
//     ios::sync_with_stdio(0); 
//     cin.tie(0);

//     int n, m;
//     cin >> n >> m;
//     multiset<int, greater<int>> s;
//     for(int i = 0; i < n; ++i) {
//         int ticket;
//         cin >> ticket;
//         s.insert(ticket);
//     }
//     for(int i = 0; i < m; ++i) {
//         int customer;
//         cin >> customer;
//         auto iter = s.lower_bound(customer);
//         if(iter==s.end()) {
//             cout << -1 << "\n";
//         }
//         else {
//             cout << *iter << "\n";
//             s.erase(iter);
//         }
//     }
// }

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    multiset<int> s;
    for(int i = 0; i < n; ++i) {
        int ticket;
        cin >> ticket;
        s.insert(ticket);
    }
    for(int i = 0; i < m; ++i) {
        int customer;
        cin >> customer;
        auto iter = s.upper_bound(customer);
        if(iter==s.begin()) {
            cout << -1 << "\n";
        }
        else {
            --iter;
            cout << *iter << "\n";
            s.erase(iter);
        }
    }
}