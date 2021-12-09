//
// Created by Jarson's mac on 2021/12/9.
//

#include <iostream>
using namespace std;
#include "MyArray.hpp"
#include <string>

//类模板案例——数组类封装

void test01()
{
    MyArray<int> arr1(5);                  //MyArray的有参构造调用
    MyArray<int> arr2(arr1);                            //MyArray的拷贝构造调用
    MyArray<int> arr3(100);             //MyArray的有参构造调用
    arr3 = arr1;                                                //MyArray的operater=构造调用
}                                                                     //MyArray的析构函数调用
                                                                      //MyArray的析构函数调用
                                                                      //MyArray的析构函数调用

void printIntArray(MyArray<int> &arr)
{
    for(int i = 0; i < arr.getSize(); i++)
    {
        cout << arr[i] << endl;
    }
}


void test02()
{
    MyArray<int> arr3(5);

    for(int i = 0; i < 5; i++)
    {
        //利用尾插法向数组中插入数据
        arr3.push_back(i);
    }
    cout << "arr3的打印输出为：" << endl;
    printIntArray(arr3);

    cout << "arr3的容量为：" << arr3.getCapacity() << endl;//5
    cout << "arr3的大小为：" << arr3.getSize() << endl;//5

    MyArray<int> arr4(arr3);
    cout << "arr4的打印输出为：" << endl;
    printIntArray(arr4);

    //尾删
    arr4.pop_back();
    cout << "arr4尾删后：" << endl;
    cout << "arr4的容量为：" << arr4.getCapacity() << endl;//5
    cout << "arr4的大小为：" << arr4.getSize() << endl;//4
}

//测试自定义的数据类型
class Person
{
public:
    Person() {}
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    string m_Name;
    int m_Age;
};

void printPersonArray(MyArray<Person> &arr)
{
    for(int i = 0; i < arr.getSize(); i++)
    {
        cout << "姓名：" << arr[i].m_Name << "    年龄："  << arr[i].m_Age << endl;
    }
}

void test03()
{
    MyArray<Person> arr(10);
    Person p1("孙悟空", 999);
    Person p2("韩信", 30);
    Person p3("妲己", 20);
    Person p4("赵云", 25);
    Person p5("安琪拉", 27);

    //将数组插入到数组中
    arr.push_back(p1);
    arr.push_back(p2);
    arr.push_back(p3);
    arr.push_back(p4);
    arr.push_back(p5);
    //打印数组
    printPersonArray(arr);
    //输出容量和大小
    cout << "arr的容量为：" <<arr.getCapacity() << endl;
    cout << "arr的大小为：" <<arr.getSize() << endl;
}

int main()
{
    //test01();
    test02();
    test03();
    return 0;
}
