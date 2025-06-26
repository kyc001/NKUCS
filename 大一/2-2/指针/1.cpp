#include<bits/stdc++.h>
using namespace std;
int a, b;
void Swap(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> a >> b;
    Swap(&a, &b);
    cout << a << " " << b << endl;
    return 0;
}