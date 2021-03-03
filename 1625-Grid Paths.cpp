#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
Optimization2:
If the path reaches the lower-left square before it has visited all other squares of the grid, 
it is clear that it will not be possible to complete the solution.

Optimization4:
if the path cannot continue forward but can turn either left or right, 
the grid splits into two parts that both contain unvisited squares. 
It is clear that we cannot visit all squares anymore, so we can terminate the search.
*/

int ans = 0;
bool done[7][7];

bool canGo(int x, int y) {
    return (x>=0 && x<7 && y>=0 && y<7 && !done[x][y]);
}

void dfs(int i, int x, int y, string & s) {
    if(x==6 && y==0) { // Optimization2
        if(i==48) ans += 1;
        return;
    }
    if(s[i]=='D' || s[i]=='?') { // Check dir
        if(canGo(x+1, y)) { // Check if next position can go or not
            if( !( !canGo(x+2, y) && canGo(x+1, y+1) && canGo(x+1, y-1) ) ) { // Optimization4
                done[x+1][y] = true;
                dfs(i+1, x+1, y, s);
                done[x+1][y] = false;
            }
        }
    }
    if(s[i]=='U' || s[i]=='?') {
        if(canGo(x-1, y)) {
            if( !( !canGo(x-2, y) && canGo(x-1, y+1) && canGo(x-1, y-1) ) ) {
                done[x-1][y] = true;
                dfs(i+1, x-1, y, s);
                done[x-1][y] = false;
            }
        }
    } 
    if(s[i]=='L' || s[i]=='?') {
        if(canGo(x, y-1)) {
            if( !( !canGo(x, y-2) && canGo(x+1, y-1) && canGo(x-1, y-1) ) ) {
                done[x][y-1] = true;
                dfs(i+1, x, y-1, s);
                done[x][y-1] = false;
            }
        }
    } 
    if(s[i]=='R' || s[i]=='?') {
        if(canGo(x, y+1)) {
            if( !( !canGo(x, y+2) && canGo(x+1, y+1) && canGo(x-1, y+1) ) ) {
                done[x][y+1] = true;
                dfs(i+1, x, y+1, s);
                done[x][y+1] = false;
            }
        }
    } 
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    string s;
    cin >> s;
    // string s = "??????R??????U??????????????????????????LD????D?";

    done[0][0] = true;
    dfs(0, 0, 0, s);
    cout << ans;
}
