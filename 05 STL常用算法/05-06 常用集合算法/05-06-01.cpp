//
// Created by Jarson's mac on 2021/12/28.
//
#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
//常用的集合算法 set_intersection

void test01()
{
    vector<int> v1;
    vector<int> v2;
    for(int i = 0; i < 10; i++)
    {
        v1.push_back(i);//0~9
        v2.push_back(i + 5);//5~14
    }

    vector<int> vTarget;
    //目标容器需要提前开辟空间
    //最特殊情况 大容器包含小容器 开辟空间 取小容器的size
    vTarget.resize(min(v1.size(), v2.size()));

    //获取交集 返回交集最后元素的后一个位置的迭代器
    vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    //开辟容器大小一般会大于等于itEnd
    for_each(vTarget.begin(), itEnd, [&](const int &val){cout << val << " ";});
    //5 6 7 8 9
}

int main()
{
    test01();
    return 0;
}
