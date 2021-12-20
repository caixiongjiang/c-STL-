//
// Created by Jarson's mac on 2021/12/20.
//
#include <iostream>
using namespace std;
#include <set>

//set容器和multiset容器区别

void test01()
{
    set<int> s;
    //set插入会返回一个队组的数据类型
    //第一次插入
    pair<set<int>::iterator, bool> ret = s.insert(10);
    if(ret.second)
    {
        cout << "第一次插入成功了" << endl;
    }
    else
    {
        cout << "第一次插入失败了" << endl;
    }

    //第二次插入
    ret = s.insert(10);
    if(ret.second)
    {
        cout << "第二次插入成功了" << endl;
    }
    else
    {
        cout << "第二次插入失败了" << endl;
    }
}

void test02()
{
    multiset<int> ms;
    //multiset插入只会返回一个迭代器
    //允许插入重复的值
    ms.insert(10);
    ms.insert(10);
    ms.insert(30);
    ms.insert(20);

    for(multiset<int>::iterator it = ms.begin(); it != ms.end(); it++)
    {
        cout << *it << " ";
     }
    //10 10 20 30
    cout << endl;

}

int main()
{
    test01();
    //第一次插入成功了
    //第二次插入失败了
    test02();
    return 0;
}
