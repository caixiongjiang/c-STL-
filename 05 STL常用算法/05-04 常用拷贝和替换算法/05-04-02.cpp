//
// Created by Jarson's mac on 2021/12/28.
//
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
//常用拷贝和替换算法 replace

void test01()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(50);
    v.push_back(20);
    v.push_back(20);
    v.push_back(30);
    v.push_back(60);
    v.push_back(20);

    cout << "替换前：" << endl;
    for_each(v.begin(), v.end(), [&](const int &val){cout << val << " ";});
    cout << endl;
    //替换前：
    //10 50 20 20 30 60 20

    replace(v.begin(), v.end(), 20, 2000);
    cout << "替换后：" << endl;
    for_each(v.begin(), v.end(), [&](const int &val){cout << val << " ";});
    //替换后：
    //10 50 2000 2000 30 60 2000
}

int main()
{
    test01();
    return 0;
}
