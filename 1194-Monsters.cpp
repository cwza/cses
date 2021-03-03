#include <bits/stdc++.h>
#include <utility>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef array<int, 2> pos;

/*
 * Lava Flow Problem
 * https://www.youtube.com/watch?v=hB59dxdDLII
*/

int n, m;
const int maxN = 1000, maxM = 1000, inf = maxN+maxM;
string grid[maxN];
vector<pos> monsterPos, goalPos;
pos aPos;
int monsterDist[maxN][maxM], aDist[maxN][maxM];
pair<char, pos> monsterParent[maxN][maxM], aParent[maxN][maxM];

bool isValid(int x, int y, bool visited[maxN][maxM]) {
    if(x>=0 && x<n && y>=0 && y < m && grid[x][y]!='#' && !visited[x][y]) return true;
    return false;
}

void bfs(vector<pos> srcs, int dist[maxN][maxM],  pair<char, pos> parent[maxN][maxM]) {
    int xs[] = {1, -1, 0, 0}, ys[] = {0, 0, 1, -1}, dir[] = {'D', 'U', 'R', 'L'};
    bool visited[maxN][maxM] = {{0}};
    fill(&dist[0][0], &dist[0][0]+maxN*maxM, inf);
    queue<array<int, 2>> q;
    for(auto src : srcs) {
        q.push(src);
        visited[src[0]][src[1]] = true;
        dist[src[0]][src[1]] = 0;
    }
    int d = 1;
    while(q.size()) {
        int qSz = q.size();
        while(qSz--) {
            auto[x, y] = q.front(); q.pop();
            for(int i = 0; i < 4; ++i) {
                int nextX = x+xs[i], nextY = y+ys[i];
                if(isValid(nextX, nextY, visited)) {
                    q.push({nextX, nextY});
                    visited[nextX][nextY] = true;
                    dist[nextX][nextY] = d;
                    parent[nextX][nextY].first = dir[i];
                    parent[nextX][nextY].second = {x, y};
                }
            }
        }
        d++;
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        string a;
        cin >> a;
        grid[i] = a;
        for(int j = 0; j < m; ++j) {
            if(grid[i][j]=='A') aPos = {i, j};
            if(grid[i][j]=='M') monsterPos.push_back({i, j});
            if(grid[i][j]!='#' && (i==0 || i==n-1 || j==0 || j==m-1)) goalPos.push_back({i, j});
        }
    }

    bfs(monsterPos, monsterDist, monsterParent);
    bfs({aPos}, aDist, aParent);

    int lastX = -1, lastY = -1;
    for(auto[x, y] : goalPos) {
        if(aDist[x][y]<monsterDist[x][y]) {
            lastX = x;
            lastY = y;
        }
    }
    
    if(lastX != -1) {
        vector<char> ans;
        int curX = lastX, curY = lastY;
        while(aParent[curX][curY].first != 0) {
            auto [dir, cur] = aParent[curX][curY];
            ans.push_back(dir);
            curX = cur[0];
            curY = cur[1];
        }
        reverse(ans.begin(), ans.end());
        cout << "YES\n";
        cout << ans.size() << "\n";
        for(auto dir : ans) cout << dir;
    } else {
        cout << "NO";
    }
}

