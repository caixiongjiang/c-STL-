//
// Created by Jarson's mac on 2021/12/27.
//
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//常用查找算法 binary_search

void test01()
{
    vector<int> v;
    for(int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    //v.push_back(2);  如果是无序序列，结果未知！
    //查找容器中是否有9元素
    //注意:这个容器必须时有序的序列
    bool flag = binary_search(v.begin(), v.end(), 9);
    if(flag)
    {
        cout << "找到了" << endl;
    }
    else
    {
        cout << "未找到" << endl;
    }
}

int main()
{
    test01();
    //找到了
    return 0;
}
