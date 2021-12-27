//
// Created by Jarson's mac on 2021/12/27.
//
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>

//常用查找算法 find_if

//1.查找内置数据类型

class GreaterFive
{
public:
    bool operator()(int val)
    {
        return val > 5;
    }
};

void test01()
{
    vector<int> v;
    for(int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    vector<int>::iterator  it = find_if(v.begin(), v.end(), GreaterFive());

    if(it == v.end())
    {
        cout << "没有找到" << endl;
    }
    else
    {
        cout << "找到大于5的数字：" << *it << endl;
    }
}

//2.查找自定义的数据类型

class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    string m_Name;
    int m_Age;
};

class Greater20
{
public:
    bool operator()(Person &p)
    {
        return p.m_Age > 20;
    }
};

void test02()
{
    vector<Person> v;
    //创建数据
    Person p1("a", 10);
    Person p2("b", 20);
    Person p3("c", 30);
    Person p4("d", 40);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    //查找年龄大于20的人
    vector<Person>::iterator it = find_if(v.begin(), v.end(), Greater20());

    if(it == v.end())
    {
        cout << "没有找到" << endl;
    }
    else
    {
        cout << "找到姓名：" << it->m_Name << "  年龄：" << it->m_Age << endl;
    }
}

int main()
{
    test01();
    //找到大于5的数字：6
    test02();
    //找到姓名：c  年龄：30
    return 0;
}