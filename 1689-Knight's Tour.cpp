#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef array<int, 2> point;

/*
Backtracking and Warnsdorf’s rule
The idea is to always move the knight so that it ends up in a square where the number of possible moves is as small as possible.
*/

int oriX, oriY;
const int n = 8;
int board[n][n];
int ans[n][n];

vector<point> next(int x, int y) {
    int xDir[] = {-1, -1, -2, -2,  1, 1,  2, 2};
    int yDir[] = {-2,  2, -1,  1, -2, 2, -1, 1};
    vector<point> nexts; 
    for(int i = 0; i < 8; ++i) {
        int nextX = x + xDir[i]; int nextY = y + yDir[i];
        if(nextX>=0 && nextX<n && nextY>=0 && nextY < n && board[nextX][nextY]==0) {
            nexts.push_back({nextX, nextY});
        }
    }
    return nexts;
}

bool cmp(point a, point b) {
    return next(a[0], a[1]).size() < next(b[0], b[1]).size();
}

void helper(int x, int y) {
    auto nexts = next(x, y);
    sort(nexts.begin(), nexts.end(), cmp);
    for(auto [nextX, nextY] : nexts) {
        board[nextX][nextY] = board[x][y] + 1;
        if(board[nextX][nextY] == n*n) {
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    cout << board[i][j] << " ";
                }
                cout << "\n";
            }
            exit(0);
        }
        helper(nextX, nextY);
        board[nextX][nextY] = 0; 
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    cin >> oriY >> oriX; oriY--; oriX--;
    board[oriX][oriY] = 1;
    helper(oriX, oriY);

}