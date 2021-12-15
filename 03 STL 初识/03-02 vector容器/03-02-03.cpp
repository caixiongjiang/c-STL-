//
// Created by Jarson's mac on 2021/12/15.
//
#include <iostream>
using namespace std;
#include <vector>

//vector容器的容量和大小操作

void printVector(vector<int> &v)
{
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    vector<int> v1;
    for(int i = 0; i < 10; i++)
    {
        v1.emplace_back(i);
    }
    printVector(v1);

    if(v1.empty()) //为真代表容器为空
    {
        cout << "v1为空" << endl;
    }
    else
    {
        cout << "v1不为空" <<endl;
        cout << "v1的容量为：" << v1.capacity() << endl;//16
        cout << "v1的大小为：" << v1.size() << endl;//10
    }

    //重新指定大小
    //利用重载版本，参数2可以指定默认填充值
    v1.resize(15, 100);
    //如果重新指定的比原来长了，默认用0来填充新的位置
    printVector(v1);// 0 1 2 3 4 5 6 7 8 9 100 100 100 100 100
    //如果重新指定的比原来短了，超出的部分会删除掉
    v1.resize(5);
    printVector(v1);

}

int main()
{
    test01();
    return 0;
}
