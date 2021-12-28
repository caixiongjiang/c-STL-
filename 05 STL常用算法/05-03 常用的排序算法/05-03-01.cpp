//
// Created by Jarson's mac on 2021/12/28.
//
#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <functional>

//常用排序算法 sort

void myPrint(int val)
{
    cout << val << " ";
}

void test01()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(20);
    v.push_back(50);
    v.push_back(40);
    v.push_back(90);
    v.push_back(80);

    vector<int> clone(7);
    clone = v;

    //利用sort进行升序
    sort(v.begin(), v.end());
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;
    //10 20 30 40 50 80 90

    //改变为降序(利用内建函数对象)
    sort(v.begin(), v.end(), greater<int>());
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;
    //10 20 30 40 50 80 90

    //第二种为自定义仿函数（省略）
    //第三种写法
    sort(clone.begin(), clone.end(), [&](const int &a,const int &b){return a > b;});
    for_each(clone.begin(), clone.end(), myPrint);
    cout << endl;
    //90 80 50 40 30 20 10
}

int main()
{
    test01();
    return 0;
}
