//
// Created by Jarson's mac on 2021/12/13.
//
#include <iostream>
using namespace std;
#include <string>
//string赋值操作

void test01()
{
    string str1;
    str1 = "hello world!";
    cout << "str1 = " << str1 << endl;

    string str2;
    str2 = str1;
    cout << "str2 = " << str2 << endl;

    string str3;
    str3 = 'a';
    cout << "str3 = " << str3 << endl;

    //成员函数的赋值方法
    string str4;
    str4.assign("hello C++");
    cout << "str4 = " << str4 << endl;

    string str5;
    str5.assign("hello C++", 5);//将字符串的前5个字符拿过来赋值为str5
    cout << "str5 = " << str5 << endl;

    string str6;
    str6.assign(str5);
    cout << "str6 = " << str6 << endl;

    string str7;
    str7.assign(10, 'w');
    cout << "str7 = " << str7 << endl;
}

int main()
{
    test01();
    return 0;
}
