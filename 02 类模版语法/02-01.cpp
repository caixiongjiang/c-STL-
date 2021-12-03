//
// Created by Jarson's mac on 2021/12/3.
//

#include <iostream>
using namespace std;
#include <string>

//类模版
template<class NameType, class AgeType>
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
        cout << "   name: " << this->m_Name << "   age: " << this->m_Age << endl;
    }
    NameType m_Name;
    AgeType m_Age;
};

void test01()
{
    Person<string, int> p1("孙悟空", 999);
    p1.showPerson();
}

int main()
{
    test01();
    return 0;
}