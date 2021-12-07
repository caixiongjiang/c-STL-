//
// Created by Jarson's mac on 2021/12/7.
//

#ifndef C__STL__PERSON_H
#define C__STL__PERSON_H

#endif //C__STL__PERSON_H

#pragma once
#include <iostream>
using namespace std;

template<class T1, class T2>
class Person
{
public:
    Person(T1 name, T2 age);
    void showPerson();
    T1 m_Name;
    T2 m_Age;
};