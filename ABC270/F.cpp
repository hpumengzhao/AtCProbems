#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9+7;
#define pb push_back
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define fep(i,a,b) for(int i=(a);i>=(b);i--)
#define deb(x) cerr<<#x<<" = "<<(x)<<"\n"
typedef vector<int> VI;
typedef vector<ll> VII;
typedef pair<int,int> pii;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll Rand(ll B) {
	return (ull)rng() % B;
}
struct edge{
	int u, v;
	ll w;
};
bool cmp(edge a, edge b){
	return a.w < b.w;
}
vector<int> f, siz;
int find(int x){
	return x == f[x] ? x : f[x] = find(f[x]);
}
void unite(int x, int y){
	x = find(x);
	y = find(y);
	if(x == y) return ;
	f[x] = y;
	siz[y] += siz[x];
}
int main(){
	int n, m;
	cin >> n >> m;
	f.resize(n + 3);
	siz.resize(n + 3);
	vector<ll> x(n + 1), y(n + 1);
	vector<edge> E;
	for(int i = 1; i <= n; i++) cin >> x[i], E.pb({i, n + 1, x[i]}); 
	for(int i = 1; i <= n; i++) cin >> y[i], E.pb({i, n + 2, y[i]});
	int u, v, w;
	for(int i = 1; i <= m; i++){
		cin >> u >> v >> w;
		E.pb({u, v, w});
	}

	map<int, int> contains[4];
	for(int i = 1; i <= n + 2; i++) contains[0][i] = 1;
	for(int i = 1; i <= n + 1; i++) contains[1][i] = 1;
	for(int i = 1; i <= n; i++) contains[2][i] = 1;
	for(int i = 1; i <= n + 2; i++) contains[3][i] = 1;
	contains[3][n + 1] = 0;
	sort(E.begin(), E.end(), cmp);
	//全选
	ll res = 1e18;
	for(int cas = 0; cas < 4; cas++){
		for(int i = 1; i <= n + 2; i++) f[i] = i, siz[i] = 1;
		ll ans = 0;
		for(auto &e: E){
			int u = e.u;
			int v = e.v;
			ll w = e.w;
			if(find(u) != find(v) && contains[cas][find(u)] && contains[cas][find(v)]){
				ans += w;
				unite(u, v);
			}
		}
		bool ok = 1;
		for(int i = 1; i <= n; i++){
			if(find(i) != find(1)){
				ok = 0;
				break;
			}
		}
		if(ok) res = min(res, ans);
	}
	cout << res << endl;
}