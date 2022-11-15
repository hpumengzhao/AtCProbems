#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> str(n);
    set<string> all;
    for(int i = 0; i < n; i++){
        cin >> str[i];
        all.insert(str[i]);
    }

    function<bool(string)> check = [&](string s){
        if(!(s[0] == 'H' || s[0] == 'D' || s[0] == 'C' || s[0] == 'S')){
            return false;
        }
        if(!((s[1] >= '2' && s[1] <= '9')|| s[1] == 'A' || s[1] == 'T' || s[1] == 'J' || s[1] == 'Q' || s[1] == 'K')){
            return false;
        }
        return true;
    };
    for(int i = 0; i < n; i++){
        if(!check(str[i])){
            
            cout << "No\n";
            return 0;
        }
    }
    if((int)all.size() != n){
        cout << "No\n";
    }else{
        cout << "Yes\n";
    }
    return 0;
}