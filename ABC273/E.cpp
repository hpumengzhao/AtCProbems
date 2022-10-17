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
const int N = 5e5 + 100;

int fa[N], val[N], ptr = 0, cnt = 0;
map<int, int> table;
string op;

int main(){
	int Q, x, y, z;
	cin >> Q;
	vector<int> trace;
	for(int qq = 1; qq <= Q; qq++){
		cin >> op;
		if(op == "ADD"){
			cin >> x;
			val[++cnt] = x;
			fa[cnt] = ptr;
			ptr = cnt;
			trace.pb(x);
		}
		if(op == "DELETE"){
			ptr = fa[ptr];
			if(ptr == 0){
				trace.pb(-1);
			}else{
				trace.pb(val[ptr]);
			}
		}
		if(op == "SAVE"){
			cin >> y;
			if(ptr == 0) trace.pb(-1);
			else trace.pb(val[ptr]);
			table[y] = ptr;
		}
		if(op == "LOAD"){
			cin >> z;
			ptr = table[z];
			if(ptr == 0) trace.pb(-1);
			else trace.pb(val[ptr]);
		}
	}

	for(int &v: trace){
		cout << v << ' ';
	}
	cout << endl;
}