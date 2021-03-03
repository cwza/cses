#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

//////////////////  TreeSet  ////////////////////
// int main() {
//     ios::sync_with_stdio(0); 
//     cin.tie(0);

//     int n, m, k;
//     cin >> n >> m >> k;
//     vi applicants(n), apartments(m);
//     for(int i = 0; i < n; ++i) cin >> applicants[i];
//     for(int i = 0; i < m; ++i) cin >> apartments[i];
//     sort(applicants.begin(), applicants.end());
//     multiset<int> treeAparment(apartments.begin(), apartments.end());

//     int ans = 0;
//     for(int applicant : applicants) {
//         auto iter = treeAparment.lower_bound(applicant-k);
//         if(iter!=treeAparment.end() && *iter <= applicant+k) {
//             ans++;
//             treeAparment.erase(iter);
//         } 
//     }
//     cout << ans;
// }

/////////////////////  Two Pointer  ///////////////////
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vi applicants(n), apartments(m);
    for(int i = 0; i < n; ++i) cin >> applicants[i];
    for(int i = 0; i < m; ++i) cin >> apartments[i]; 
    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());

    int ans = 0;
    for(int i = 0, j = 0; i < n && j < m; ++i) {
        // Find the smallest one that less than or equal to applicants[i]-k in apartemts
        // auto iter = lower_bound(apartments.begin()+j, apartments.end(), applicants[i]-k);
        // j = iter - apartments.begin();
        while(j<m && apartments[j] < applicants[i]-k) j++;
        if(j<m && apartments[j] <= applicants[i]+k) {
            ans++;
            j++;
        }
    }
    cout << ans;
}