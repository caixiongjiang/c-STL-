//
// Created by Jarson's mac on 2021/12/20.
//
#include <iostream>
using namespace std;
#include <list>

//list容器 数据存取

void test01()
{
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);

    //l1[0] 不可以使用[]访问list中的容器

    //l1.at(0) 不可以用at方式访问list容器中的元素

    //原因是list本质为链表，不是用连续的线性空间存储数据，迭代器也是不支持随机访问的
    cout << "l1的第一个元素为：" << l1.front() << endl;
    cout << "l1的最后一个元素为：" << l1.back() << endl;

    //验证迭代器是不支持随机访问的
    list<int>::iterator it = l1.begin();
    it++;//支持双向递增递减
    it--;
    //it = it + 1;   不允许加特定的数值（不支持随机访问）
}

int main()
{
    test01();
    return 0;
}
