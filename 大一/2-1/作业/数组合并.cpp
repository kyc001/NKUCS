#include<bits/stdc++.h>
using namespace std;
const int N = 100 + 10;
int n, m, a[N], b[N], p1 = 1, p2 = 1;
bool cmp(int x, int y) {
	return x < y;
}
int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	for(int i = 1; i <= m; i ++) {
		cin >> b[i];
	}
	sort(a + 1, a + 1 + n, cmp);
	sort(b + 1, b + 1 + m, cmp);
	while(p1 <= n || p2 <= m) {
		if(a[p1] < b[p2]) {
			cout << a[p1] << " ";
			while(a[p1 + 1] == a[p1]) p1 ++;
			p1 ++;
		}
		else if(a[p1] > b[p2]) {
			cout << b[p2] << " ";
			while(b[p2 + 1] == b[p2]) p2 ++;
			p2 ++;
		}
		else if(a[p1] == b[p2]){
			cout << a[p1] << " ";
			while(a[p1 + 1] == a[p1]) p1 ++;
			while(b[p2 + 1] == b[p2]) p2 ++;
			p1 ++, p2 ++;
		}
	}
	return 0;
}
