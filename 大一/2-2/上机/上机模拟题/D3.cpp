#include <iostream>
#include <string>
#include <stdexcept> // 用于抛出异常

// 类模板定义
template <typename T>
class MyStack {
private:
    T* data;        // 指向动态分配数组的指针
    int top_index;  // 栈顶索引
    int capacity;   // 栈的当前容量

    // 动态扩容函数
    void resize() {
        // 创建一个容量是原来两倍的新数组
        int new_capacity = capacity * 2;
        T* new_data = new T[new_capacity];

        // 将旧数组的元素复制到新数组
        for (int i = 0; i < capacity; ++i) {
            new_data[i] = data[i];
        }

        // 释放旧数组的内存
        delete[] data;

        // 更新成员变量
        data = new_data;
        capacity = new_capacity;
    }

public:
    // 构造函数，设定一个初始容量
    MyStack(int initial_capacity = 2) {
        capacity = initial_capacity;
        data = new T[capacity];
        top_index = -1; // -1 表示栈为空
    }

    // 析构函数，释放动态分配的内存
    ~MyStack() {
        delete[] data;
    }

    // 判断栈是否为空
    bool isEmpty() const {
        return top_index == -1;
    }

    // 入栈操作
    void push(T value) {
        // 如果栈已满（栈顶索引等于容量减一），则进行扩容
        if (top_index == capacity - 1) {
            resize();
        }
        top_index++;
        data[top_index] = value;
    }

    // 出栈操作
    T pop() {
        if (isEmpty()) {
            // 在实际工程中，抛出异常比直接输出错误信息更好
            throw std::runtime_error("Error: Stack is empty.");
        }
        T value = data[top_index];
        top_index--;
        return value;
    }

    // 查看栈顶元素
    T peek() const {
        if (isEmpty()) {
            throw std::runtime_error("Error: Stack is empty.");
        }
        return data[top_index];
    }
};

// 用于处理一种类型操作的函数
template<typename T>
void process_stack_operations() {
    int n;
    std::cin >> n;

    MyStack<T> stack;
    std::string command;
    T value;

    for (int i = 0; i < n; ++i) {
        std::cin >> command;
        try {
            if (command == "push") {
                std::cin >> value;
                stack.push(value);
            } else if (command == "pop") {
                std::cout << stack.pop() << std::endl;
            } else if (command == "peek") {
                std::cout << stack.peek() << std::endl;
            }
        } catch (const std::runtime_error& e) {
            std::cout << e.what() << std::endl;
        }
    }
}

int main() {
    // 禁用C++流与C标准流的同步，提高IO效率
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // 处理int类型的栈操作
    process_stack_operations<int>();

    // 处理string类型的栈操作
    process_stack_operations<std::string>();

    return 0;
}
