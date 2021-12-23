//
// Created by Jarson's mac on 2021/12/23.
//
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>

//关系仿函数  例：大于 greater

class myCompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};

void test01()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(40);
    v.push_back(20);
    v.push_back(50);

    for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    //10 30 40 20 50
    cout << endl;

    //降序
    //sort(v.begin(), v.end(), myCompare());
    //greater<int>() 内建函数对象
    sort(v.begin(), v.end(), greater<int>());
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    //50 40 30 20 10
    cout << endl;
}

int main()
{
    test01();
    return 0;
}
