#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

int n, m;
const int maxN = 1e5;
set<int> adj[maxN+1];
int ind[maxN+1], outd[maxN+1];
vector<int> ans;

void dfs(int u) {
    while(adj[u].size()) {
        int v = *adj[u].begin();
        adj[u].erase(v);
        dfs(v);
        ans.push_back(v);
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].insert(b);
        outd[a]++;
        ind[b]++;
    }

    for(int i = 1; i <= n; ++i) {
        if(i==1) {
            if(outd[i] != ind[i] + 1) {
                cout << "IMPOSSIBLE";
                return 0;
            }
        } else if(i==n) {
            if(ind[i] != outd[i] + 1) {
                cout << "IMPOSSIBLE";
                return 0;
            }
        } else if(outd[i] != ind[i]) {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }

    dfs(1);
    ans.push_back(1);
    reverse(ans.begin(), ans.end());
    if(ans.size() != m+1) {
        cout << "IMPOSSIBLE";
        return 0;
    } 
    for(int u : ans) cout << u << " ";
}