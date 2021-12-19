//
// Created by Jarson's mac on 2021/12/19.
//
#include <iostream>
using namespace std;
#include <list>

//list容器的赋值与交换

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
    list<int> l1;

    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);

    printList(l1);

    list<int> l2;
    l2 = l1;//operator= 赋值
    printList(l2);

    list<int> l3;
    l3.assign(l2.begin(), l2.end());
    printList(l3);

    list<int> l4;
    l4.assign(10, 100);
    printList(l4);
}

void test02()
{
    list<int> l1;

    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);

    list<int> l2;
    l2.assign(10, 100);
    cout << "交换前：" << endl;
    printList(l1);
    printList(l2);

    l1.swap(l2);

    cout << "交换后：" << endl;
    printList(l1);
    printList(l2);
}

int main()
{
    test01();
    //10 20 30 40
    //10 20 30 40
    //10 20 30 40
    //100 100 100 100 100 100 100 100 100 100
    test02();
    //交换前：
    //10 20 30 40
    //100 100 100 100 100 100 100 100 100 100
    //交换后：
    //100 100 100 100 100 100 100 100 100 100
    //10 20 30 40
    return 0;
}
