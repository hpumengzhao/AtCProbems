#include<bits/stdc++.h>

using namespace std;
const int INF  = 1e9;
int a[3001];
int dp[3001][3001][2];//dp[i][j][k]
int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= m; j++){
			for(int k = 0; k < 2; k++) dp[i][j][k] = 1e9;
		}
	}
	for(int i = 1; i <= n; i++) dp[i][0][0] = 1;
	dp[1][a[1]][1] = 0;
	dp[1][0][0]= 1;
	for(int i = 2; i <= n; i++){
		for(int j = 1; j <= m; j++){
			dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][0]);
			dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][1] + 1);
			if(j >= a[i]) dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j - a[i]][0]);
			if(j >= a[i]) dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j - a[i]][1]);
		}
	}

	for(int j = 1; j <= m; j++){
		int ans = 1e9;
		ans = min(ans, dp[n][j][0]);
		ans = min(ans, dp[n][j][1]);
		cout << (ans == 1e9 ? -1 : ans) << endl;
	}
}