#include <bits/stdc++.h>

using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<long long> pre(n + 1, 0);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    auto gao = [&](int len){
        --len;
        return pre[len / 2] + pre[len - len / 2];
    };

    vector<long long> dp(n + 1, 0);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            dp[i] = max(dp[i], dp[i - j] + gao(j));
        }
    }
    cout << dp[n] << endl;
}


