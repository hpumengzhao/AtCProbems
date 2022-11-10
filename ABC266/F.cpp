#include<bits/stdc++.h>

using namespace std;
const int N = 2e5 + 100;
int f[N];
int find(int x){
	return x == f[x] ? x : f[x] = find(f[x]);
}
void init(int n){
	for(int i = 1; i <= n; i++){
		f[i] = i;
	}
}
void unite(int x, int y){
	x = find(x);
	y = find(y);
	if(x == y){
		return ;
	}
	f[x] = y;
}
bool same(int x, int y){
	x = find(x);
	y = find(y);
	return x == y;
}
map<int, int> cv;
vector<int> G[N];
int fa[N], dep[N];
void dfs(int u, int f){
	fa[u] = f;
	dep[u] = dep[f] + 1;
	for(int v: G[u]){
		if(v == f) continue;
		dfs(v, u);
	}
}
int main(){
	int n;
	cin >> n;
	init(n);
	vector<int> u(n + 1), v(n + 1);
	int L = -1;
	int R = -1;
	int id = 1;
	for(int i = 1; i <= n; i++){
		cin >> u[i] >> v[i];
		if(same(u[i], v[i])){
			L = u[i];
			R = v[i];
		}else{
			unite(u[i], v[i]);
			G[u[i]].push_back(v[i]);
			G[v[i]].push_back(u[i]);
		}
	}
	set<int> st;
	dfs(1, 0);
	int dd = min(dep[L], dep[R]);
	while(dep[L] > dd){
		st.insert(L);
		cv[L] = 1;
		L = fa[L];
	}
	while(dep[R] > dd){
		st.insert(R);
		cv[R] = 1;
		R = fa[R];
	}
	while(L != R){
		st.insert(R);
		st.insert(L);
		cv[R] = 1;
		cv[L] = 1;
		L = fa[L];
		R = fa[R];
	}
	st.insert(R);
	cv[R] = 1;
	init(n);
	for(int i = 1; i <= n; i++){
		if(cv[u[i]] && cv[v[i]]) continue;
		unite(u[i], v[i]);
	}

	int q, x, y;
	cin >> q;
	while(q--){
		cin >> x >> y;
		if(same(x, y)){
			cout << "Yes\n";
		}else{
			cout << "No\n";
		}
	}
	return 0;
}