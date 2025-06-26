#include<bits/stdc++.h>
using namespace std;
int **p1, **p2;
int n, m;
void init(int n, int m) {
    p1 = new int*[n];
    p2 = new int*[n];
    for(int i = 0; i < n; i++) {
        p1[i] = new int[m];
        p2[i] = new int[m];
    }
}
void solve() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            p2[i][j] += p1[i][j];
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;;
    init(n, m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> p1[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> p2[i][j];
        }
    }
    solve();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << p2[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}