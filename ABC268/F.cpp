#include<bits/stdc++.h>

using namespace std;

long long cal(string s){
	int n = (int)s.size();
	vector<int> pre(n + 1);
	for(int i = 0; i < n; i++){
		if(s[i] == 'X') pre[i + 1] = pre[i] + 1;
		else pre[i + 1] = pre[i];
	}

	long long ans = 0;
	for(int i = 0; i < n; i++){
		if(s[i] != 'X') ans += (s[i] - '0') * pre[i];
	}
	return ans;
}

int main(){
	int n;
	cin >> n;
	vector<string> s(n);
	for(int i = 0; i < n; i++) cin >> s[i];

	sort(s.begin(), s.end(), [&](string &a, string &b){
		return cal(a + b) > cal(b + a);
	});
	
	string ans = "";
	for(auto &v: s) ans += v;
	cout << cal(ans) << endl;
}