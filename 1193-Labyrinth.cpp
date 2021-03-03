#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef tuple<int, int, char> pe;

const int maxN = 1000;
string field[maxN];
pe parent[maxN][maxN]; // {parent_x, parent_y, dir)
int n, m, startX, startY, endX, endY;

bool allow(int x, int y) {
    return x>=0 && x<n && y>=0 && y<m && field[x][y]=='.';
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        cin >> field[i];
        for(int j = 0; j < m; ++j) {
            if(field[i][j]=='A') startX = i, startY = j;
            if(field[i][j]=='B') endX = i, endY = j, field[i][j] = '.';
        }
    }


    queue<array<int, 2>> q; // x, y
    q.push({startX, startY});
    int dirXs[] = {0, 0, 1, -1};
    int dirYs[] = {1, -1, 0, 0};
    char dirs[] = {'R', 'L', 'D', 'U'};
    while(q.size()) {
        auto [x, y] = q.front(); q.pop();
        if(x==endX && y==endY) break;
        for(int j = 0; j < 4; ++j) {
            int newX = x + dirXs[j], newY = y + dirYs[j];
            if(allow(newX, newY)) {
                field[newX][newY] = '#';
                parent[newX][newY] = make_tuple(x, y, dirs[j]);
                q.push({newX, newY});
            }
        }
    }

    if(!get<2>(parent[endX][endY])) {
        cout << "NO";
        return 0;
    }

    int curX = endX, curY = endY;
    string ans;
    while(curX != startX || curY != startY) {
        auto [px, py, dir] = parent[curX][curY];
        ans.push_back(dir);
        curX = px, curY = py;
    }
    reverse(ans.begin(), ans.end());
    cout << "YES\n";
    cout << ans.size() << "\n";
    cout << ans;
}
