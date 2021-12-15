//
// Created by Jarson's mac on 2021/12/15.
//
#include <iostream>
using namespace std;
#include <vector>

//vector容器互换

void printVector(vector<int> &v)
{
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

//1.基本使用
void test01()
{
    vector<int> v1;
    for(int i = 0; i < 10; i++)
    {
        v1.emplace_back(i);
    }
    cout << "交换前：" << endl;
    printVector(v1);

    vector<int> v2;
    for(int i = 9; i >= 0; i--)
    {
        v2.emplace_back(i);
    }
    printVector(v2);

    cout << "交换后：" << endl;
    v1.swap(v2);
    printVector(v1);
    printVector(v2);
}

//2.实际用途
//巧用swap可以收缩内存空间
void test02()
{
    vector<int> v;
    for(int i = 0; i < 100000; i++)
    {
        v.emplace_back(i);
    }

    cout << "v的容量为：" << v.capacity() << endl;//131072
    cout << "v的大小为：" << v.size() << endl;//100000

    v.resize(3);//重新指定大小为3
    cout << "v的容量为：" << v.capacity() << endl;//131072
    cout << "v的大小为：" << v.size() << endl;//3

    //巧用swap收缩内存
    /*vector<int>(v) 代表匿名对象
     *  .swap(v) 代表容器交换
     *  匿名对象执行完系统会回收，使得原本庞大的空间被释放
     * */
    vector<int>(v).swap(v);
    cout << "v的容量为：" << v.capacity() << endl;//3
    cout << "v的大小为：" << v.size() << endl;//3
}

int main()
{
    test01();
//    交换前：
//    0 1 2 3 4 5 6 7 8 9
//    9 8 7 6 5 4 3 2 1 0
//    交换后：
//    9 8 7 6 5 4 3 2 1 0
//    0 1 2 3 4 5 6 7 8 9
    test02();
    return 0;
}
