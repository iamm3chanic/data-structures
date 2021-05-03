/*Класс, наследующий класс ListBase*/
#pragma once
#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>
#include <stdarg.h>
#include <iterator>

#include "errors.h"
#include "listbase.h"
#include "listnode.h"
#include "listiterator.h"

template <typename T>
class List : public ListBase
{
public:
    //конструкторы
    List();
    explicit List(const List<T> &someList);
    List(List<T> &&someList);
    List(std::initializer_list<T> someList);
    List(const T *arr, const int size);
    template <typename T_>
    List(T_ begin, T_ end);
    //деструктор
    virtual ~List() = default;

    //операторы
    List<T> &operator=(const List<T> &someList);
    List<T> &operator=(List<T> &&someList);
    List<T> &operator=(std::initializer_list<T> someList);

    List<T> &append(const T &data);
    List<T> &operator+=(const T &data);
    List<T> &add(const T &data) const;
    List<T> operator+(const T &data) const;

    List<T> &insert(const T &data, const ListIter<T> &iter);

    List<T> &extend(const List<T> &ListToAdd);
    List<T> &operator+=(const List<T> &someList);
    List<T> &addlist(const List<T> &someList) const;
    List<T> operator+(const List<T> &somelist) const;
    
    T operator[](const size_t i) ;

    //удалить элемент с конца
    const T pop();

    //удалить элемент с места, куда указывает итератор
    const T remove(const ListIter<T> &iter);
    
    //сортировка
    void sort();

    //очистка списка
    List<T> &clear();

    bool isEqual(const List<T> &someList) const;
    bool operator==(const List<T> &someList) const;
    bool isNotEqual(const List<T> &someList) const;
    bool operator!=(const List<T> &someList) const;

    //итераторы
    ListIter<T> begin();
    ListIter<T> end();
    ConstListIter<T> begin() const;
    ConstListIter<T> end() const;
    ConstListIter<T> c_begin() const;
    ConstListIter<T> c_end() const;
    
    //friend std::ostream &operator<<(std::ostream &stream, List<T> &list);
     

private:
    //указатели на начало и конец списка
    std::shared_ptr<ListNode<T>> head;
    std::shared_ptr<ListNode<T>> tail;

    //создание узла
    std::shared_ptr<ListNode<T>> initNode(const T &data, std::shared_ptr<ListNode<T>> ptrNode = nullptr);
    //создание списка
    void addList(const List<T> &ListToAdd);
    //сравнение для оператора =
    bool isNodesEqual(const List<T> &someList) const;
    //проверка, пуст ли список
    bool isEmpty() const;
};

#endif
