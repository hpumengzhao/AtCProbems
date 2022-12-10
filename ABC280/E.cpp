#include <bits/stdc++.h>

using namespace std;
const int mod = 998244353;
typedef long long ll;

ll qpow(ll a, ll b, ll mod){
    ll ans = 1;
    while(b){
        if(b & 1){
            ans = ans * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return ans % mod;
}

int main(){
    ll n, p;
    cin >> n >> p;
    vector<ll> dp(n + 1, 0);
    dp[1] = 1;
    ll inv = qpow(100, mod - 2, mod);
    for(int i = 2; i <= n; i++){
        long long a = (dp[i - 1] + 1) * (100 - p) % mod;
        dp[i] += a * inv % mod;
        a = (dp[i - 2] + 1) * p % mod;
        dp[i] += a * inv % mod;
        dp[i] %= mod;
    }
    cout << dp[n] << endl;
}

//dp[i]表示怪兽血量为i击败它所需要的攻击次数的期望
//dp[0] = 0, dp[1] = 1
//dp[i] = (dp[i - 1] + 1) * (1 - p) * (1 - p)
//dp[i] = (dp[i - 1] + 1)* (1 - p) + (dp[i - 2] + 1) * p

//dp[i][0]选择最后一个操作为2的期望次数
//dp[i][1]最后一个操作为1的期望次数

//dp[i][0] = (dp[i - 1][0] + 1) * q * q + (dp[i - 1][1] + 1) * q * (1 - q) + (dp[i - 2][0] + 1) * q + (dp[i - 2][1] + 1) * q;

