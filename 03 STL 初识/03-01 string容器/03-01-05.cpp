//
// Created by Jarson's mac on 2021/12/13.
//
#include <iostream>
using namespace std;

//字符串比较

void test01()
{
    string str1 = "xello";
    string str2 = "hello";
    //对比方式，每个字符按照ASCII码值进行比较

    if(str1.compare(str2) == 0){
        cout << "str1等于str2" << endl;
    }
    else if(str1.compare(str2) > 0)
    {
        cout << "str1大于str2" << endl;
    }
    else{
        cout << "str1小于str2" << endl;
    }
}

int main()
{
    test01();
    return 0;
}