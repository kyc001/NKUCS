#include<bits/stdc++.h>
using namespace std;
struct node {
    int val;
    node *next;
    node(int x) : val(x), next(nullptr){}
};
class List {
public:
    
    node* head;
    
    List() : head(nullptr){}

    List(int arr[],int l) {
        node* dummy = new node(0);
        node* current = dummy;
        for(int i = 0; i < l; i ++) {
            current->next = new node(arr[i]);
            current = current -> next;
        }

        head = dummy->next;
        delete dummy;
    }

    static node* rever(node* h) {
        node* prev = nullptr;
        node* curr = h;
        while(curr != nullptr) {
            node* temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    node* operator+ (List& b) {
        node* bc = rever(b.head);
        node* ac = rever(head);
        node* dummy = new node(0);
        node *curr = dummy;
        int carry = 0;
        while(ac!=nullptr || bc!=nullptr || carry != 0) {
            int val1 = (ac != nullptr) ? ac -> val : 0;
            int val2 = (bc != nullptr) ? bc -> val : 0;

            int sum = val1 + val2 + carry;
            carry = sum / 10;
            
            curr->next = new node(sum % 10);
            curr = curr->next;
            
            if (ac != nullptr) ac = ac->next;
            if (bc != nullptr) bc = bc->next;
        }
        curr = dummy -> next;
        delete dummy;
        return curr;
    }
    void show() {
        node* curr = head;
        while(curr != nullptr) {
            cout << curr -> val << ' ';
            curr = curr->next;
        }
        return;
    }
    ~List() {
        clear();
    }
    void clear() {
        node *curr = head;
        while(curr != nullptr) {
            node *temp = curr;
            curr = curr->next;
            delete temp;
        }
        head = nullptr;
    }
};
string s;
int a[1000], len;
void solve() {
    len = 0;
    for(int i = 0; i < s.size(); i ++) {
        int temp = 0, tag = 0;
        if(!(s[i] >= '0' && s[i] <= '9')) continue;
        while(s[i] >= '0' && s[i] <= '9' && i < s.size()) {
            temp = temp * 10 + s[i] - '0';
            i ++;
            tag = 1;
        }
        if(tag==1) a[len ++] = temp;
    }
}
/*
1 2 3
4 5 6
*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    getline(cin, s);
    solve();
    List l1(a, len);

    getline(cin, s);
    solve();
    List l2(a, len);

    List l3;
    l3.head = l1 + l2;
    l3.show();

    return 0;
}
