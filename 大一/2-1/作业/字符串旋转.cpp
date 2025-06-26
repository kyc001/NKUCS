#include<bits/stdc++.h>
using namespace std;
int n, k, len, p;
string s;
char op;
int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> s;
		len = s.size();
		p = 0;
		for(int j = len; j < len * 2; j ++) {
			s[j] = s[j - len];
		}
		cin >> op >> k;
		if(op == 'L') {
			p = k % len;
		}
		else if(op == 'R') {
			p = len - k % len;
		}
		for(int j = p; j < p + len; j ++) {
			if((j - p + 1) % 2)
				cout << s[j]; 
		} 
		cout << endl;
	}
	return 0;
}
