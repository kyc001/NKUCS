#include <iostream>
#include <string>
#include <sstream> // 用于字符串流构建输出

// 多项式的项（作为链表节点）
struct Term {
    int coef; // 系数
    int exp;  // 指数
    Term* next;

    Term(int c, int e) : coef(c), exp(e), next(nullptr) {}
};

class Polynomial {
private:
    Term* head;

public:
    // 构造函数
    Polynomial() : head(nullptr) {}

    // 析构函数，释放链表内存
    ~Polynomial() {
        Term* current = head;
        while (current != nullptr) {
            Term* next = current->next;
            delete current;
            current = next;
        }
    }

    // 拷贝构造函数，实现深拷贝
    Polynomial(const Polynomial& other) {
        head = nullptr;
        if (other.head == nullptr) {
            return;
        }
        Term* other_curr = other.head;
        Term* this_curr = nullptr;
        while(other_curr != nullptr) {
            Term* new_term = new Term(other_curr->coef, other_curr->exp);
            if(head == nullptr) {
                head = new_term;
                this_curr = head;
            } else {
                this_curr->next = new_term;
                this_curr = this_curr->next;
            }
            other_curr = other_curr->next;
        }
    }

    // 在链表尾部添加一项（用于构建多项式）
    void addTerm(int c, int e) {
        if (c == 0) return; // 系数为0的项不添加
        Term* new_term = new Term(c, e);
        if (head == nullptr) {
            head = new_term;
        } else {
            Term* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new_term;
        }
    }

    // 重载加法运算符
    Polynomial operator+(const Polynomial& other) const {
        Polynomial result;
        Term* p1 = this->head;
        Term* p2 = other.head;

        while (p1 != nullptr && p2 != nullptr) {
            if (p1->exp > p2->exp) {
                result.addTerm(p1->coef, p1->exp);
                p1 = p1->next;
            } else if (p1->exp < p2->exp) {
                result.addTerm(p2->coef, p2->exp);
                p2 = p2->next;
            } else { // 指数相等
                int sum_coef = p1->coef + p2->coef;
                if (sum_coef != 0) { // 系数和不为0才添加
                    result.addTerm(sum_coef, p1->exp);
                }
                p1 = p1->next;
                p2 = p2->next;
            }
        }

        // 将剩余的项添加到结果中
        while (p1 != nullptr) {
            result.addTerm(p1->coef, p1->exp);
            p1 = p1->next;
        }
        while (p2 != nullptr) {
            result.addTerm(p2->coef, p2->exp);
            p2 = p2->next;
        }
        return result;
    }

    // 友元函数，重载流插入运算符以实现格式化输出
    friend std::ostream& operator<<(std::ostream& out, const Polynomial& p);
};

std::ostream& operator<<(std::ostream& out, const Polynomial& p) {
    if (p.head == nullptr) {
        out << "0";
        return out;
    }

    Term* current = p.head;
    bool is_first_term = true;

    while (current != nullptr) {
        // --- 处理符号 ---
        if (!is_first_term) {
            if (current->coef > 0) {
                out << " + ";
            } else {
                out << " - ";
            }
        } else {
            if (current->coef < 0) {
                out << "-";
            }
        }

        // --- 处理系数 ---
        int abs_coef = std::abs(current->coef);
        if (abs_coef != 1 || current->exp == 0) {
            out << abs_coef;
        }

        // --- 处理变量x和指数 ---
        if (current->exp > 0) {
            out << "x";
            if (current->exp > 1) {
                out << "^" << current->exp;
            }
        }
        
        is_first_term = false;
        current = current->next;
    }
    return out;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    Polynomial p1, p2;
    int n, c, e;

    // 读取第一个多项式
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> c >> e;
        p1.addTerm(c, e);
    }

    // 读取第二个多项式
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> c >> e;
        p2.addTerm(c, e);
    }

    // 计算并输出结果
    Polynomial p3 = p1 + p2;
    std::cout << p3 << std::endl;

    return 0;
}
