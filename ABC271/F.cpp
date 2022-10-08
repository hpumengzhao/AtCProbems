#include<bits/stdc++.h>
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

map<int,ll> A[21][21], B[21][21];

int main(){
	int n;
	cin >> n;
	vector<vector<int>>  maze(n + 1, vector<int>(n + 1));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> maze[i][j];
		}
	}

	for(int i = 0; i < (1 << (n - 1)); i++){
		int sx = 1;
		int sy = 1;
		int val = maze[1][1];
		for(int j = 0; j < (n - 1); j++){
			if((i >> j) & 1) sx++;
			else sy++;
			val ^= maze[sx][sy];
		}
		A[sx][sy][val]++;
	}

	for(int i = 0; i < (1 << (n - 1)); i++){
		int sx = n;
		int sy = n;
		int val = maze[n][n];
		for(int j = 0; j < (n - 1); j++){
			if((i >> j) & 1) sx--;
			else sy--;
			val ^= maze[sx][sy];
		}
		B[sx][sy][val]++;
	}

	long long ans = 0;
	for(int x = 1; x <= n; x++){
		int y = n + 1 - x;
		for(auto &v: A[x][y]){
			int now = (v.first ^ maze[x][y]);
			ans += v.second * B[x][y][now];
		}
	}
	cout << ans << '\n';
}
