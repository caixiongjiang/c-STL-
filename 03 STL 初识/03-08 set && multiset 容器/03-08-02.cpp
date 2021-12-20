//
// Created by Jarson's mac on 2021/12/20.
//
#include <iostream>
using namespace std;
#include <set>

//set容器 大小和交换

void printSet(set<int> &s)
{
    for(set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

//大小
void test01()
{
    set<int> s1;
    //插入数据
    s1.insert(10);
    s1.insert(30);
    s1.insert(20);
    s1.insert(5);
    s1.insert(25);

    printSet(s1);
    //5 10 20 25 30

    //判断是否为空
    if(s1.empty())
    {
        cout << "s1为空" << endl;
    }
    else
    {
        cout << "s1不为空" << endl;
        cout << "s1的大小为：" << s1.size() << endl;//5
    }
}
//交换
void test02()
{
    set<int> s1;
    //插入数据
    s1.insert(10);
    s1.insert(30);
    s1.insert(20);
    s1.insert(5);
    s1.insert(25);

    set<int> s2;
    //插入数据
    s2.insert(100);
    s2.insert(300);
    s2.insert(200);
    s2.insert(50);
    s2.insert(250);

    cout << "交换前：" << endl;
    cout << "s1：" << endl;
    printSet(s1);
    cout << "s2：" << endl;
    printSet(s2);
    //交换前：
    //s1：
    //5 10 20 25 30
    //s2：
    //50 100 200 250 300

    s1.swap(s2);

    cout << "交换后：" << endl;
    cout << "s1：" << endl;
    printSet(s1);
    cout << "s2：" << endl;
    printSet(s2);
    //交换后：
    //s1：
    //50 100 200 250 300
    //s2：
    //5 10 20 25 30
}

int main()
{
    test01();
    test02();
    return 0;
}
