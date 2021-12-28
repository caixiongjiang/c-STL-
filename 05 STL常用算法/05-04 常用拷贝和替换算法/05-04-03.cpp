//
// Created by Jarson's mac on 2021/12/28.
//
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//常用拷贝和替换算法 repalce_if

class Greater30
{
public:
    bool operator()(const int &val)
    {
        return val >= 30;
    }
};

void test01()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(30);
    v.push_back(50);
    v.push_back(70);
    v.push_back(20);
    v.push_back(60);
    v.push_back(10);

    //将大于等于30的元素替换成3000
    cout << "替换前：" << endl;
    for_each(v.begin(), v.end(), [&](const int &val){cout << val << " ";});
    //替换前：
    //10 40 30 50 70 20 60 10
    cout << endl;

    //方式1
    replace_if(v.begin(), v.end(), Greater30(), 3000);
    cout << "1次替换：" << endl;
    for_each(v.begin(), v.end(), [&](const int &val){cout << val << " ";});
    //1次替换：
    //10 3000 3000 3000 3000 20 3000 10
    cout << endl;

    //方式2
    replace_if(v.begin(), v.end(), [&](const int &val){
        return val >500;
    }, 3000);
    cout << "2次替换：" << endl;
    for_each(v.begin(), v.end(), [&](const int &val){cout << val << " ";});
    //2次替换：
    //10 3000 3000 3000 3000 20 3000 10
}

int main()
{
    test01();
    return 0;
}
