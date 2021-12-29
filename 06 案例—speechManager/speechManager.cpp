//
// Created by Jarson's mac on 2021/12/29.
//

#include "speechManager.h"

//构造函数
SpeechManager::SpeechManager()
{
    //初始化属性
    this->initSpeech();

    //创建12名选手
    this->creatSpeaker();

    //加载往届记录
    this->loadRecord();
}

//菜单功能
void SpeechManager::show_Menu()
{
    cout << "**************************" << endl;
    cout << "*****欢迎参加演讲比赛******" << endl;
    cout << "*****1.开始演讲比赛********" << endl;
    cout << "*****2.查看往届记录********" << endl;
    cout << "*****3.清空比赛记录********" << endl;
    cout << "*****0.退出比赛程序********" << endl;
    cout << "**************************" << endl;
    cout << endl;

}

//退出系统
void SpeechManager::exitSystem()
{
    cout << "欢迎下次使用" << endl;
    exit(0);
}

//初始化容器和属性
void SpeechManager::initSpeech()
{
    //容器都置空
    this->v1.clear();
    this->v2.clear();
    this->vVictory.clear();
    this->m_Speaker.clear();

    //初始化比赛轮数
    this->m_Index = 1;

    //将记录的容器也清空
    this->m_Record.clear();
}

//创建12名选手
void SpeechManager::creatSpeaker()
{
    string nameSeed = "ABCDEFGHIJKL";
    for(int i = 0; i < nameSeed.size(); i++)
    {
        string name = "选手";
        name += nameSeed[i];

        //创建了具体的选手
        Speaker sp;
        sp.m_Name = name;

        for(int j = 0; j < 2; j++)
        {
            sp.m_Score[j] = 0;
        }

        //创建选手编号 并且放到v1容器中
        this->v1.push_back(i + 10001);

        //选手的编号以及对应的选手 放入到map容器中
        this->m_Speaker.insert(make_pair(i + 10001, sp));
    }
}

//开始比赛 比赛整个流程的控制函数
void SpeechManager::startSpeech()
{
    //第一轮开始比赛

    //1.抽签
    this->speechDraw();
    //2.比赛
    this->speechContest();
    //3.显示晋级结果
    this->showScore();
    //第二轮开始比赛
    this->m_Index++;
    //1.抽签
    this->speechDraw();
    //2.比赛
    this->speechContest();
    //3.显示最终结果
    this->showScore();
    //4.保存分数到文件中
    this->saveRecord();

    //重置比赛

    //初始化属性
    this->initSpeech();
    //创建12名选手
    this->creatSpeaker();
    //加载往届记录
    this->loadRecord();

    cout << "本届比赛完毕！" << endl;

}

