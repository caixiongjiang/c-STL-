//
// Created by Jarson's mac on 2021/12/27.
//
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>
//常用的查找算法
//find

//查找 内置数据类型
void test01()
{
    vector<int> v;
    for(int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    //查找 容器中是否有5这个元素
    vector<int>::iterator it = find(v.begin(), v.end(), 5);
    if(it == v.end())
    {
        cout << "没有找到！" << endl;
    }
    else
    {
        cout << "找到：" << *it << endl;
    }
}

//查找自定义数据类型

class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    //重载==  底层find知道如何对比Person数据类型
    bool operator==(const Person &p)
    {
        if(this->m_Name == p.m_Name && this->m_Age == this->m_Age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    string m_Name;
    int m_Age;
};

void test02()
{
    vector<Person> v;
    //创建数据
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);

    //放入到容器中
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    Person pp("ddd", 40);

    vector<Person>::iterator it = find(v.begin(), v.end(), pp);
    if(it == v.end())
    {
        cout << "没有找到！" << endl;
    }
    else
    {
        cout << "找到元素 姓名：" << it->m_Name << "   年龄：" << it->m_Age << endl;
    }
}

int main()
{
    test01();
    //找到：5
    test02();
    return 0;
}
