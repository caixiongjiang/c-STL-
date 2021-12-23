//
// Created by Jarson's mac on 2021/12/23.
//
#include <iostream>
using namespace std;
#include <functional> //内建函数对象头文件

//算术仿函数

//negata  一元仿函数 取反仿函数

void test01()
{
    negate<int> n;
    cout << n(50) << endl;//-50
}

//plus 二元仿函数 加法仿函数
void test02()
{
    plus<int> p;
    cout << p(10, 20) << endl;//30
}

int main()
{
    test01();
    test02();
    return 0;
}
