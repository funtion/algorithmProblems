#include <iostream>
using namespace std;
class A
{
public:
    A(){cout << "���캯��ִ��!" << endl;};
    ~A(){cout << "��������ִ��!" << endl;}
    A(const A&z){x = z.x;cout << "���ƹ��캯��ִ��!" << endl;}
    A(int y){x = y; cout << "���������캯��ִ��!" << endl;}
    void set(int i)
    {
        x = i;
    }
    int get() const
    {
        return x;
    }
    A&  operator++()  //ǰ�Լ�
    {
        ++x;
        return *this;
    }
    A const operator++(int cc) //���Լ�
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
