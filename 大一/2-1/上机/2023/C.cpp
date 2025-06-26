#include <bits/stdc++.h>
using namespace std;

int n;
unsigned long long ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while (cin >> n) {
        int t;
        if(n%2) t = 2;
        else t = -2;
        ans = (1LL << (n - 1)) + t;
        cout << ans << endl;
    }
    return 0;
}
