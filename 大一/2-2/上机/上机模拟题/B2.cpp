#include<bits/stdc++.h>
#define nullptr 0
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

class List{
public:
    Node* head;
    List() : head(nullptr) {} 
    ~List() {
        clear();
    } 
    
    void create() {
        clear();
        Node dummy(0);
        Node* current = &dummy;
        int val;
        while(cin >> val && val != -1) {
            current->next = new Node(val);
            current = current->next;
        } 
        head = dummy.next;
    }
    
    // 改为静态方法
    static List merge(List& list1, List& list2) {
        List res;
        Node dummy(0);
        Node* current = &dummy;
        Node* l1 = list1.head;
        Node* l2 = list2.head;
        
        while(l1 && l2) {
            if(l1->val <= l2->val) {
                current->next = l1;
                l1 = l1->next;
            }
            else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next; 
        }
        
        if(l1 != nullptr) {
            current->next = l1;
        }
        else {
            current->next = l2;
        }
        
        res.head = dummy.next;
        // 重要：防止原链表析构时释放节点
        list1.head = nullptr;
        list2.head = nullptr;
        
        return res;
    }
    
    void print() const {
        Node* current = head;
        while(current != nullptr) {
            cout << current->val;
            if(current->next != nullptr) {
                cout << ' ';
            }
            current = current->next;
        }
    } 
    
    void clear() {
        Node* temp;
        while(head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
        head = nullptr;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    List list1, list2;
    
    list1.create();
    list2.create();
    
    // 使用静态方法调用，无需再手动设置原链表head为空
    List l = List::merge(list1, list2);
    
    l.print(); 

    return 0;
}
