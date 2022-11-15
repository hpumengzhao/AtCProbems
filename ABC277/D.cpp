
#include<bits/stdc++.h>
using namespace std;
map<int, int> fa;
map<int, long long> w;
int find(int x){
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return ;
    fa[x] = y;
    w[y] += w[x];
}
map<int, int> cnt;
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    long long s = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        s += a[i];
        w[a[i]] += a[i];
        cnt[a[i]]++;
        fa[a[i]] = a[i];
    }
    for(int i = 1; i <= n; i++){
        if(cnt[(a[i] + 1) % m]){
            unite(a[i], (a[i] + 1) % m);
        }
    }
    long long ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, w[a[i]]);
    }
    cout << s - ans << endl;
}