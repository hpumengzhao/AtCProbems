#include<iostream>


using namespace std;
const long long N  = 2002;
long long dp[N][N][2][2];
long long r[N], c[N];
long long n, m;
char maze[N][N];
void make_min(long long &x, long long y){
    x = min(x, y);
}
int main(){
    cin >> n >> m;
    for(long long i = 1; i <= n; i++) cin >> r[i];
    for(long long j = 1; j <= m; j++) cin >> c[j];
    for(long long i = 1; i <= n; i++){
        for(long long j = 1; j <= m; j++){
            cin >> maze[i][j];
            maze[i][j] -= '0';
        }
    }
    for(long long i = 0; i <= n; i++){
        for(long long j = 0; j <= m; j++){
            for(long long k = 0; k < 2; k++){
                for(long long d = 0; d < 2; d++){
                    dp[i][j][k][d] = 1e18;
                }
            }
        }
    }
    dp[1][1][0][0] = 0;
    dp[1][1][1][0] = r[1];
    dp[1][1][0][1] = c[1];
    dp[1][1][1][1] = r[1] + c[1];
    for(long long i = 1; i <= n; i++){
        for(long long j = 1; j <= m; j++){
            for(long long k = 0; k < 2; k++){
                for(long long d = 0; d < 2; d++){
                    dp[i][j][k][d] = min(dp[i][j][k][d], dp[i - 1][j][k ^ maze[i][j] ^ maze[i - 1][j]][d] + k * r[i]);
                    dp[i][j][k][d] = min(dp[i][j][k][d], dp[i][j - 1][k][d ^ maze[i][j] ^ maze[i][j - 1]] + d * c[j]);
                }
            }
        }
    }
    long long ans = 1e18;
    for(long long i = 0; i < 2; i++){
        for(long long j = 0; j < 2; j++){
            ans = min(ans, dp[n][m][i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}