#include <bits/stdc++.h>

using namespace std;
struct edge{
    int u, v;
    long long w;
    bool operator<(const edge &other) const{
        return w > other.w;
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    
    auto qpow = [&](long long a, long long b){
        long long ans = 1;
        while(b){
            if(b & 1) ans = ans * a % m;
            a = a * a % m;
            b >>= 1;
        }
        return ans % m;
    };
    auto ev = [&](long long x, long long y){
        return (qpow(x, y) + qpow(y, x)) % m;
    };


    vector<edge> E;
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            E.push_back({i, j, ev(a[i], a[j])});
        }
    }
    
    vector<int> fa(n + 1);
    for(int i = 1; i <= n; i++) fa[i] = i;
    function<int(int)> find = [&](int x){
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    };
    auto unite = [&](int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return ;
        fa[x] = y;
        return ;
    };
    auto same = [&](int x, int y){
        return find(x) == find(y);
    };

    sort(E.begin(), E.end());
    long long ans = 0;
    for(auto e: E){
        int u = e.u;
        int v = e.v;
        if(same(u, v)) continue;
        ans += e.w;
        unite(u, v);
    }
    cout << ans << endl;
}