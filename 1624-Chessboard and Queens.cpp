#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

// string board[8];
// bool colState[8] = {0};
// bool leftState[15] = {0};
// bool rightState[15] = {0};
// int ans = 0;

// void helper(int row) {
//     if(row == 8) {
//         ans++;
//         return;
//     }
//     for(int col = 0; col < 8; ++col) {
//         if(board[row][col]=='.' && !colState[col] && !leftState[row+col] && !rightState[row-col+7]) {
//             colState[col] = true;
//             leftState[row+col] = true;
//             rightState[row-col+7] = true;
//             helper(row+1);
//             colState[col] = false;
//             leftState[row+col] = false;
//             rightState[row-col+7] = false;
//         }
//     }
// }

// int main() {
//     ios::sync_with_stdio(0); 
//     cin.tie(0);

//     for(int i = 0; i < 8; ++i) cin >> board[i];

//     helper(0);
//     cout << ans;
// }

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    string board[8];
    for(int i = 0; i < 8; ++i) cin >> board[i];

    int cols[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    int ans = 0;
    do {
        bool leftState[15] = {0};
        bool rightState[15] = {0};
        bool ok = true;
        for(int row = 0; row < 8; ++row) {
            int col = cols[row];
            if(board[row][col]=='*' || leftState[row+col] || rightState[row-col+7]) {
                ok = false;
                break;
            }
            leftState[row+col] = true;
            rightState[row-col+7] = true;
        }
        if(ok) ans++;
    } while(next_permutation(cols, cols+8));
    cout << ans;
}