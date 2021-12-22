//
// Created by Jarson's mac on 2021/12/22.
//
#include <iostream>
using namespace std;
#include <map>

//map容器 插入和删除

void printMap(map<int, int> &m)
{
    for(map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key = " << (*it).first << "   value = " << (*it).second << endl;
    }
    cout << endl;
}

void test01()
{
    map<int, int> m;

    //插入
    //第一种
    m.insert(pair<int, int>(1, 10));

    //第二种（推荐使用这一种）
    m.insert(make_pair(2, 20));

    //第三种
    m.insert(map<int, int>::value_type(3, 30));

    //第四种
    m[4] = 40;

    //如果用第四种方式输出没有的键值对
    //系统会自动将这个键值对的value变为0输出
    //[]不建议插入，用途 ：可以利用key访问到value
    cout << m[5] << endl;
    printMap(m);
    //0
    //key = 1   value = 10
    //key = 2   value = 20
    //key = 3   value = 30
    //key = 4   value = 40
    //key = 5   value = 0

    //删除
    m.erase(m.begin());
    printMap(m);
    //key = 2   value = 20
    //key = 3   value = 30
    //key = 4   value = 40
    //key = 5   value = 0

    m.erase(3);//按照key删除，没有则不删
    printMap(m);
    //key = 2   value = 20
    //key = 4   value = 40
    //key = 5   value = 0

    //清空
    m.erase(m.begin(), m.end());
    printMap(m);
    m.clear();
}

int main()
{
    test01();
    return 0;
}
