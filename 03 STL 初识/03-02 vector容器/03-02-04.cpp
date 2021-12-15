//
// Created by Jarson's mac on 2021/12/15.
//
#include <iostream>
using namespace std;
#include <vector>

//插入和删除

void printVector(vector<int> &v)
{
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    vector<int> v1;
    //尾插
    v1.emplace_back(10);
    v1.emplace_back(20);
    v1.emplace_back(30);
    v1.emplace_back(40);
    v1.emplace_back(50);

    printVector(v1);

    //尾删
    v1.pop_back();
    printVector(v1);//10 20 30 40

    //插入  第一个参数是迭代器
    v1.insert(v1.begin(), 100);
    printVector(v1);//100 10 20 30 40

    //在v1.begin()的位置插入两个1000
    v1.insert(v1.begin(), 2, 1000);
    printVector(v1);//1000 1000 100 10 20 30 40

    //删除 参数也是迭代器
    v1.erase(v1.begin());
    printVector(v1);//1000 100 10 20 30 40

    //清空
    //v1.erase(v1.begin(), v1.end());
    v1.clear();
    printVector(v1);
}

int main()
{
    test01();
    return 0;
}