//抽签
void SpeechManager::speechDraw()
{
    cout << "第<<" << this->m_Index << ">> 轮比赛选手正在抽签" << endl;
    cout << "--------------------------" << endl;
    cout << "抽签后演讲的顺序如下：" << endl;

    if(this->m_Index == 1)
    {
        //第一轮比赛
        random_shuffle(v1.begin(), v1.end());
        for(vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
    else
    {
        //第一轮比赛
        random_shuffle(v2.begin(), v2.end());
        for(vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }

    cout << "---------------------" << endl;
    cout << endl;
}

//比赛
void SpeechManager::speechContest()
{
    cout << "-----第" << this->m_Index << "轮比赛正式开始------" << endl;

    //准备一个临时的容器 存放小组成绩
    multimap<double, int, greater<double>> groupScore;

    int num = 0;//用于统计人员的个数 6人一组

    vector<int> v_Src;//比赛人员的容器
    if(m_Index == 1)
    {
        v_Src = v1;
    }
    else
    {
        v_Src = v2;
    }

    //遍历所有的选手进行比赛
    for(vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
    {
        num++;
        //评委打分
        deque<double> d;
        for(int i = 0; i < 10; i++)
        {
            double score = (rand()%401 + 600) / 10.f; //600~1000
            //cout << score << " ";
            d.push_back(score);
        }
        //cout << endl;

        sort(v_Src.begin(), v_Src.end(), greater<double>());//排序
        d.pop_front();//去除最高分
        d.pop_back();//去除最低分

        double sum = accumulate(d.begin(), d.end(), 0.0f);//总分
        double avg = sum / (double)d.size();    //平均分

        //打印平均分
        //cout << "编号："  << *it << "   姓名：" << this->m_Speaker[*it].m_Name << "   获取平均分：" << avg << endl;

        //将平均分放入到map容器中
        this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;

        //将打分数据 放入临时的小组容器中
        groupScore.insert(make_pair(avg, *it)); //key是得分，value是具体的选手编号
        //每6人取出前三名
        if(num % 6 == 0)
        {
            cout << "第" << num / 6 << "小组比赛名次：" << endl;
            for(multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
            {
                cout << "编号：" << it->second << "  姓名" << this->m_Speaker[it->second].m_Name << "  成绩："
                        << this->m_Speaker[it->second].m_Score[this->m_Index - 1] << endl;
            }
            //取走前3名
            int count = 0;
            for(multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end() && count  < 3; it++, count++)
            {
                if(this->m_Index == 1)
                {
                    v2.push_back((*it).second);
                }
                else
                {
                    vVictory.push_back((*it).second);
                }
            }

            groupScore.clear(); //小组容器要清空
            cout << endl;
        }
    }
    cout << "-----------第" << this->m_Index << "轮比赛完毕----------" <<  endl;
}

//显示成绩
void SpeechManager::showScore()
{
    cout << "----------第" << this->m_Index << "轮晋级选手信息如下：-------------" << endl;

    vector<int> v;
    if(this->m_Index == 1)
    {
        v = v2;
    }
    else
    {
        v = vVictory;
    }

    for(vector<int>::iterator it = v.begin(); it !=v.end(); it++)
    {
        cout << "选手编号：" << *it << "  姓名：" << this->m_Speaker[*it].m_Name << "  得分："
                << this->m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
    }
    cout << endl;
    this->show_Menu();
}

//保存记录
void SpeechManager::saveRecord()
{
    ofstream ofs;
    ofs.open("speech.csv", ios::out | ios::app);   //用追加的方式写文件

    //将每个选手的数据写入到文件中
    for(vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
    {
        ofs << *it << "，" << this->m_Speaker[*it].m_Score[1] << "，";
    }
    ofs << endl;
    //关闭文件
    ofs.close();
    cout << "记录已经保存" << endl;
    //更改文件不为空的状态
    fileIsEmpty = false;
}

//读取记录
void SpeechManager::loadRecord()
{
    ifstream ifs("speech.csv");//读文件
    if(ifs.is_open())
    {
        this->fileIsEmpty = true;
        //cout << "文件不存在" << endl;
        ifs.close();
        return;
    }
    //文件清空的情况
    char ch;
    ifs >> ch;
    if(ifs.eof())
    {
        //cout << "文件为空" << endl;
        fileIsEmpty = true;
        ifs.close();
        return;
    }
    //文件不为空
    this->fileIsEmpty = false;
    ifs.putback(ch);//将上面读取的单个字符 放回来

    string data;
    int index  = 0;

    while (ifs >> data)
    {
        //cout << data << endl;
        //10011，86.7125，10010，82.375，10005，81.4125，

        vector<string> v;//存放6个string字符串
        int pos = -1; //查到"，"位置的变量
        int start = 0;

        while(true)
        {
            pos = data.find("，", start);
            if(pos == -1)
            {
                //没有找到的情况
                break;
            }
            string temp = data.substr(start, pos - start);
            start = pos + 1;
            //cout << temp << endl;
            v.push_back(temp);
        }
        this->m_Record.insert(make_pair(index, v));
        index++;
    }
    ifs.close();
    /*
    for(map<int, vector<string>>::iterator it = this->m_Record.begin(); it != this->m_Record.end(); it++)
    {
        cout << it->first << "冠军编号：" << it->second[0] << "  分数：" << it->second[1] << endl;
    }
     */
}

//显示往届记录
void SpeechManager::showRecord()
{
    if(this->fileIsEmpty)
    {
        cout << "文件为空或者文件不存在" << endl;
    }
    else {
        for (int i = 0; i < this->m_Record.size(); i++) {
            cout << "第" << i + 1 << "届"
                 << "冠军编号：" << this->m_Record[i][0] << "得分：" << this->m_Record[i][1] << " "
                 << "亚军编号：" << this->m_Record[i][2] << "得分：" << this->m_Record[i][3] << " "
                 << "季军编号：" << this->m_Record[i][4] << "得分：" << this->m_Record[i][5] << endl;
        }
    }
}

//清空记录
void SpeechManager::clearRoad()
{
    cout << "是否确定清空文件？" << endl;
    cout << " 1.  是" << endl;
    cout << " 2.  否" << endl;

     int select = 0;
     cin >> select;
     if(select == 1)
     {
         //确认清空
         ofstream ofs("speech.csv", ios::trunc);
         ofs.close();

         //初始化属性
         this->initSpeech();

         //创建12名选手
         this->creatSpeaker();

         //加载往届记录
         this->loadRecord();

         cout << "清空成功！" << endl;
     }
}

//析构函数
SpeechManager::~SpeechManager()
{

}