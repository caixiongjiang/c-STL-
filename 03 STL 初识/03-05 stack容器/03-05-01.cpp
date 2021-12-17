//
// Created by Jarson's mac on 2021/12/17.
//
#include <iostream>
using namespace std;
#include <stack>

//栈stack容器

void test01()
{
    //特点：符合先进后出的数据结构
    stack<int> s;
    //入栈
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout << "栈的大小：" << s.size() << endl;
    //只要栈不为空，查看栈顶，并执行出栈操作
    while(!s.empty())
    {
        //查看栈顶元素
        cout << "栈顶元素为：" << s.top() << endl;

        //出栈
        s.pop();
    }
    cout << "栈的大小：" << s.size() << endl;
}

int main()
{
    test01();
//    栈的大小：4
//    栈顶元素为：40
//    栈顶元素为：30
//    栈顶元素为：20
//    栈顶元素为：10
//    栈的大小：0
    return 0;
}
