//
// Created by Jarson's mac on 2021/12/7.
//

#include <iostream>
#include <string>
using namespace std;
//类模板中分文件编写及其问题

//第一种解决方式，直接包含源文件
//#include "Person.cpp"

//第二种解决方式，将.h和.cpp中的内容写到一起，将后缀名改为.hpp文件（一般类模板都采用这种方式）
#include "person1.hpp"

void test01()
{
    Person <string, int> p("CaiXiongJiang", 23);
    p.showPerson();
}

int main()
{
    test01();
    return 0;
}