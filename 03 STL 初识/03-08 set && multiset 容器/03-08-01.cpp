//
// Created by Jarson's mac on 2021/12/20.
//
#include <iostream>
using namespace std;
#include <set>          //set头文件包括set和multiset两个容器

//set容器的构造和赋值

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
    s1.insert(30);
    s1.insert(20);
    s1.insert(30);

    //遍历容器
    //set容器的特点：
    //1.所有的元素插入时候会自动被排序
    //2.set容器不允许插入重复值
    printSet(s1);
    //10 20 30 40

    //拷贝构造
    set<int> s2(s1);
    printSet(s2);
    //10 20 30 40

    //赋值
    set<int> s3;
    s3 = s2;
    printSet(s3);
    //10 20 30 40
}

int main()
{
    test01();
    return 0;
}
