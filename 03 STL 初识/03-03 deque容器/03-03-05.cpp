//
// Created by Jarson's mac on 2021/12/16.
//
#include <iostream>
using namespace std;
#include <deque>

//deque容器的数据存取

void test01()
{
    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_front(100);
    d.push_front(200);
    d.push_front(300);

    //通过[]的方式访问元素
    //300 200 100 10 20 30
    for(int i = 0; i < d.size(); i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;

    //通过at方式访问元素
    //300 200 100 10 20 30
    for(int i = 0; i < d.size(); i++)
    {
        cout << d.at(i) << " ";
    }
    cout << endl;

    cout << "第一个元素为：" << d.front() << endl;//300
    cout << "最后一个元素为：" << d.back() << endl;//30
}

int main()
{
    test01();
    return 0;
}
