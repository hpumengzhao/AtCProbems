#include<bits/stdc++.h>

using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> p(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> p[i];
    }
    for(int i = 1; i <= n; i++){
        if(p[i] == k){
            cout << i << endl;
            return 0;
        }
    }
}