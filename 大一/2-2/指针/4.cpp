#include<bits/stdc++.h>
using namespace std;
int n;
int *p;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n;
    p = new int[n];
    for(int i = 0; i < n; i ++) {
        cin >> p[n - 1 - i];
    }
    for(int i = 0; i < n; i ++) {
        cout << p[i] << " ";
    }
    return 0;
}