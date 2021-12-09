//
// Created by Jarson's mac on 2021/12/9.
//

#ifndef C__STL__MYARRAY_HPP
#define C__STL__MYARRAY_HPP

#endif //C__STL__MYARRAY_HPP

//自己的通用的数组类
#pragma once
#include <iostream>
using namespace std;

template<class T>
class MyArray
{
public:
    //有参构造 参数 为容量
    MyArray(int capacity)
    {
        //cout << "MyArray的有参构造调用" << endl;
        this->m_Capacity = capacity;
        this->m_Size = 0;
        this->pAddress = new T[this->m_Capacity];//开辟堆区空间
    }

    //拷贝构造
    MyArray(const MyArray& arr)
    {
        //cout << "MyArray的拷贝构造调用" << endl;
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        //this->pAddress = arr.pAddress;
        //深拷贝（防止浅拷贝导致的堆区数据重复释放的问题）
        this->pAddress = new T[arr.m_Capacity];
        //将arr中的数据都拷贝过来
        for(int i = 0; i < this->m_Size; i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }
    }

    //operater= 防止浅拷贝问题    返回引用可以做连等操作：a = b = c
    MyArray& operator=(const MyArray& arr)
    {
        //cout << "MyArray的operater=构造调用" << endl;
        //先判断原来堆区是否有数据，如果有先释放
        if(this->pAddress != NULL)
        {
            delete[] this->pAddress;
            this->pAddress = NULL;
            this->m_Capacity = 0;
            this->m_Size = 0;
        }

        //深拷贝
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        this->pAddress = new T[arr.m_Capacity];
        for(int i = 0; i < this->m_Size; i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }
        return *this;
    }

    //尾插法
    void push_back(const T & val)
    {
        //判断容量是否等于大小
        if(this->m_Capacity == this->m_Size) return;
        this->pAddress[this->m_Size] = val;//注意这里不是m_Size - 1是因为插入的位置在当前数组最后一个元素的后一个位置
        this->m_Size++;
    }

    //尾删法
    void pop_back()
    {
        //让用户访问不到最后一个元素，即为尾删，逻辑删除
        if(this->m_Size == 0) return;
        this->m_Size--;
    }

    //通过下标的方式来访问数组中的元素
    // arr[x] = 100;
    //函数调用想作为左值使用，必须返回一个引用
    T& operator[](int index)
    {
        return this->pAddress[index];
    }

    //返回数组的容量
    int getCapacity()
    {
        return this->m_Capacity;
    }

    //返回数组的大小
    int getSize()
    {
        return this->m_Size;
    }

    //析构函数
    ~MyArray()
    {
        if(this->pAddress != NULL)
        {
            //cout << "MyArray的析构函数调用" << endl;
            delete[] this->pAddress;
            this->pAddress = NULL;
        }
    }
private:
    T * pAddress;//指针指向堆区开辟的真实的数组

    int m_Capacity;//数组的容量
    int m_Size;//数组的大小
};