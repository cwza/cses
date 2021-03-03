#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

const int maxN = 1e5;
vi graph[maxN+1];
bool done[maxN+1];
int n, m;

void dfs(int u) {
    for(int v : graph[u]) {
        if(!done[v]) {
            done[v] = true;
            dfs(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    
    cin >> n >> m;
    // Generate Graph
    for(int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // Run Dfs
    vi ans; // First node of each connected component
    for(int i = 1; i <= n; ++i) {
        if(!done[i]) {
            done[i] = true;
            dfs(i);
            ans.push_back(i);
        }
    }

    cout << ans.size()-1 << "\n";
    for(int i = 0; i < ans.size()-1; ++i) cout << ans[i] << " " << ans[i+1] << "\n";
}

