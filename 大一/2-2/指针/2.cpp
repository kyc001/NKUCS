#include<bits/stdc++.h>
using namespace std;
const int N = 1000 + 10;
int n, a[N];
int *p, temp = INT_MIN;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] > temp) {
            temp = a[i];
            p = &a[i];
        }
    }
    cout << *p;
    return 0;
}