//
// Created by Jarson's mac on 2021/12/28.
//
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//常用拷贝和替换算法 copy

void test01()
{
    vector<int> v1;
    for(int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    vector<int> v2;
    v2.resize(v1.size());
    copy(v1.begin(), v1.end(), v2.begin());
    for_each(v2.begin(), v2.end(), [&](const int &val){cout << val << " ";});
    //0 1 2 3 4 5 6 7 8 9
    cout << endl;
}

int main()
{
    test01();
    return 0;
}
