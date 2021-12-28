//
// Created by Jarson's mac on 2021/12/28.
//
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//常用集合算法 set_difference

void test01()
{
    vector<int> v1;
    vector<int> v2;
    for(int i = 0; i < 10; i++)
    {
        v1.push_back(i);//0~9
        v2.push_back(i + 5);//5~14
    }

    //v1和v2的差集
    vector<int> vTarget1;
    //预先开辟空间
    //最特殊的情况 两个容器没有交集 取两个容器中大的size作为目标容器开辟空间
    vTarget1.resize(max(v1.size(), v2.size()));

    cout << "v1和v2的差集为：" << endl;

    vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget1.begin());
    for_each(vTarget1.begin(), itEnd, [&](const int val){cout << val << " ";});
    cout << endl;
    //v1和v2的差集为：
    //0 1 2 3 4

    cout << "v1和v2的差集为：" << endl;
    itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget1.begin());
    for_each(vTarget1.begin(), itEnd, [&](const int val){cout << val << " ";});
    cout << endl;
    //v1和v2的差集为：
    //10 11 12 13 14
}

int main()
{
    test01();
    return 0;
}
