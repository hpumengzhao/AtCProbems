#include<iostream>
#include<vector>
using namespace std;
const int mod = 998244353;
long long qpow(long long a, long long b){
    long long ans = 1;
    while(b){
        if(b & 1) ans = (ans * a) % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans % mod;
}
int main(){
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    vector<long long> dp(n + 1);
    vector<long long> suf(n + 2, 0);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    dp[n] = 0;
    for(int i = n - 1; i >= 1; --i){
        long long up = (suf[i + 1] - suf[a[i] + i + 1] + mod) % mod;
        long long p = up * qpow(a[i] + 1, mod - 2) % mod;
        p += 1;
        p %= mod;
        long long q = (a[i] + 1) * qpow(a[i], mod - 2) % mod;
        dp[i] = (p * q) % mod;
        suf[i] = suf[i + 1] + dp[i];
        suf[i] %= mod;
    }
    cout << dp[1]  << endl;
}