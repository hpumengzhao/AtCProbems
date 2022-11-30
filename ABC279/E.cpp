#include <bits/stdc++.h>
//pre[i]表示执行完第i部后1在哪个位置
//last[i]表示i最后在哪个位置
using namespace std;
int a[200005];
int pos[200005];
int pre[200005];
int last[200005];
int ans[200005];
int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        pos[i] = i;
    }
    pre[0] = 1;
    for(int i = 1; i <= m; i++){
        swap(pos[a[i]], pos[a[i] + 1]);
        if(pos[a[i]] == 1){
            pre[i] = a[i];
            continue;
        }
        if(pos[a[i] + 1] == 1){
            pre[i] = a[i] + 1;
            continue;
        }
        pre[i] = pre[i - 1];
    }
    for(int i = 1; i <= n; i++){
         last[i] = i;
    }
    for(int i = m; i >= 2; --i){
        swap(last[a[i]], last[a[i] + 1]);
        ans[i - 1] = last[pre[i - 2]];
    }
    ans[m] = pre[m - 1];
    for(int i = 1; i <= m; i++){
        cout << ans[i] << endl;
    }
}