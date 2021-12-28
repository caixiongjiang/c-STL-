//
// Created by Jarson's mac on 2021/12/28.
//
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//常用的拷贝和替换算法 swap

void test01()
{
    vector<int> v1;
    vector<int> v2;

    for(int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(100 + i);
    }
    cout << "交换前：" << endl;
    for_each(v1.begin(), v1.end(), [&](const int &val){
        cout << val << " ";
    });
    cout << endl;

    for_each(v2.begin(), v2.end(), [&](const int &val){
        cout << val << " ";
    });
    cout << endl;

    cout << "交换后：" << endl;
    swap(v1, v2);
    for_each(v1.begin(), v1.end(), [&](const int &val){
        cout << val << " ";
    });
    cout << endl;

    for_each(v2.begin(), v2.end(), [&](const int &val){
        cout << val << " ";
    });
    cout << endl;
}

int main()
{
    test01();
    //交换前：
    //0 1 2 3 4 5 6 7 8 9
    //100 101 102 103 104 105 106 107 108 109
    //交换后：
    //100 101 102 103 104 105 106 107 108 109
    //0 1 2 3 4 5 6 7 8 9
    return 0;
}
