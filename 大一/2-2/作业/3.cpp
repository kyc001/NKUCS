#include<bits/stdc++.h>
using namespace std;

// 基类：Distance
class Distance {
protected:
    int x1, y1, x2, y2;
public:
    Distance(int x1, int y1, int x2, int y2) 
        : x1(x1), y1(y1), x2(x2), y2(y2) {}
    
    // 纯虚函数：计算距离
    virtual int calculate() const = 0;
    
    // 虚析构函数确保正确释放派生类对象
    virtual ~Distance() {}
};

// 派生类：曼哈顿距离
class ManhattanDistance : public Distance {
public:
    ManhattanDistance(int x1, int y1, int x2, int y2) 
        : Distance(x1, y1, x2, y2) {}
    
    int calculate() const override {
        return abs(x1 - x2) + abs(y1 - y2);
    }
};

// 派生类：欧几里得距离的平方
class EuclideanDistance : public Distance {
public:
    EuclideanDistance(int x1, int y1, int x2, int y2) 
        : Distance(x1, y1, x2, y2) {}
    
    int calculate() const override {
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    }
};

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    
    // 使用基类指针指向动态分配的派生类对象
    Distance* manhattan = new ManhattanDistance(x1, y1, x2, y2);
    Distance* euclidean = new EuclideanDistance(x1, y1, x2, y2);
    
    // 通过基类指针调用虚函数实现动态联编
    cout << manhattan->calculate() << " " << euclidean->calculate() << endl;
    
    // 手动释放内存，防止内存泄漏
    delete manhattan;
    delete euclidean;
    
    return 0;
}
