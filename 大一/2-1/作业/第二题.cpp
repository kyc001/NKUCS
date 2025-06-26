#include<bits/stdc++.h>
using namespace std;
int n, m, a[150];
bool is_prime(int x) {
    if(x < 2) return false;
    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0) return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> m >> n;
    for(int i = 1; i <= m*n; i ++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n * m);
    for (int i = 1; i <= n * m; i ++)
    {
        if(is_prime(a[i])) {
            cout << (i - 1) / n + 1 << " " << i - ((i-1)/n)*n<< endl;
            return 0;
        }
    }
    return 0;
}