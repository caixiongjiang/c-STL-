//
// Created by Jarson's mac on 2021/12/20.
//
#include <iostream>
using namespace std;
#include <list>

//list容器的反转和排序

void printList(const list<int> &l)
{
    for(list<int>::const_iterator it = l.begin(); it != l.end(); it++)
    {
        cout << * it << " ";
    }
    cout << endl;
}

void test01()
{
    //反转
    list<int> l1;
    l1.push_back(10);
    l1.push_back(50);
    l1.push_back(40);
    l1.push_back(30);
    l1.push_back(20);
    cout << "反转前：" << endl;
    printList(l1);
//    10 50 40 30 20
    l1.reverse();
    cout << "反转后：" << endl;
    printList(l1);
//    20 30 40 50 10
}

bool myCompare(int v1, int v2)
{
    //降序  就让第一个数 > 第二个数
    return v1 > v2;
}

//排序
void test02()
{
    list<int> l1;
    l1.push_back(10);
    l1.push_back(50);
    l1.push_back(40);
    l1.push_back(30);
    l1.push_back(20);
    cout << "排序前：" << endl;
    printList(l1);
//    10 50 40 30 20

    //所有不支持随机访问迭代器的容器，不可以使用标准算法
    //sort(l1.begin(), l1.end());
    //不支持随机访问迭代器的容器，内部会提供一些对应的成员函数算法
    l1.sort();//默认排序规则为升序
    cout << "排序后：" << endl;
    printList(l1);
//10 20 30 40 50

    //降序排列
    l1.sort(myCompare);
    printList(l1);
//50 40 30 20 10
}

int main()
{
    test01();
    test02();
    return 0;
}
