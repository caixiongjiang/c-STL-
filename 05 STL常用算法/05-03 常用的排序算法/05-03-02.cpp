//
// Created by Jarson's mac on 2021/12/28.
//
#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <ctime>

//常用排序算法 random_shuffle

void myPrint(int val)
{
    cout << val << " ";
}

void test01()
{
    //随机数的种子
    srand((unsigned  int)time(NULL));
    vector<int> v;
    for(int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    //利用洗牌算法打乱顺序
    random_shuffle(v.begin(), v.end());
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;
}

int main()
{
    test01();
    return 0;
}
