//
// Created by Jarson's mac on 2021/12/23.
//
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
//二元谓词

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
    v.push_back(40);
    v.push_back(20);
    v.push_back(50);
    v.push_back(30);

    sort(v.begin(), v.end());
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    //使用函数对象 改变算法策略，变为排序规则为从大到小
    //myCompare() 为匿名函数对象
    sort(v.begin(), v.end(), myCompare());
    cout << "------------------------" << endl;
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    test01();
    //10 20 30 40 50
    //------------------------
    //50 40 30 20 10
    return 0;
}
