#include<bits/stdc++.h>
using namespace std;
priority_queue<int> q;
map<int, int> b;
int n, m; 
int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n + m; i ++) {
		int temp;
		cin >> temp;
		if(!b[temp]) {
			b[temp] = 1;
			q.push(-temp);
		}
	}
	while(!q.empty()) {
		int t = -q.top();
		q.pop();
		cout << t << " ";
	}
	return 0;
}
