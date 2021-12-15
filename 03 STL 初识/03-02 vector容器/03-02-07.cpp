//
// Created by Jarson's mac on 2021/12/15.
//
#include <iostream>
using namespace std;
#include <vector>

//vector预留空间

void test01()
{
    vector<int> v;

    //利用reserve预留空间
    v.reserve(100000);
    int num = 0;//统计开辟内存的次数
    int *p = NULL;
    for(int i = 0; i < 100000; i++)
    {
        v.emplace_back(i);
        //每次重新开辟内存空间首地址会发生改变，每发生一次改变，
        //就记一次数，并让p指向首地址的位置
        if(p != &v[0])
        {
            p = &v[0];
            num++;
        }
    }
    //这样num就等于开辟内存的次数
    //提前预留空间了开辟次数就为1， 如果没预留100000个数据需要开辟18次
    cout << "开辟内存的次数为 " << num << endl;
}

int main()
{
    test01();
    return 0;
}
