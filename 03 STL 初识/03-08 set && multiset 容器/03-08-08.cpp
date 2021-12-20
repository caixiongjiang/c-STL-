//
// Created by Jarson's mac on 2021/12/20.
//
#include <iostream>
using namespace std;
#include <set>
#include <string>

//set容器存放自定义数据类型如何指定排序规则

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

class compare
{
public:
    //仿函数必须传入固定值，如果不是就用const将其转换为固定值
    bool operator()(const Person &p1, const Person &p2)
    {
        //按照年龄降序排列
        return p1.m_Age > p2.m_Age;
    }
};

void test01()
{
    //自定义的数据类型 都会指定排序规则
    set<Person, compare> s;
    //创建Person对象
    Person p1("刘备", 24);
    Person p2("关羽", 28);
    Person p3("张飞", 25);
    Person p4("赵云", 21);

    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);

    cout << "按照年龄降序排列：" << endl;
    for(set<Person, compare>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << "姓名：" << (*it).m_Name << "   年龄：" << (*it).m_Age << endl;
    }

}

int main()
{
    test01();
    //按照年龄降序排列：
    //姓名：关羽   年龄：28
    //姓名：张飞   年龄：25
    //姓名：刘备   年龄：24
    //姓名：赵云   年龄：21
    return 0;
}
