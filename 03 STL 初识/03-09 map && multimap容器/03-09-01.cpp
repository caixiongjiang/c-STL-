//
// Created by Jarson's mac on 2021/12/22.
//
#include <iostream>
using namespace std;
#include <map>

//map容器 赋值和构造

void printMap(map<int, int> &m)
{
    for(map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key = " << (*it).first << "   value = " << it->second << endl;
    }
    cout << endl;
}

void test01()
{
    //创建map容器
    map<int, int> m;

    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(3, 30));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(4, 40));

    printMap(m);
    //按照key值进行排序
    //key = 1   value = 10
    //key = 2   value = 20
    //key = 3   value = 30
    //key = 4   value = 40

    //拷贝构造
    map<int, int> m1(m);
    printMap(m1);

    //赋值
    map<int, int> m2;
    m2 = m1;
    printMap(m2);
}

int main()
{
    test01();
    return 0;
}
