//
// Created by Jarson's mac on 2021/12/15.
//
#include <iostream>
using namespace std;
#include <vector>

//vector赋值

void printVector(vector<int> &v)
{
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    vector<int> v1;
    for(int i  = 0; i < 10; i++)
    {
        v1.emplace_back(i);
    }
    printVector(v1);

    //赋值 operator=
    vector<int> v2;
    v2 = v1;
    printVector(v2);

    //assign
    vector<int> v3;
    v3.assign(v1.begin(), v1.end());
    printVector(v3);

    //n个element方式赋值
    vector<int> v4;
    v4.assign(10, 100);
    printVector(v4);
}

int main()
{
    test01();
    return 0;
}