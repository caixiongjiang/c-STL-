//
// Created by Jarson's mac on 2021/12/17.
//
#include <iostream>
using namespace std;
#include <queue>
#include <string>
//队列queue

class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    string m_Name;
    int m_Age;
};

void test01()
{
    //创建队列
    queue<Person> q;
    //准备数据
    Person p1("唐僧", 30);
    Person p2("孙悟空", 1000);
    Person p3("猪八戒", 900);
    Person p4("沙僧", 800);

    //入队
    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);

    cout << "队列的大小：" << q.size() << endl;//4

    //判断只要队列不为空，查看队头，队尾，出队
    while(!q.empty())
    {
        //查看队头
        cout << "队头元素—— 姓名：" << q.front().m_Name << "年龄 ：" << q.front().m_Age << endl;
        //查看队尾
        cout << "队尾元素——姓名：" << q.back().m_Name << "年龄：" << q.back().m_Age << endl;
        //出队
        q.pop();
    }
    cout << "队列的大小：" << q.size() << endl;//0
}

int main()
{
    test01();
//    队列的大小：4
//    队头元素—— 姓名：唐僧年龄 ：30
//    队尾元素——姓名：沙僧年龄：800
//    队头元素—— 姓名：孙悟空年龄 ：1000
//    队尾元素——姓名：沙僧年龄：800
//    队头元素—— 姓名：猪八戒年龄 ：900
//    队尾元素——姓名：沙僧年龄：800
//    队头元素—— 姓名：沙僧年龄 ：800
//    队尾元素——姓名：沙僧年龄：800
//    队列的大小：0
    return 0;
}
