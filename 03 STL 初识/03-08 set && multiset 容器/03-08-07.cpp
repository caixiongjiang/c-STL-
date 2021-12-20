//
// Created by Jarson's mac on 2021/12/20.
//
#include <iostream>
using namespace std;
#include <set>

//set容器排序

//仿函数
class Mycompare
{
public:
    bool operator() (int v1, int v2)
    {
        return v1 > v2;
    }
};

void test01()
{
    set<int> s1;
    s1.insert(10);
    s1.insert(40);
    s1.insert(50);
    s1.insert(30);
    s1.insert(20);

    //默认排序规则为升序
    for(set<int>::iterator it = s1.begin(); it != s1.end(); it++)
    {
        cout << *it << " ";
    }
    //10 20 30 40 50
    cout << endl;

    //指定排序规则为降序
    set<int, Mycompare> s2;

    s2.insert(10);
    s2.insert(40);
    s2.insert(50);
    s2.insert(30);
    s2.insert(20);

    for(set<int, Mycompare>::iterator it = s2.begin(); it != s2.end(); it++)
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