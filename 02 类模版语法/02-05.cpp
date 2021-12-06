//
// Created by Jarson's mac on 2021/12/6.
//

#include <iostream>
using namespace std;

//类模版与继承
template<class T>
class Base
{
    T m;
};

//class Son : public Base  //错误，必须知道父类中的T类型，才能继承给子类
class Son : public Base<int>
{

};

void test01()
{
    Son s1;
}

//如果像灵活指定父类中T的类型，那么子类也需要变为一个类模板
template<class T1, class T2>
class Son2 : public Base<T2>
{
public:
    Son2()
    {
        cout << "T1的类型为：" << typeid(T1).name() << endl;
        cout << "T2的类型为：" << typeid(T2).name() << endl;
    }
    T1 obj;
};

void test02()
{
    Son2<int, char> S2;
}

int main()
{
    test02();
    return 0;
}
