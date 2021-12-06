//
// Created by Jarson's mac on 2021/12/6.
//

#include <iostream>
using namespace std;

//类模版中成员函数创建的时机
//类模版成员函数在调用时才去创建

class Person1
{
public:
    void showPerson1()
    {
        cout << "Person1 show" << endl;
    }
};

class Person2
{
public:
    void showPerson2()
    {
        cout << "Person2 show" << endl;
    }
};
//没有调用之前不会报错

template<class T>
class Myclass
{
public:
    T obj;
    //类模版中的成员函数
    void func1()
    {
        obj.showPerson1();
    }
    void func2()
    {
        obj.showPerson2();
    }
};

void test01()
{
    Myclass<Person1> m;
    //以下两段代码只能运行一段
    m.func1();
    //m.func2();
}

int main()
{
    test01();
    return 0;
}