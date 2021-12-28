//
// Created by Jarson's mac on 2021/12/28.
//
#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

//常用排序算法 merge

void myPrint(int val)
{
    cout << val << " ";
}

void test01()
{
    vector<int> v1;
    vector<int> v2;
    for(int i = 0; i < 10; i++)
    {
        v1.push_back(i);//0~9
        v2.push_back(i + 2);//2~11
    }

    //目标容器
    vector<int> vTarget;
    //提前给目标容器分配空间
    vTarget.resize(v1.size() + v2.size());
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    for_each(vTarget.begin(), vTarget.end(), myPrint);
}

int main()
{
    test01();
    //0 1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9 10 11
    return 0;
}
