//
// Created by Jarson's mac on 2021/12/13.
//

#include <iostream>
using namespace std;
#include <string>

//string的构造函数
void test01()
{
    string s1;//默认构造

    const char * str = "hello world!";
    string s2(str);
    cout << "s2 = " << s2 << endl;

    string s3(s2);//拷贝构造
    cout << "s3 = " << s3 << endl;

    string s4(10, 'a');//初始化字符组成字符串
    cout << "s4 = " << s4 << endl;
}

int main()
{
    test01();
    return 0;
}
