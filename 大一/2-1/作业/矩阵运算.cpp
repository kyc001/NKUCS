#include<bits/stdc++.h>
using namespace std;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
int n, m, a[15][15], tag = 1, flag=0, cnt;
bool vis[15][15];
void dfs(int tx, int ty, int dir) {
	if(flag == 1) return;
	int cnt = 0;
	while(1) {
		int px = tx + dx[dir];
		int py = ty + dy[dir];
		if(!vis[px][py] && px >= 1 && px <= n && py >= 1 && py <= m) {
			vis[px][py] = 1;
			cout << a[px][py] << " ";
			dfs(px, py, dir);
		}
		dir = (dir + 1) % 4;
		cnt ++;
		if(cnt == 4) {
			flag = 1;
			return;
		}
	}
}
int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			cin >> a[i][j];
		} 
	}
	for(int i = 1; i <= n; i ++) {
		if(tag==1)
			for(int j = 1; j <= m; j ++)
				cout << a[i][j] << " ";
		else
			for(int j = m; j >= 1; j --)
				cout << a[i][j] << " ";
		tag = -tag;
	}
	cout << endl;
	cout << a[1][1] << " ";
	vis[1][1] = 1;
	dfs(1, 1, 0);
	return 0;
}
