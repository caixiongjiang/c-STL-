//
// Created by Jarson's mac on 2021/12/16.
//
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>

/*
 有5名选手：ABCDE ，10个评委分别对每一个选手打分，
 去除评委中最高分和最低分，取平均分
 * */

//选手类
class Person
{
public:
    Person(string name, int score)
    {
        this->m_Name = name;
        this->m_Score = score;
    }

    string m_Name;//姓名
    int m_Score;//平均分
};

void creatPerson(vector<Person> &v)
{
    string nameSeed = "ABCDE";
    for(int i  = 0; i < 5; i++)
    {
        string name  = "选手";
        name += nameSeed[i];

        int score = 0;

        Person p(name, score);

        //将创建的Person对象放入到容器中
        v.push_back(p);
    }
}

//打分
void setScore(vector<Person> &v)
{
    for(vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        //将评委的分数放入一个deque容器中
        deque<int> d;
        for(int i = 0; i < 10; i++)
        {
            //rand() % 40 为0到39
            int score = rand() % 41 + 60;    //60~100之间的随机数
            d.push_back(score);
        }

        /*手动打印每个评委的分数测试（测试使用）
        cout << it->m_Name << "打分：" << endl;
        for(deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
        {
            cout << *dit << " ";
        }
        cout << endl;
         */

        //先排序
        sort(d.begin(), d.end());

        //去除最高和最低分
        d.pop_back();
        d.pop_front();

        //取平均分
        int sum = 0;
        for(deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
        {
            sum += *dit;//累加每个评委的分数
        }
        int avg = sum / d.size();

        //将平均分赋值给选手上
        it->m_Score = avg;
    }
}

void showScore(vector<Person> &v)
{
    for(vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "姓名：" << it->m_Name << "平均分" << it->m_Score << endl;
    }
}

int main()
{
    //随机数的种子 必须加在main函数里
    srand((unsigned int)time(NULL));

    //1.创建5名选手
    vector<Person> v;//存放选手容器
    creatPerson(v);

    //测试
    /*
    for(vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "姓名：" << (*it).m_Name << "  分数：" << (*it).m_Score << endl;
    }
     */

    //2.给5名选手打分
    setScore(v);
    //第一次手动打分测试结果：
//    选手A打分：
//    98 69 62 62 95 85 78 80 74 72
//    选手B打分：
//    83 97 60 97 93 72 80 97 90 73
//    选手C打分：
//    69 89 77 60 67 62 95 80 88 80
//    选手D打分：
//    92 64 61 88 71 76 78 86 70 60
//    选手E打分：
//    71 98 80 68 94 90 66 71 67 94

    //3.显示最后得分
    showScore(v);
//    姓名：选手A平均分76
//    姓名：选手B平均分85
//    姓名：选手C平均分76
//    姓名：选手D平均分74
//    姓名：选手E平均分79
    return 0;
}
