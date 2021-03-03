#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

const int maxN = 1e5;
vi graph[maxN+1];
int n, m, ans[maxN+1];

int invHelper(int group) {
    if(group==1) return 2;
    else if(group==2) return 1;
    else return -1;
}

void dfs(int u) {
    int group = ans[u];
    for(int v : graph[u]) {
        if(group==ans[v]) {
            cout << "IMPOSSIBLE";
            exit(0);
        }
        if(ans[v] == 0) {
            ans[v] = invHelper(group);  
            dfs(v);
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
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    for(int i = 1; i <= n; ++i) {
        if(ans[i]==0) {
            ans[i] = 1;
            dfs(i);
        }
    }

    for(int i = 1; i <= n; ++i) cout << ans[i] << " ";
}

