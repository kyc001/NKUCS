//#include<bits/stdc++.h>
//using namespace std;
//template<typename T>
//class mystack{
//public:
//	T *p;
//	int num=0;
//	mystack() {
//		p = new T[1000];
//	}
//	~mystack() {
//		delete []p;
//	}
//	void push(T t) {
//		p[num ++] = t;
//	}
//	void pop() {
//		if(isempty()) return;
//		num --;
//	}
//	bool isempty() {
//		return num == 0;
//	}
//	void show() {
//		for(int i = num - 1; i >= 0; i --) {
//			cout << p[i] << ' ';
//		} 
//		cout << endl;
//	}
//};
//char op;
//int main() {
//
//	ios::sync_with_stdio(false);
//	cin.tie(0); cout.tie(0);
//
//	mystack<int> s1;
//	while(scanf("%c", &op)) {
//		if(op == '\n') break;
//		if(op == 'i') {
//			int temp;
//			cin >> temp;
//			s1.push(temp);
//		}
//		else if(op == 'o') {
//			s1.pop();
//		}
//		else if(op == 's') {
//			s1.show();
//		}
//	}
//	mystack<char> s2;
//	while(cin >> op) {
//		if(op == 'i') {
//			char temp;
//			cin >> temp;
//			s2.push(temp);
//		}
//		else if(op == 'o') {
//			s2.pop();
//		}
//		else if(op == 's') {
//			s2.show();
//		}
//	}
//
//	return 0;
//}
//
//
#include <iostream>
#include <string>
#include <sstream> // 用于解析字符串流

// 定义一个常量作为栈的默认容量
const int STACK_CAPACITY = 100;

/**
 * @brief 通用栈类模板
 * @tparam T 栈中存储的数据类型
 */
template <class T>
class MyStack {
private:
    T* data;       // 使用指针指向动态分配的数组，用于存储栈元素
    int top_index; // 栈顶元素的索引，-1表示栈空
    int capacity;  // 栈的容量

public:
    // 构造函数，可以指定容量
    MyStack(int size = STACK_CAPACITY);
    // 析构函数，释放动态分配的内存
    ~MyStack();

    // 成员函数
    void push(T value); // 入栈
    void pop();         // 出栈
    bool isEmpty();     // 判断栈是否为空
    void show();        // 显示栈内所有元素
};

/**
 * @brief 构造函数
 * @tparam T
 * @param size 栈的容量
 */
template <class T>
MyStack<T>::MyStack(int size) {
    capacity = size;
    data = new T[capacity]; // 动态分配内存
    top_index = -1;         // 初始化栈顶索引，表示栈空
}

/**
 * @brief 析构函数
 * @tparam T
 */
template <class T>
MyStack<T>::~MyStack() {
    delete[] data; // 释放动态分配的数组内存
    data = 0;
}

/**
 * @brief 判断栈是否为空
 * @tparam T
 * @return 如果栈为空则返回true，否则返回false
 */
template <class T>
bool MyStack<T>::isEmpty() {
    return top_index == -1;
}

/**
 * @brief 入栈操作
 * @tparam T
 * @param value 要入栈的元素
 */
template <class T>
void MyStack<T>::push(T value) {
    // 题目保证不会栈满，但在实际工程中应检查 top_index < capacity - 1
    top_index++;
    data[top_index] = value;
}

/**
 * @brief 出栈操作
 * @tparam T
 */
template <class T>
void MyStack<T>::pop() {
    if (isEmpty()) {
        // 按照题目要求，如果栈空则输出 "Empty"
        std::cout << "Empty" << std::endl;
        return;
    }
    top_index--; // 仅移动栈顶指针，不实际清除数据
}

/**
 * @brief 显示栈内所有元素（从栈顶到栈底）
 * @tparam T
 */
template <class T>
void MyStack<T>::show() {
    if (isEmpty()) {
        std::cout << "Empty" << std::endl;
        return;
    }
    // 从栈顶开始遍历，直到栈底
    for (int i = top_index; i >= 0; --i) {
        std::cout << data[i] << (i == 0 ? "" : " "); // 最后一个元素后不加空格
    }
    std::cout << std::endl;
}

/**
 * @brief 处理一行操作指令的通用函数
 * @tparam T 栈的数据类型 (int 或 char)
 * @param stack 要操作的栈对象
 * @param line 包含操作指令的字符串
 */
template <typename T>
void process_operations(MyStack<T>& stack, const std::string& line) {
    std::stringstream ss(line); // 创建字符串流以方便地解析字符串
    char operation_code;
    T value;

    // 逐个读取操作符
    while (ss >> operation_code) {
        switch (operation_code) {
            case 'i': // 入栈操作
                ss >> value; // 读取要入栈的元素
                stack.push(value);
                break;
            case 'o': // 出栈操作
                stack.pop();
                break;
            case 's': // 显示操作
                stack.show();
                break;
        }
    }
}

int main() {
    // 提高C++流的IO效率
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string line;

    // --- 处理第一行：整数栈 ---
    if (getline(std::cin, line)) {
        MyStack<int> int_stack;
        process_operations(int_stack, line);
    }

    // --- 处理第二行：字符栈 ---
    if (getline(std::cin, line)) {
        MyStack<char> char_stack;
        process_operations(char_stack, line);
    }

    return 0;
}

