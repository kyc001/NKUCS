#include<bits/stdc++.h>
using namespace std;
int n, temp;
int *p1, *p2, t1, t2;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n;
    p1 = new int[n];
    p2 = new int[n];
    for(int i = 0; i < n; i ++) {
        cin >> temp;
        if(temp % 2 == 0) {
            p1[t1++] = temp;
        } else {
            p2[t2++] = temp;
        }
    }
    for(int i = 0; i < t1; i ++) {
        cout << p1[i] << " ";
    }
    for(int i = 0; i < t2; i ++) {
        cout << p2[i] << " ";
    }
    return 0;
}