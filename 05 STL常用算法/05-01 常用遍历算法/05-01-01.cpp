//
// Created by Jarson's mac on 2021/12/27.
//
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//常用遍历算法 for_each

//普通函数
void print01(int val)
{
    cout << val << " ";
}

//仿函数
class print02
{
public:
    void operator()(int val)
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
    //普通函数在遍历时要放入函数名
    for_each(v.begin(), v.end(), print01);
    cout << endl;
    //仿函数在遍历时需要放入匿名函数对象
    for_each(v.begin(), v.end(), print02());
}

int main()
{
    test01();
    return 0;
}
