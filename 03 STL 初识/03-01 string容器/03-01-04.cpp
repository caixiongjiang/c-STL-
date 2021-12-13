//
// Created by Jarson's mac on 2021/12/13.
//
#include <iostream>
using namespace std;
#include <string>

//字符串查找和替换

//1.查找
void test01()
{
    string str1 = "abcdefgde";
    int pos1 = str1.find("de");//默认从pos = 0 的位置开始查找，返回位置下标
    int pos2 = str1.find("df");//没有找到
    cout << "pos1 = " << pos1 << endl;//3
    cout << "pos2 = " << pos2 << endl;//-1

    //rfind和find的区别：
    //rfind从右往左查找  find从左往右查找
    int pos3 = str1.rfind("de");
    cout << "pos3 = " << pos3 << endl;//7
}
//2.替换
void test02()
{
    string str1 = "abcdefg";
    //1代表起始位置， 3为要替换的长度，替换为"1111"
    str1.replace(1, 3, "1111");
    cout << "str1 = " << str1 << endl;//str1 = a1111efg
}

int main()
{
    test01();
    test02();
    return 0;
}