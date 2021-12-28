//
// Created by Jarson's mac on 2021/12/28.
//
#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

//常用排序算法 reverse

void myPrint(int val)
{
    cout << val << " ";
}

void test01()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(50);
    v.push_back(20);
    v.push_back(40);

    cout << "反转前：" << endl;
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;

    cout << "反转后：" << endl;
    reverse(v.begin(), v.end());
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;
}

int main()
{
    test01();
    //反转前：
    //10 30 50 20 40
    //反转后：
    //40 20 50 30 10
    return 0;
}
