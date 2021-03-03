#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

const int maxN = 1e5;
vi adj[maxN+1];
int n, m;
int parent[maxN+1], done[maxN+1];
vi ans;

void dfs(int u) {
    for(int v : adj[u]) {
        if(done[v]==2 || v==parent[u]) continue;
        else if(done[v]==0) {
            parent[v] = u;
            done[v] = 1;
            dfs(v);
            done[v] = 2;
        }
        else if(done[v]==1) {
            int cur = u;
            ans.push_back(v);
            while(cur!=v) {
                ans.push_back(cur);
                cur = parent[cur];
            }
            ans.push_back(v);
            cout << ans.size() << "\n";
            for(int i = 0; i < ans.size(); ++i) 
                cout << ans[i] << " ";
            exit(0);
        }
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1; i <= n; ++i) {
        if(done[i]==0) {
            done[i] = 1;
            dfs(i);
            done[i] = 2;
        }
    }
    cout << "IMPOSSIBLE";
}

