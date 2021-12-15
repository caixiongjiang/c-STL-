//
// Created by Jarson's mac on 2021/12/15.
//
#include <iostream>
using namespace std;
#include <string>

//string求字串
void test01()
{
    string str = "abcdef";

    string subStr = str.substr(1,3);
    cout << "subStr = " << subStr << endl;//bcd
}

//实用操作
void test02()
{
    string email = "nau_cxj@163.com";
    //从邮件地址中获取用户名信息
    int pos = email.find("@");
    cout << "@位置在：" << pos << endl;
    //@的位置在7，用户名的末尾下标是6，所以需要读6+1=7个字符
    string userName = email.substr(0, pos );
    cout << "userName = " << userName << endl;
}

int main()
{
    test01();
    test02();
    return 0;
}