//Класс итератор
#ifndef _LISTITERATOR_H_
#define _LISTITERATOR_H_

#include "listnode.h"
#include<string>
#include <memory>

//базовый класс
template <typename T>
class ListIterBase : public std::iterator<std::input_iterator_tag, T>
{
public:
    //конструкторы
    ListIterBase();
    ListIterBase(const ListIterBase<T> &listIter);
    ListIterBase(const std::shared_ptr<ListNode<T>> node);
    //деструктор
    virtual ~ListIterBase() = default;

    //операторы
    ListIterBase<T> &operator=(const ListIterBase<T> &listIter);

    ListIterBase<T> &next();
    ListIterBase<T> &operator++();
    ListIterBase<T> operator++(int);

    bool checkRange() const;

    bool operator==(const ListIterBase<T> &listIter) const;
    bool operator!=(const ListIterBase<T> &listIter) const;

protected:
    std::weak_ptr<ListNode<T>> ptrCur;
};

//класс итератор
template <typename T>
class ListIter : public ListIterBase<T>
{
public:
    ListIter();
    ListIter(const ListIter<T> &listIter);
    ListIter(const std::shared_ptr<ListNode<T>> node);

    ListIter<T> &operator=(const ListIter<T> &listIter);

    T &getCur();
    const T &getCur() const;

    T &getNext();
    const T &getNext() const;

    T &operator*();
    const T &operator*() const;

    T *operator->();
    const T *operator->() const;

    operator bool() const;
};

//класс константный итератор
template <typename T>
class ConstListIter : public ListIterBase<T>
{
public:
    ConstListIter();
    ConstListIter(const ConstListIter<T> &listIter);
    ConstListIter(const std::shared_ptr<ListNode<T>> node);

    ConstListIter<T> &operator=(const ConstListIter<T> &listIter);

    const T &getCur() const;
    const T &getNext() const;
    const T &operator*() const;
    const T *operator->() const;
    operator bool() const;
};

#endif
