#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<string> s(n);

    for(int i = 0; i < n; i++){
        cin >> s[i];
    }

    vector<vector<bool> > dp(1 << n, vector<bool>(26, false));
    for(int i = 0; i < 26; i++) dp[0][i] = false;
    for(int S = 1; S < (1 << n); S++){
        for(int j = 0; j < n; j++){
            if((S >> j) & 1){//s[j]可用
                char first = s[j][0];
                char last = s[j][(int)s[j].size() - 1];
                if(!dp[S ^ (1 << j)][last - 'a']){
                    dp[S][first - 'a'] = true;
                }
            }
        }
    }
    for(int j = 0; j < 26; j++){
        if(dp[(1 << n) - 1][j]){
            cout << "First\n";
            return 0;
        }
    }
    cout << "Second\n";
}