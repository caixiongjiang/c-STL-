//
// Created by Jarson's mac on 2021/12/16.
//
#include <iostream>
using namespace std;
#include <deque>
#include <algorithm> //标准算法头文件

void printDeque(const deque<int> &d)
{
    for(deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

//deque容器排序
void test01()
{
    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_front(100);
    d.push_front(200);
    d.push_front(300);
    printDeque(d);//300 200 100 10 20 30

    //排序  默认排序规则为升序(从小到大)
    //对于支持随机访问的迭代器的容器，都可以利用sort算法直接对其进行排序
    //vector容器也可以利用sort进行排序
    sort(d.begin(), d.end());
    cout << "排序后的结果：" << endl;
    printDeque(d);//10 20 30 100 200 300
}

int main()
{
    test01();
    return 0;
}
