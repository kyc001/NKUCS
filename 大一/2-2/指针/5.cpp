#include<bits/stdc++.h>
using namespace std;
string s;
char *p;
bool tag = false;
int num;
bool check(char c) {
    if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') return true;
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    getline(cin, s);
    p = &s[0];
    for(int i = 0; i < s.size(); i ++) {
        while(check(p[i])) {
            i ++;
            tag = true;
        }
        num += tag;
        tag = false;
    }
    cout << num << endl;
    return 0;
}