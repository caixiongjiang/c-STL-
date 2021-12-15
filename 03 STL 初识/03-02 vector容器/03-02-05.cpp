//
// Created by Jarson's mac on 2021/12/15.
//
#include <iostream>
using namespace std;
#include <vector>

//vector容器的数据存取

void test01()
{
    vector<int> v1;
    for(int i = 0; i < 10; i++)
    {
        v1.emplace_back(i);
    }
    //利用[]的方式来访问数组中的元素
    for(int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;

    //利用at方式访问元素
    for(int i = 0; i < v1.size(); i++)
    {
        cout << v1.at(i) << " ";//0 1 2 3 4 5 6 7 8 9
    }
    cout << endl;

    //获取第一个元素
    cout << "第一个元素为：" << v1.front() << endl;//0

    //获取最后一个元素
    cout << "最后一个元素为：" << v1.back() << endl;//9
}

int main()
{
    test01();
    return 0;
}
