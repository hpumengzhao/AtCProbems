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
 
	function<void(int, int, int, int, int)> dfs1 = [&](int x, int y, int ex, int ey, int now){
		if(x > ex || y > ey) return ;
		if(x == ex && y == ey){
			A[ex][ey][now]++;
			return ;
		}
		if(x < n) dfs1(x + 1, y, ex, ey, now ^ maze[x + 1][y]);
		if(y < n) dfs1(x, y + 1, ex, ey, now ^ maze[x][y + 1]);
	};
 
	int sx, sy;
	function<void(int, int, int, int, int)> dfs2 = [&](int x, int y, int ex, int ey, int now){
		if(x > ex || y > ey) return ;
		if(x == ex && y == ey){
			B[sx][sy][now]++;
			return ;
		}
		if(x < n) dfs2(x + 1, y, ex, ey, now ^ maze[x + 1][y]);
		if(y < n) dfs2(x, y + 1, ex, ey, now ^ maze[x][y + 1]);
	};
	for(int x = 1; x <= n; x++){
		int y = n + 1 - x;
		dfs1(1, 1, x, y, maze[1][1]);
		sx = x;
		sy = y;
		dfs2(x, y, n, n, maze[x][y]);
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