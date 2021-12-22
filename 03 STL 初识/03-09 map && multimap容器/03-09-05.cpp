//
// Created by Jarson's mac on 2021/12/22.
//
#include <iostream>
using namespace std;
#include <map>
#include <string>

//map容器 排序

//仿函数1
class MyCompare
{
public:
    bool operator() (int v1, int v2)
    {
        //降序
        return v1 > v2;
    }
};

void test01()
{
    map<int, int, MyCompare> m;
    m.insert(make_pair(4, 40));
    m.insert(make_pair(1, 10));
    m.insert(make_pair(6, 60));
    m.insert(make_pair(2, 20));
    m.insert(make_pair(3, 30));
    m.insert(make_pair(5, 50));
    //降序排列
    for(map<int, int, MyCompare>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key = " << (*it).first << "   value = " << (*it).second << endl;
    }
    cout << endl;
}

//自定义数据类型
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

//仿函数2
class compare
{
public:
    bool operator()(const Person &p1, const Person &p2)
    {
        //按照年龄降序排列
        return p1.m_Age > p2.m_Age;
    }
};

void test02()
{
    map<Person, int, compare> m;
    //准备数据
    Person p1("刘备", 24);
    Person p2("关羽", 28);
    Person p3("张飞", 25);
    Person p4("赵云", 21);

    m.insert(make_pair(p1, p1.m_Age));
    m.insert(make_pair(p2, p2.m_Age));
    m.insert(make_pair(p3, p3.m_Age));
    m.insert(make_pair(p4, p4.m_Age));

    for(map<Person, int, compare>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "姓名为： " << (*it).first.m_Name << "   年龄为： " << (*it).second << endl;
    }
    cout << endl;
}

int main()
{
    test01();
    //key = 6   value = 60
    //key = 5   value = 50
    //key = 4   value = 40
    //key = 3   value = 30
    //key = 2   value = 20
    //key = 1   value = 10
    test02();
    //姓名为： 关羽   年龄为： 28
    //姓名为： 张飞   年龄为： 25
    //姓名为： 刘备   年龄为： 24
    //姓名为： 赵云   年龄为： 21
    return 0;
}
