#include<bits/stdc++.h>
using namespace std;
const int maxp = 1e6 + 3;
int p[100000];
int cnt;
bool is_prime(int x) {
	for(int i = 0; i < cnt; i ++) {
		if(x % p[i] == 0)
			return 0;
	}
	return 1;
}
void init() {
	p[cnt ++] = 2;
	for(int i = 3; i < maxp; i ++) {
		if(is_prime(i)) {
			p[cnt ++] = i;
			cout << i << ", ";
		}
	}
}
int n, m;
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen(".out", "w", stdout);
	cout << "int p[80000] = {2, "; 
	init();
	cout << maxp << "};";
	return 0;
}


