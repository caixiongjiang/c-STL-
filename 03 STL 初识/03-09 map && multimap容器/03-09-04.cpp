//
// Created by Jarson's mac on 2021/12/22.
//
#include <iostream>
using namespace std;
#include <map>

//map容器 查找和统计

void test01()
{
    //查找
    map<int, int> m;
    m.insert(make_pair(1, 10));
    m.insert(make_pair(2, 20));
    m.insert(make_pair(3, 30));
    //key相同，map不允许插入重复的key
    m.insert(make_pair(3, 40));

    map<int, int>::iterator pos = m.find(3);
    if(pos != m.end())
    {
        cout << "查到了元素key = " << pos->first << "  value = " << (*pos).second << endl;
    }
    else
    {
        cout << "未找到元素" << endl;
    }

    //统计 ：count结果统计要么是0要么是1（multimap统计可能大于1）
    int num = m.count(3);
    cout << "num = " << num << endl;//1
}

int main()
{
    test01();
    return 0;
}