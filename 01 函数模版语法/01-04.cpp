//
// Created by Jarson's mac on 2021/12/3.
//

#include <iostream>
using namespace std;

//普通函数和函数模版的区别

//1.普通函数调用可以发生隐式类型转换
//2.函数模版用自动类型推导，不可以发生隐式类型转换
//3.函数模版用显示指定类型，可以发生隐式类型转换

//普通函数
int myAdd01(int a, int b)
{
    return a + b;
}

void test01()
{
    int a = 10;
    int b = 20;

    cout << myAdd01(a, b) << endl;
}

int main()
{
    test01();
    return 0;
}