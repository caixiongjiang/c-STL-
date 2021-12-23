//
// Created by Jarson's mac on 2021/12/23.
//
#include <iostream>
using namespace std;
#include <string>

//函数对象（仿函数）
/*
•函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
•函数对象超出普通函数的概念，函数对象可以有自己的状态
•函数对象可以作为参数传递
 */

class MyAdd
{
public:
    int operator()(int v1, int v2)
    {
        return v1 + v2;
    }
};

void test01()
{
    MyAdd myadd;
    //函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
    cout << myadd(10, 10) << endl;
}

//函数对象超出普通函数的概念，函数对象可以有自己的状态

class Myprint
{
public:
    Myprint()
    {
        this->count = 0;
    }
    void operator()(string test)
    {
        cout << test << endl;
        this->count++;
    }
    int count;//内部自己的状态
};

void test02()
{
    Myprint myprint;
    myprint("hello world!");
    myprint("hello world!");
    myprint("hello world!");
    myprint("hello world!");
    myprint("hello world!");

    cout << "myprint的调用次数为：" << myprint.count << endl;
}

//函数对象可以作为参数传递(其实就是作为类的对象使用)

void doPrint(Myprint &mp, string test)
{
    mp(test);
}

void test03()
{
    Myprint myprint;
    doPrint(myprint, "Hello c++");
}

int main()
{
    test01();
    //20
    test02();
    //hello world!
    //hello world!
    //hello world!
    //hello world!
    //hello world!
    //myprint的调用次数为：5
    test03();
    //Hello c++
    return 0;
}
