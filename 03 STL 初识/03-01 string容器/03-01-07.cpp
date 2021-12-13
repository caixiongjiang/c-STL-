//
// Created by Jarson's mac on 2021/12/13.
//
#include <iostream>
using namespace std;
#include <string>

//字符串的插入和删除
void test01()
{
    string str = "hello";
    //插入
    str.insert(1, "111");
    cout << "str = " << str << endl;//str = h111ello

    //删除
    //从下标为1的位置删除3个字符
    str.erase(1, 3);
    cout << "str = " << str << endl;//str = hello
}

int main()
{
    test01();
    return 0;
}

