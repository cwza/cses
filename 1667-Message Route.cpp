#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

const int maxN = 1e5;
vi graph[maxN+1];
int parent[maxN+1];
bool done[maxN+1];
int n, m;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    
    cin >> n >> m;
    // Build Graph
    for(int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // BFS
    queue<int> q; q.push(1); done[1] = true;
    while(q.size()) {
        int u = q.front(); q.pop();
        if(u==n) break;
        for(int v : graph[u]) {
            if(!done[v]) {
                done[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    if(parent[n]==0) {
        cout << "IMPOSSIBLE";
        return 0;
    }    
    vi ans;
    int cur = n;
    while(cur != 0) {
        ans.push_back(cur);
        cur = parent[cur];
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(auto t : ans) cout << t << " ";
}
