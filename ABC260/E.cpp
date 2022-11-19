#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    vector<vector<int> >  pos(m + 1);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        pos[a[i]].push_back(i);
        pos[b[i]].push_back(i);
    }
    int satisfy = 0;
    vector<int> used(n + 2, 0);
    vector<int> ans(m + 2);
    for(int L = 1, R = 1; L <= m;){
        while(R <= m && satisfy != n){
            for(int &v: pos[R]){
                if(used[v] == 0) ++satisfy;
                used[v]++;
            }
            R++;
        }
        if(satisfy != n) break;
        ans[R - L]++;
        ans[m + 1 - L + 1]--;
        for(int &v: pos[L]){
            --used[v];
            if(used[v] == 0) --satisfy;
        }
        L++;
    }
    for(int i = 1; i <= m; i++) ans[i] += ans[i - 1];
    for(int i = 1; i <= m; i++){
        cout << ans[i] << ' ';
    }
    cout << endl;
}