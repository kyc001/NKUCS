#include<bits/stdc++.h>
using namespace std;
class account{
public:
    double balance;
    account(double x) : balance(x){}
    virtual void withdraw(double amount) = 0;
};
class savingaccount : public account {
public:
    savingaccount(double x) : account(x){}
    void withdraw(double x) {
        if(x > balance) {
            cout << fixed << setprecision(2) << "Failed, balance: " << balance << endl;
        }
        else {
            balance -= x;
            cout << fixed << setprecision(2) << "Success, balance: " << balance << endl;
        }
    }
};
class creditaccount : public account {
public:
    creditaccount(double x) : account(x){}
    void withdraw(double x) {
        if(x > balance) {
            balance = balance - x - (x - balance) * 0.1;
            cout << fixed << setprecision(2) << "Success, balance: " << balance << endl;
        }
        else {
            balance -= x;
            cout << fixed << setprecision(2) << "Success, balance: " << balance << endl;
        }
    }
};
int n;
char op;
double x, y;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i ++) {
        cin >> op;
        if(op == 's') {
            cin >> x >> y;
            savingaccount s(x);
            s.withdraw(y);
        }
        else {
            cin >> x >> y;
            creditaccount s(x);
            s.withdraw(y);
        }
    }

    return 0;
}