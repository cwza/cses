#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef tuple<int, int, int> ti;

// Swipe line
// int main() {
//     ios::sync_with_stdio(0); 
//     cin.tie(0);

//     int n;
//     cin >> n;

//     vector<ti> arr; // [(time, isOut, idx)]
//     for(int i = 0; i < n; ++i) {
//         int inT, outT;
//         cin >> inT >> outT;
//         arr.push_back(make_tuple(inT, 0, i));
//         arr.push_back(make_tuple(outT, 1, i));
//     }
//     sort(arr.begin(), arr.end());

//     vi available; // available zoom
//     int maxZoom = 0;
//     vi ans(n);
//     for(auto [t, isOut, idx] : arr) {
//         if(!isOut) {
//             if(available.size()) {
//                 ans[idx] = available.back();
//                 available.pop_back();
//             } else {
//                 ans[idx] = ++maxZoom;
//             }
//         } else {
//             available.push_back(ans[idx]);
//         }
//     }

//     cout << maxZoom << "\n";
//     for(int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
// }

// Similar to 1632 Movie Festival II
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int n;
    cin >> n;
    vector<array<int, 3>> arr(n); // [(end, start, customer_index)]
    for(int i = 0; i < n; ++i) {
        cin >> arr[i][1] >> arr[i][0];
        arr[i][2] = i;
    }
    sort(arr.begin(), arr.end());

    set<pi> s; // {(end, room_index)}
    vi ans(n);
    int curRoomIdx = 1;
    for(int i = 0; i < n; ++i) {
        auto [end, start, cIdx] = arr[i];
        auto iter = s.lower_bound(make_pair(start, -1));
        if(iter!=s.begin()) {
            iter--;
            int roomIdx = (*iter).second;
            ans[cIdx] = roomIdx;
            s.erase(iter);
            s.insert(make_pair(end, roomIdx));
        } else {
            ans[cIdx] = curRoomIdx;
            s.insert(make_pair(end, curRoomIdx));
            curRoomIdx++;
        }
    }
    cout << curRoomIdx-1 << "\n";
    for(int room : ans) cout << room << " ";
}