//
// Created by Jarson's mac on 2021/12/22.
//
#include <iostream>
using namespace std;
#include <map>

//map容器 大小和交换

void printMap(map<int, int> &m)
{
    for(map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key = " << (*it).first << "   value = " << (*it).second << endl;
    }
    cout << endl;
}

//大小
void test01()
{
    //键值对的方式出现
    map<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));

    if(m.empty()){
        cout << "map为空" << endl;
    }
    else
    {
        cout << "map m不为空" << endl;
        cout << "map m的大小为" << m.size() << endl;
    }
}

//交换
void test02()
{
    map<int, int> m1;
    m1.insert(pair<int, int>(1, 10));
    m1.insert(pair<int, int>(2, 20));
    m1.insert(pair<int, int>(3, 30));

    map<int, int> m2;
    m2.insert(pair<int, int>(4, 100));
    m2.insert(pair<int, int>(5, 200));
    m2.insert(pair<int, int>(6, 300));

    cout << "交换前：" << endl;
    printMap(m1);
    printMap(m2);
    cout << "---------------------" << endl;
    m2.swap(m1);
    cout << "交换后：" << endl;
    printMap(m1);
    printMap(m2);
}

int main()
{
    test01();
    test02();
    //交换前：
    //key = 1   value = 10
    //key = 2   value = 20
    //key = 3   value = 30
    //
    //key = 4   value = 100
    //key = 5   value = 200
    //key = 6   value = 300
    //---------------------
    //交换后：
    //key = 4   value = 100
    //key = 5   value = 200
    //key = 6   value = 300
    //
    //key = 1   value = 10
    //key = 2   value = 20
    //key = 3   value = 30
    return 0;
}
