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
	int n, S;
	cin >> n >> S;
	vector<int> a(n + 1), b(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> b[i];
	}
	dp[0][0] = 1;
	vector<vector<int>> dp(n + 1, vector<int>(S + 1 , 0));
	for(int i = 1; i <= n; i++){
		for(int last = 0; last <= S; last++){
			if(dp[i - 1][last]){
				 if(last + a[i] <= S) dp[i][a[i] + last] = 1;
				 if(last + b[i] <= S) dp[i][b[i] + last] = 1;
			}
		}
	}
	if(dp[n][S]){
		cout << "Yes\n";
		string ans = "";
		int now = S;
		for(int i = n; i >= 1; --i){
			if(now >= a[i] && dp[i - 1][now - a[i]]){
				ans += "H";
				now -= a[i];
			}else{
				ans += "T";
				now -= b[i];
			}
		}
		reverse(ans.begin(), ans.end());
		cout << ans << endl;
	}else{
		cout << "No\n";
	}
}


