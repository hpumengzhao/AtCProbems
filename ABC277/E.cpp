#include<bits/stdc++.h>
using namespace std;
struct node
{
    int u;
    int dis;
    bool operator<(const node &other) const{
        return dis > other.dis;
    }
};

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> u(m + 1), v(m + 1), a(m + 1);
    vector<vector<pair<int, int>> > G(2 * n + 1);
    for(int i = 1; i <= m; i++){
        cin >> u[i] >> v[i] >> a[i];
        if(a[i] == 1){
            G[u[i]].push_back({v[i], 1});
            G[v[i]].push_back({u[i], 1});
        }else{
            G[u[i] + n].push_back({v[i] + n, 1});
            G[v[i] + n].push_back({u[i] + n, 1});
        }
    } 
    int x;
    for(int i = 1; i <= k; i++){
        cin >> x;
        G[x].push_back({x + n, 0});
        G[x + n].push_back({x , 0});
    }

    function<int(int)> dij = [&](int u){
        vector<int> dis(2 * n + 1, 1e9);
        vector<int> vis(2 * n + 1, 0);
        dis[u] = 0;
        priority_queue<node> q;
        q.push({u, 0});
        while(!q.empty()){
            auto rt = q.top();q.pop();
            int u = rt.u;
            if(vis[u]) continue;
            vis[u] = 1;
            for(auto &E: G[u]){
                int v = E.first;
                int w = E.second;
                if(dis[v] > dis[u] + w){
                    dis[v] = dis[u] + w;
                    q.push({v, dis[v]});
                }
            }
        }
        int ans = min(dis[n], dis[2 * n]);
        return ans;
    };
    int res = dij(1);
    if(res == 1e9) res = -1;
    cout << res << endl;
}
