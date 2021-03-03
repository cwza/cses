#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

const int maxN = 1000;
string field[maxN];
int n, m;

bool allow(int x, int y) {
    return x>=0 && x<n && y>=0 && y<m && field[x][y]=='.';
}

void dfs(int x, int y) {
    if(allow(x+1, y)) {
        field[x+1][y] = '#';
        dfs(x+1, y);
    }
    if(allow(x-1, y)) {
        field[x-1][y] = '#';
        dfs(x-1, y);
    }
    if(allow(x, y+1)) {
        field[x][y+1] = '#';
        dfs(x, y+1);
    }
    if(allow(x, y-1)) {
        field[x][y-1] = '#';
        dfs(x, y-1);
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; ++i) cin >> field[i];

    int ans = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(allow(i, j)) {
                field[i][j] = '#';
                dfs(i, j);
                ans++;
            }
        }
    }
    cout << ans;
}
