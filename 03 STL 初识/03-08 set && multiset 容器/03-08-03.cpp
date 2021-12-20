//
// Created by Jarson's mac on 2021/12/20.
//
#include <iostream>
using namespace std;
#include <set>

//set容器 插入和删除

void printSet(set<int> &s)
{
    for(set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    set<int> s1;
    //插入数据 只有insert的方式
    s1.insert(10);
    s1.insert(40);
    s1.insert(20);
    s1.insert(30);

    printSet(s1);
    //10 20 30 40

    //删除
    s1.erase(s1.begin());
    printSet(s1);
    //20 30 40

    //删除重载版本
    s1.erase(30);
    printSet(s1);
    //20 40

    //清空
    s1.erase(s1.begin(), s1.end());
    s1.clear();
    printSet(s1);
}

int main()
{
    test01();
    return 0;
}
