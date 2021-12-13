//
// Created by Jarson's mac on 2021/12/13.
//
#include <iostream>
using namespace std;
#include <string>

//string字符串的拼接操作

void test01()
{
    string str1 = "我";
    str1 += "爱玩游戏";
    cout << "str1 = " << str1 << endl;//str1 = 我爱玩游戏

    str1 += ':';
    cout << "str1 = " << str1 << endl;//str1 = 我爱玩游戏

    string str2 = " LOL DNF";
    str1 += str2;
    cout << "str1 = " << str1 << endl;//str1 = 我爱玩游戏: LOL DNF

    string str3 = "I";
    str3.append(" love");
    cout << "str3 = " << str3 << endl;//str3 = I love

    str3.append(" game abcde", 5);
    cout << "str3 = " << str3 << endl;//str3 = I love game

    str3.append(str2);
    cout << "str3 = " << str3 << endl;//str3 = I love game LOL DNF

    str3.append(str2, 0, 4);//只截取到LOL  参数2 是从哪个位置开始截取 位置3 截取字符串的个数
    cout << "str3 = " << str3 << endl;//str3 = I love game LOL DNF LOL
}

int main()
{
    test01();
    return 0;
}