#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, u, v;
    cin >> n;
    map<int, vector<int>> G;
    map<int, int> vis;
    for(int i = 1; i <= n; i++){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int ans = 1;
    function<void(int)> dfs = [&](int u){
        if(vis[u]) return ;
        vis[u] = 1;
        ans = max(ans, u);
        for(int v: G[u]) dfs(v);
    };
    dfs(1);
    cout << ans << endl;
}