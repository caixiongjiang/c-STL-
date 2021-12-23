//
// Created by Jarson's mac on 2021/12/23.
//
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>
//逻辑仿函数
//逻辑非 logical_not

void test01()
{
    vector<bool> v;
    v.push_back(true);
    v.push_back(false);
    v.push_back(true);
    v.push_back(false);

    for(vector<bool>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    //1 0 1 0
    cout << endl;

    //利用逻辑非  将容器v搬运到容器v2中，并执行取反操作
    vector<bool> v2;
    v2.resize(v.size());
    //前两个参数为被搬运的容器的区间。
    // 第三个参数为目标容器的起始迭代器，第四个参数为仿函数（匿名函数对象）
    transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());
    for(vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
    {
        cout << *it << " ";
    }
    //0 1 0 1
    cout << endl;
}

int main()
{
    test01();
    return 0;
}
