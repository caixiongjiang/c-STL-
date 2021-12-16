//
// Created by Jarson's mac on 2021/12/16.
//
#include <iostream>
using namespace std;
#include <deque>

void printDeque(const deque<int> &d)
{
    for(deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

//deque容器的插入和删除

void test01()
{
    deque<int> d1;
    //尾插
    d1.push_back(10);
    d1.push_back(20);

    //头插
    d1.push_front(100);
    d1.push_front(200);

    printDeque(d1);//200 100 10 20

    //尾删
    d1.pop_back();
    printDeque(d1);//200 100 10

    //头删
    d1.pop_front();
    printDeque(d1);//100 10
}

void test02()
{
    deque<int> d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(100);
    d1.push_front(200);
    printDeque(d1);//200 100 10 20

    //insert插入
    d1.insert(d1.begin(), 1000);
    printDeque(d1);//1000 200 100 10 20

    d1.insert(d1.begin(), 2, 10000);
    printDeque(d1);//10000 10000 1000 200 100 10 20

    //按照区间来进行插入
    deque<int> d2;
    d2.push_back(1);
    d2.push_back(2);
    d2.push_back(3);
    //第一个参数为pos，第二第三个参数分别为起始迭代器和终止迭代器
    d1.insert(d1.begin(), d2.begin(), d2.end());
    printDeque(d1);//1 2 3 10000 10000 1000 200 100 10 20
}

void test03()
{
    deque<int> d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(100);
    d1.push_front(200);

    //删除
    deque<int>::iterator it = d1.begin();
    it++;
    d1.erase(it);
    printDeque(d1);//200 10 20

    //按照区间的方式进行删除
    d1.erase(d1.begin(), d1.end());
    //清空
    d1.clear();
    printDeque(d1);
}

int main()
{
    test01();
    test02();
    test03();
    return 0;
}
