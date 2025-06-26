#include <bits/stdc++.h>
using namespace std;

// 双向链表节点结构体
struct Node {
    int val;            // 好友ID
    Node* prev;         // 前驱节点
    Node* next;         // 后继节点
    Node(int x) : val(x), prev(nullptr), next(nullptr) {}
};

// 聊天列表管理器
class ChatManager {
private:
    unordered_map<int, Node*> map;  // 哈希表：ID到节点的映射
    Node* head;                     // 链表头（最新节点）
    Node* tail;                     // 链表尾（最旧节点）

public:
    ChatManager() {
        head = tail = nullptr;
    }

    // 将节点移动到链表头部
    void moveToHead(Node* node) {
        if (node == head) return;  // 已经在头部无需操作
        
        // 断开当前节点的前后连接
        if (node->prev) node->prev->next = node->next;
        if (node->next) node->next->prev = node->prev;
        
        // 如果节点是尾节点，更新尾节点
        if (node == tail) tail = node->prev;
        
        // 插入到头部
        node->prev = nullptr;
        node->next = head;
        if (head) head->prev = node;
        head = node;
        
        // 如果原本链表为空，插入后尾节点也是该节点
        if (!tail) tail = head;
    }

    // 添加新节点到头部
    void addNewToHead(int val) {
        Node* newNode = new Node(val);
        map[val] = newNode;
        
        if (!head) {  // 空链表
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // 处理一条消息
    void processMessage(int id) {
        if (map.count(id)) {  // ID存在，移动到头部
            moveToHead(map[id]);
        } else {  // ID不存在，新增到头部
            addNewToHead(id);
        }
    }

    // 获取当前列表顺序（从头部到尾部）
    vector<int> getList() {
        vector<int> res;
        Node* curr = head;
        while (curr) {
            res.push_back(curr->val);
            curr = curr->next;
        }
        return res;
    }

    // 释放内存（防止内存泄漏）
    ~ChatManager() {
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int T;
        cin >> T;
        ChatManager cm;
        for (int j = 0; j < T; ++j) {
            int id;
            cin >> id;
            cm.processMessage(id);
        }
        vector<int> list = cm.getList();
        for (size_t k = 0; k < list.size(); ++k) {
            cout << list[k];
            if (k != list.size() - 1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}
