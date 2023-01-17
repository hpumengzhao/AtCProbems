#include <iostream>
#include <vector>
const int INF = 1e9 + 7;
int main(){
	int H, W;
	std::cin >> H >> W;

	std::vector<std::vector<int> > m(H + 1, std::vector<int>(W + 1));
	for(int i = 1; i <= H; i++){
		for(int j = 1; j <= W; j++){
			std::cin >> m[i][j];
		}
	}

	std::vector<std::vector<std::vector<int>>> dp(H + 1, std::vector<std::vector<int>>(2, std::vector<int>(2, INF)));	

	dp[1][0][0] = 0;
	dp[1][1][0] = 1;

	for(int i = 2; i <= H; i++){
		for(int j = 0; j < 2; j++){
			for(int k = 0; k < 2; k++){
				for(int l = 0; l < 2; l++){
					std::vector<int> ai(W + 1, -1), bi(W + 1, -1), ci(W + 1, -1);
					if(j){
						for(int c = 1; c <= W; c++) ci[c] = 1 - m[i][c];
					}else{
						for(int c = 1; c <= W; c++) ci[c] = m[i][c];
					}
					if(k){
						for(int c = 1; c <= W; c++) bi[c] = 1 - m[i - 1][c];
					}else{
						for(int c = 1; c <= W; c++) bi[c] = m[i - 1][c];
					}

					if(i > 2){
						if(l) for(int c = 1; c <= W; c++) ai[c] = 1 - m[i - 2][c];
						else  for(int c = 1; c <= W; c++) ai[c] = m[i - 2][c];
					}

					bool ck = true;
					for(int c = 1; c <= W; c++){
						if(ci[c] != bi[c] && bi[c] != ai[c] && (c == 1 || bi[c] != bi[c - 1]) && (c == W || bi[c] != bi[c + 1])){
							ck = false;
							break;
						}
					}

					if(i == H){
						for(int c = 1; c <= W; c++){
							if(ci[c] != bi[c] && (c == 1 || ci[c] != ci[c - 1] && (c == W || ci[c] != ci[c + 1]))){
								ck = false;
								break;
							}
						}
					}

					if(ck){
						dp[i][j][k] = std::min(dp[i][j][k], dp[i - 1][k][l] + j);
					}
				}
			}
		}
	}
	int ans = INF;
	for(int j = 0; j < 2; j++){
		for(int k = 0; k < 2; k++){
			ans = std::min(ans, dp[H][j][k]);
		}
	}
	if(ans == INF) ans = -1;
	std::cout << ans << '\n';
}
