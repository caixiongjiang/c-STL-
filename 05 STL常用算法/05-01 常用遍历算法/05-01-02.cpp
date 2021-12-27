//
// Created by Jarson's mac on 2021/12/27.
//
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
//常用遍历算法  transform

//仿函数
class Transform
{
public:
    int operator()(int v)
    {
        return v + 100;
    }
};

//仿函数
class Myprint
{
public:
    int operator()(int val)
    {
        cout << val << " ";
    }
};

void test01()
{
    vector<int> v;
    for(int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    vector<int> vTarget;//目标容器

    vTarget.resize(v.size());//目标容器需要提前开辟空间

    transform(v.begin(), v.end(), vTarget.begin(), Transform());

    for_each(vTarget.begin(), vTarget.end(), Myprint());
    //100 101 102 103 104 105 106 107 108 109
    cout << endl;
}

int main()
{
    test01();
    return 0;
}