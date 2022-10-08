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
const ll INF = 1e18 + 10;


int main(){
	int n, m, k;
	cin >> n >> m >> k;
	vector<ll> u(m + 1), v(m + 1), w(m + 1), e(k + 1);
	for(int i = 1; i <= m; i++){
		cin >> u[i] >> v[i] >> w[i];
	}
	for(int i = 1; i <= k; i++) cin >> e[i];

	vector<ll> dis(n + 1, INF);

	vector<ll> last(n + 1, -1);

	for(int i = 1; i <= k; i++){
		if(u[e[i]] == 1){
			if(dis[v[e[i]]] > w[e[i]]){
				dis[v[e[i]]] = w[e[i]];
				last[v[e[i]]] = i;
			}
			continue;
		}
		if(last[u[e[i]]] != -1){
			if(dis[v[e[i]]] > dis[u[e[i]]] + w[e[i]]){
				dis[v[e[i]]] = dis[u[e[i]]] + w[e[i]];
				last[v[e[i]]] = i;
			}
		}
	}

	cout << (dis[n] == INF ? -1 : dis[n]) << endl;
	return 0;
}


//dp[i][j][k]
