//
// Created by Jarson's mac on 2021/12/28.
//
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//常用集合算法 set_union

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
    //最特殊情况 大容器包含小容器 开辟空间 取两个容器size之和
    vTarget.resize(v1.size() + v2.size());
    vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    for_each(vTarget.begin(), itEnd, [&](const int val){cout << val << " ";});
    //0 1 2 3 4 5 6 7 8 9 10 11 12 13 14
    cout << endl;
}

int main()
{
    test01();
    return 0;
}
