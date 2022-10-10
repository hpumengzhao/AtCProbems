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


int main(){
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	vector<vector<int>> need(m + 1);

	for(int i = 0; i < n; i++) cin >> a[i];

	for(int i = 0; i < n; i++){
		if(a[i] >= n) continue;
		int l = (a[i] >= 0 ? 1 : (-a[i] + i) / (i + 1));
		int r = min(m + 1, (n - a[i] + i) / (i + 1));
		for(int j = l ; j < r; j++){
			need[j].push_back(a[i] + j * (i + 1));
		}
	}
	for(int i = 1; i <= m; i++){
		int siz = (int)need[i].size();
		vector<int> vis(siz + 1, 0);
		for(auto &v: need[i]){
			if(v >= 0 && v < siz) vis[v] = 1;
		}
		int ans = 0;
		while(vis[ans]) ++ans;
		cout << ans << endl;
	}
}