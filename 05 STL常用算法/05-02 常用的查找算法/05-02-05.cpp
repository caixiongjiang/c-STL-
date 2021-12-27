//
// Created by Jarson's mac on 2021/12/27.
//
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>

//常用查找算法 count

//1.统计内置数据类型

void test01()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(40);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(20);

    int num = count(v.begin(), v.end(), 40);
    cout << "40的元素个数为：" << num << endl;
}
//2.统计自定义数据类型

class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    //重载== 让底层知道count如何对比
    bool operator==(const Person & p)//必须要加const防止修改底层
    {
        return this->m_Age == p.m_Age;
    }
    string m_Name;
    int m_Age;
};

void test02()
{
    vector<Person> v;
    Person p1("刘备", 35);
    Person p2("关羽", 35);
    Person p3("张飞", 35);
    Person p4("赵云", 30);
    Person p5("曹操", 40);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    Person p("诸葛亮", 35);

    int num = count(v.begin(), v.end(), p);
    cout << "和诸葛亮同岁数的人员个数为" << num << endl;
}

int main()
{
    test01();
    //40的元素个数为：3
    test02();
    //和诸葛亮同岁数的人员个数为3
    return 0;
}
