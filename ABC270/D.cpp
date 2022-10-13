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


//dp[i] = max{dp[i - k[j]] + k[j]} 


int main(){
	int n, k;
	cin >> n >> k;
	vector<int> dp(n + 1);
	vector<int> a(k);
	for(int i = 0; i < k; i++){
		cin >> a[i];
	}
	dp[0] = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < k; j++){
			if(i >= a[j]) dp[i] = max(dp[i], (i - a[j]) - dp[i - a[j]] + a[j]);
		}
	}
	cout << dp[n] << endl;
}




