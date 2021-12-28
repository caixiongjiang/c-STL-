//
// Created by Jarson's mac on 2021/12/28.
//
#include <iostream>
using namespace std;
#include <vector>
#include <numeric>//小型算法头文件

//常用算术生成算法 accumulate

void test01()
{
    vector<int> v;
    for(int i = 0; i <= 100; i++)
    {
        v.push_back(i);
    }
    int total = accumulate(v.begin(), v.end(), 0);
    cout << "total=" << total << endl;
    //total=5050
}

int main()
{
    test01();
    return 0;
}
