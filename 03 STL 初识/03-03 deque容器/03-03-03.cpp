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

//deque容器的大小操作

void test01()
{
    deque<int> d1;
    for(int i  = 0; i < 10; i++)
    {
        d1.emplace_back(i);
    }
    printDeque(d1);

    if(d1.empty())
    {
        cout << "d1为空！" << endl;
    }
    else
    {
        cout << "d1不为空" << endl;
        cout << "d1的大小为：" << d1.size() << endl;//d1的大小为：10
        //deque容器没有容量的概念
    }

    //重新指定大小
    d1.resize(15, 1);
    printDeque(d1);//0 1 2 3 4 5 6 7 8 9 1 1 1 1 1

    d1.resize(5);
    printDeque(d1);//0 1 2 3 4

}

int main()
{
    test01();
    return 0;
}
