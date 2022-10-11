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
	ll n, k;
	cin >> n >> k;
	vector<pair<ll, int>> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.begin(), a.end());

	long long round = 0;
	for(int i = 0; i < n; i++){
		if(a[i].first - round > 0){
			ll contri = (a[i].first - round) * (n - i);
			if(k >= contri){
				k -= contri;
				round += a[i].first - round;
			}else{
				ll shift = k / (n - i);
				k -= shift * (n - i);
				round += shift;
				break;
			}
		}
	}

	for(auto &v: a){
		v.first = max(0LL, v.first - round);
	}

	sort(a.begin(), a.end(), [&](pair<ll, int> x, pair<ll, int> y){
		return x.second < y.second;
	});


	for(int i = 0; i < n; i++){
		if(k && a[i].first){
			 --a[i].first;
			 --k;
		}
	}


	for(auto &v: a){
		cout << v.first << endl;
	}
}