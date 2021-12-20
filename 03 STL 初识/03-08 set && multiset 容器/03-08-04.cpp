//
// Created by Jarson's mac on 2021/12/20.
//
#include <iostream>
using namespace std;
#include <set>

//set容器 查找和统计

void test01()
{
    //查找
    set<int> s1;
    s1.insert(10);
    s1.insert(50);
    s1.insert(40);
    s1.insert(20);
    s1.insert(30);

    set<int>::iterator pos = s1.find(30);
    if(pos != s1.end())
    {
        cout << "找到元素：" << *pos  << endl;
    }
    else
    {
        cout << "未找到元素：" << endl;
    }
}

void test02()
{
    //计数
    set<int> s1;
    s1.insert(10);
    s1.insert(50);
    s1.insert(40);
    s1.insert(20);
    s1.insert(30);
    s1.insert(30);
    s1.insert(30);

    //统计30的个数
    int num = s1.count(30);
    //对于set而言 统计结果 要么是0 要么是1
    cout << "30的个数为num = " << num << endl;
}

int main()
{
    test01();
    test02();
    return 0;
}
