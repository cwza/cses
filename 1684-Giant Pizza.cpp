#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
2SAT Problem
example:
+ 1 + 2
- 1 + 3
+ 4 - 2
(+1 v +2) ^ (-1 v 3) ^ (4 v -2)
*/


int n, m;
const int maxM = 2e5;
vector<int> adj[maxM+2], radj[maxM+2];
bool visited[maxM+2];
vector<int> s;
int who[maxM+2];

void dfs1(int u) {
    for(int v : adj[u]) {
        if(!visited[v]) {
            visited[v] = true;
            dfs1(v);
            s.push_back(v);
        }
    }
}
void dfs2(int root, int u) {
    for(int v : radj[u]) {
        if(!visited[v]) {
            visited[v] = true;
            who[v] = root;
            dfs2(root, v);
        }
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    cin >> n >> m;
    // Trick map +3 to +6, -3 to +7, then we can use +6 xor 1 = +7, +7 xor 1 = +6 to switch between 3 and -3
    for(int i = 1; i <= n; ++i) {
        char c1, c2; int a1, a2;
        cin >> c1 >> a1 >> c2 >> a2;
        a1 *= 2; a2 *= 2; 
        if(c1=='-') a1 ^= 1;
        if(c2=='-') a2 ^= 1;
        adj[a1^1].push_back(a2);
        adj[a2^1].push_back(a1);
        radj[a2].push_back(a1^1);
        radj[a1].push_back(a2^1);
    }

    for(int u = 2; u <= 2*m+1; ++u) {
        if(!visited[u]) {
            visited[u] = true;
            dfs1(u);
            s.push_back(u);
        }
    }
    fill(visited, visited+maxM+2, false);
    int groupId = 0;
    for(int i = s.size()-1; i >= 0; --i) {
        int u = s[i];
        if(!visited[u]) {
            visited[u] = true;
            groupId++;
            who[u] = groupId;
            dfs2(groupId, u);
        }
    }

    vector<char> ans;
    for(int u = 1; u <= m; ++u) {
        if(who[2*u]==who[2*u+1]) {
            cout << "IMPOSSIBLE";
            return 0;
        }
        if(who[2*u] < who[2*u+1]) ans.push_back('-'); // We can use this because we use Kosaraju's algorithm and assign SCC incrementally
        else ans.push_back('+');
    }
    for(char u : ans) cout << u << " ";
}
