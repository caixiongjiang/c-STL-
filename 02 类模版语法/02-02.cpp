//
// Created by Jarson's mac on 2021/12/6.
//

#include <iostream>
#include <string>
using namespace std;

//类模版与函数模版的区别
template<class NameType, class AgeType = int>
class Person
{
public:
    Person(NameType name, AgeType age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    void showPerson()
    {
        cout << "name: " << this->m_Name << "   age= " << this->m_Age << endl;
    }

    NameType m_Name;
    AgeType m_Age;
};

//1.类模版没有自动类型推导的使用方式
void test01()
{
    //Person p("孙悟空", 1000);  错误，无法使用自动类型推导
    Person<string, int>p("孙悟空", 1000);//正确，只能用显示指定类型
    p.showPerson();
}
//2.类模版在模版的参数列表中可以有默认参数
void test02()
{
    Person<string>p("猪八戒", 999);//AgeType默认为int类型，可以省略；注意，这中用法只能在类模版中使用！
    p.showPerson();
}

int main()
{
    test01();
    test02();
    return 0;
}