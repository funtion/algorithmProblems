#include <iostream>
using namespace std;
class A
{
public:
    A(){cout << "构造函数执行!" << endl;};
    ~A(){cout << "析构函数执行!" << endl;}
    A(const A&z){x = z.x;cout << "复制构造函数执行!" << endl;}
    A(int y){x = y; cout << "带参数构造函数执行!" << endl;}
    void set(int i)
    {
        x = i;
    }
    int get() const
    {
        return x;
    }
    A&  operator++()  //前自加
    {
        ++x;
        return *this;
    }
    A const operator++(int cc) //后自加
    {
        A temp(*this);
        x++;
        return temp;
    }
protected:
private:
    int x;
};
int main()
{
    A a(1);
    a.set(1);
    A z = a++;//a++;

    //cout << z.get() << endl;
    cout << a.get() << endl;
    return 0;
}
