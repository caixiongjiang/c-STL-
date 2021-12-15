//
// Created by Jarson's mac on 2021/12/15.
//
#include <iostream>
using namespace std;
#include <deque>

//deque容器 构造函数

void printDeque(const deque<int> &d)//const限定为只读状态
{
    //只读方法只能用只读迭代器进行访问
    for(deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        //*it = 100;  容器中的数据不可以修改了
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    deque<int> d1;
    for(int i = 0; i < 10; i++)
    {
        d1.emplace_back(i);
    }
    printDeque(d1);

    deque<int> d2(d1.begin(), d1.end());
    printDeque(d2);

    deque<int> d3(10, 100);
    printDeque(d3);

    deque<int> d4(d3);
    printDeque(d4);
}

int main()
{
    test01();
    return 0;
}