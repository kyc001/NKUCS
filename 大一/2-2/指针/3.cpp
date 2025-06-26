#include<bits/stdc++.h>
using namespace std;
char *p;
string s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    getline(cin, s);
    p = &s[0];
    for(int i = 0; i < s.size(); i ++) {
        if(*(p + i) >= 'a' && *(p + i) <= 'z') {
            *(p + i) = *(p + i) - 'a' + 'A';
        }
    }
    cout << p;
    return 0;
}