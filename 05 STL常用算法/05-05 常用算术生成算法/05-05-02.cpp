//
// Created by Jarson's mac on 2021/12/28.
//
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//常用算术生成算法  fill

void test01()
{
    vector<int> v;
    v.resize(10);

    //后期重新填充
    fill(v.begin(), v.end(), 100);
    for_each(v.begin(), v.end(), [&](const int &val){
        cout << val << " ";
    });
    //100 100 100 100 100 100 100 100 100 100
    cout << endl;
}

int main()
{
    test01();
    return 0;
}
