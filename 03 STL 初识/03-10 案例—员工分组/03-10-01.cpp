//
// Created by Jarson's mac on 2021/12/22.
//
//
// Created by Jarson's mac on 2021/12/22.
//
#include <iostream>
using namespace std;
#include <map>
#include <vector>
#include <string>
#include <ctime>

//案例：员工分组
/*
描述：
•公司今天招聘了10个员工 (ABCDEFGH)，10名员工进入公司之后，需要指派员工在那个部门工作
•员工信息有：姓名 工资组成；部门分为：策划、美术、研发
•随机给10名员工分配部门和工资
•通过multimap进行信息的插入 key(部门编号）value(员工）
•分部门显示员工信息

 步骤：
1. 创建10名员工，放到vector中
2. 遍历vector容品，取出每个员工，进行随机分组
3. 分组后，将员工部门编号作为key，具体员工作为value，放入到multimap容器中
4. 分部门品示员工信息
 */

#define CEHUA 0
#define MEISHU 1
#define YANFA 2

class workers
{
public:
    string m_Name;
    int m_Salary;
};

void creatWorker(vector<workers> &v)
{
    string nameSeed = "ABCDEFGHIJ";
    for(int i = 0; i < 10; i++)
    {
        workers worker;
        worker.m_Name = "员工";
        worker.m_Name += nameSeed[i];

        worker.m_Salary = rand() % 10000 + 10000; //10000~19999
        //将员工放到容器中
        v.push_back(worker);
    }
}

//员工分组
void setGroup(vector<workers> &v, multimap<int, workers> &m)
{
    for(vector<workers>::iterator it = v.begin(); it !=v.end(); it++)
    {
        //产生随机部门编号
        int depId = rand() % 3; //0, 1, 2
        //将员工插入到分组中
        //pair<部门编号, 具体的员工>
        m.insert(make_pair(depId, *it));
    }
}

//分组打印信息
void showWorkerByGroup(multimap<int, workers> &m)
{
    //0: A B C    1: D E     2: F G H I J K
    cout << "策划部门的信息：" << endl;
    multimap<int, workers>::iterator pos1 =  m.find(CEHUA);
    int count1 = m.count(CEHUA);//统计具体人数
    int index1 = 0;
    if(count1 == 0) cout << "没有员工！" << endl;
    for(; pos1 != m.end() && index1 < count1; pos1++, index1++)
    {
        cout << "姓名：" << pos1->second.m_Name << "    工资：" << pos1->second.m_Salary << endl;
    }

    cout << "--------------------------------" << endl;

    cout << "美术部门的信息：" << endl;
    multimap<int, workers>::iterator pos2 =  m.find(MEISHU);
    int count2 = m.count(MEISHU);//统计具体人数
    int index2 = 0;
    if(count2 == 0) cout << "没有员工！" << endl;
    for(; pos2 != m.end() && index2 < count2; pos2++, index2++)
    {
        cout << "姓名：" << pos2->second.m_Name << "    工资：" << pos2->second.m_Salary << endl;
    }

    cout << "--------------------------------" << endl;

    cout << "研发部门的信息：" << endl;
    multimap<int, workers>::iterator pos3 =  m.find(YANFA);
    int count3 = m.count(YANFA);//统计具体人数
    if(count3 == 0) cout << "没有员工！" << endl;
    int index3 = 0;
    for(; pos3 != m.end() && index3 < count3; pos3++, index3++)
    {
        cout << "姓名：" << pos3->second.m_Name << "    工资：" << pos3->second.m_Salary << endl;
    }
}

int main()
{
    //利用电脑时钟实现每次运行时随机数都不同
    srand((unsigned  int)time(NULL));
    //1.创建员工
    vector<workers> worker;
    creatWorker(worker);

//    //测试
//    for(vector<workers>::iterator it  = worker.begin(); it != worker.end(); it++)
//    {
//        cout << "姓名：" << it->m_Name << "   工资：" << it->m_Salary << endl;
//    }

    //2.员工分组
    multimap<int, workers> mworker;
    setGroup(worker, mworker);

    //3.分组显示员工
    showWorkerByGroup(mworker);
    return 0;
    //第一次结果：
    //策划部门的信息：
    //姓名：员工B    工资：13326
    //姓名：员工I    工资：10305
    //姓名：员工J    工资：14457
    //--------------------------------
    //美术部门的信息：
    //姓名：员工A    工资：12350
    //姓名：员工C    工资：16399
    //姓名：员工F    工资：17344
    //姓名：员工G    工资：11217
    //--------------------------------
    //研发部门的信息：
    //姓名：员工D    工资：17925
    //姓名：员工E    工资：15212
    //姓名：员工H    工资：11444

    //第二次结果：
    //策划部门的信息：
    //没有员工！
    //--------------------------------
    //美术部门的信息：
    //姓名：员工A    工资：14942
    //姓名：员工B    工资：13072
    //姓名：员工C    工资：11216
    //姓名：员工D    工资：17674
    //姓名：员工E    工资：15300
    //姓名：员工G    工资：18717
    //姓名：员工H    工资：11634
    //--------------------------------
    //研发部门的信息：
    //姓名：员工F    工资：18744
    //姓名：员工I    工资：14015
    //姓名：员工J    工资：12681
}

