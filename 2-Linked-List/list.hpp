#ifndef _LIST_HPP_
#define _LIST_HPP_

#include <memory>
#include <ctime>
#include <iterator>
#include <algorithm>

#include "list.h"

template <typename T>
List<T>::List() : head(nullptr), tail(nullptr) {}

template <typename T>
List<T>::List(const List<T> &someList) : head(nullptr), tail(nullptr)
{
    this->extend(someList);
}

template <typename T>
List<T>::List(List<T> &&someList)
{
    this->sizeList = someList->sizeList;
    this->head.reset(someList->head);
    this->tail.reset(someList->tail);

    someList->sizeList = 0;
    someList->head = nullptr;
    someList->tail = nullptr;
}

template <typename T>
List<T>::List(std::initializer_list<T> someList) : head(nullptr), tail(nullptr)
{
    for (const auto &data : someList)
    {
        append(data);
    }
}

template <typename T>
List<T>::List(const T *arr, const int size)
{
    for (int i = 0; i < size; i++)
    {
        this->append(arr[i]);
    }
}

template <typename T>
template <typename T_>
List<T>::List(T_ begin, T_ end)
{
    for (auto it = begin; end != it; ++it)
    {
        this->append(*it);
    }
}

template <typename T>
List<T> &List<T>::operator=(const List &someList)
{
    if (this != &someList)
    {
        this->clear();
        this->extend(someList);
    }

    return *this;
}

template <typename T>
List<T> &List<T>::operator=(List &&someList)
{
    if (this != someList)
    {
        this->clear();
        this->sizeList = someList->sizeList;
        this->head = someList->head;
        this->tail = someList->tail;

        someList->sizeList = 0;
        someList->head = nullptr;
        someList->tail = nullptr;
    }

    return *this;
}

template <typename T>
List<T> &List<T>::operator=(std::initializer_list<T> someList)
{
    if (this != &&someList)
    {
        this->clear();
        this->sizeList = someList->size;
        this->head = someList->begin;
        this->tail = someList->end;

        someList->size = 0;
        someList->begin = nullptr;
        someList->end = nullptr;
    }

    return *this;
}

template <typename T>
List<T> &List<T>::append(const T &data)
{
    std::shared_ptr<ListNode<T>> newNode = initNode(data);

    if (this->isEmpty())
    {
        this->head = newNode;
    }
    else
    {
        this->tail->setNext(newNode);
    }
    this->tail = newNode;

    return *this;
}

template <typename T>
List<T> &List<T>::operator+=(const T &data)
{
    this->append(data);
    return *this;
}

template <typename T>
List<T> &List<T>::add(const T &data) const
{
    List<T> newList(*this);
    newList.append(data);
    return newList;
}

template <typename T>
List<T> List<T>::operator+(const T &data) const
{
    return *this->add(data);
}

template <typename T>
T List<T>::operator[](const size_t i) 
{
    time_t t_time = time(NULL);
    std::shared_ptr<ListNode<T>> curNode = this->head;
    std::shared_ptr<ListNode<T>> tmp = nullptr;
    ListIter<T> cur = this->begin();

    for (size_t j=0; j<i && curNode && cur != this->end(); tmp = curNode, curNode = curNode->getNext(), cur.next(), j++)
        ;
    if (curNode == nullptr)
    {
        throw ListRangeError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    return tmp->getData();
}

template <typename T>
List<T> &List<T>::insert(const T &data, const ListIter<T> &iter)
{
    time_t t_time = time(NULL);
    std::shared_ptr<ListNode<T>> curNode = this->head;
    std::shared_ptr<ListNode<T>> tmp = nullptr;
    ListIter<T> cur = this->begin();

    if (this->head == nullptr && cur == iter)
    {
        std::shared_ptr<ListNode<T>> newNode = initNode(data);
        this->head = newNode;
        this->tail = newNode;
        return *this;
    }

    for (; curNode && cur != iter; tmp = curNode, curNode = curNode->getNext(), cur.next())
        ;

    if (curNode == nullptr)
    {
        throw ListRangeError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }

    std::shared_ptr<ListNode<T>> newNode = initNode(data, curNode);

    if (curNode == this->head)
    {
        this->head = newNode;
    }
    else
    {
        tmp->setNext(newNode);
    }

    return *this;
}

template <typename T>
List<T> &List<T>::extend(const List &ListToAdd)
{
    if (ListToAdd.isEmpty())
    {
        return *this;
    }

    if (this == &ListToAdd)
    {
        List<T> ListCopy;
        ListCopy = ListToAdd;
        addList(ListCopy);
    }
    else
    {
        addList(ListToAdd);
    }

    return *this;
}

template <typename T>
List<T> &List<T>::operator+=(const List<T> &someList)
{
    this->extend(someList);
    return *this;
}

template <typename T>
List<T> &List<T>::addlist(const List<T> &someList) const
{
    List<T> newList(*this);
    newList.extend(someList);
    return newList;
}

template <typename T>
List<T> List<T>::operator+(const List<T> &someList) const
{
    return *this->addlist(someList);
}

template <typename T>
const T List<T>::pop()
{
    time_t t_time = time(NULL);
    if (this->isEmpty())
    {
        throw ListEmptyError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }

    ListIter<T> iter = this->end();
    return remove(iter);
}

template <typename T>
const T List<T>::remove(const ListIter<T> &iter)
{
    time_t t_time = time(NULL);
    if (this->isEmpty())
    {
        throw ListEmptyError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }

    std::shared_ptr<ListNode<T>> curNode = this->head;
    std::shared_ptr<ListNode<T>> tmp = nullptr;
    ListIter<T> cur = this->begin();

    for (; curNode && cur != iter; tmp = curNode, curNode = curNode->getNext(), cur.next())
        ;

    if (curNode == nullptr)
    {
        throw ListRangeError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }

    T retData = iter.getCur();

    if (curNode->getNext() == nullptr)
    {
        this->tail = tmp;
    }

    if (curNode == this->head)
    {
        this->head = this->head->getNext();
    }
    else
    {
        tmp->setNext(curNode->getNext());
    }
    this->sizeList -= 1;

    return retData;
}

template <typename T>
void List<T>::sort()
{
    T *arr=new T[this->size()];
    size_t s = this->size();
    time_t t_time = time(NULL);
    std::shared_ptr<ListNode<T>> curNode = this->head;
    std::shared_ptr<ListNode<T>> tmp = nullptr;
    ListIter<T> cur = this->begin();

    for (size_t i=0; i<this->size() && curNode && cur != this->end(); tmp = curNode, curNode = curNode->getNext(), cur.next(), i++)
        arr[i]=curNode->getData();
    
    if (curNode == nullptr)
    {
        throw ListRangeError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    
    std::sort(arr, arr+this->size());
    this->clear();
    List<T> g(arr,s);
    addList(g);
    delete [] arr;
    //return *this;
}

template <typename T>
List<T> &List<T>::clear()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->sizeList = 0;

    return *this;
}

template <typename T>
bool List<T>::isEqual(const List<T> &someList) const
{
    return isNodesEqual(someList);
}

template <typename T>
bool List<T>::operator==(const List &someList) const
{
    return isNodesEqual(someList);
}

template <typename T>
bool List<T>::isNotEqual(const List<T> &someList) const
{
    return !isNodesEqual(someList);
}

template <typename T>
bool List<T>::operator!=(const List &someList) const
{
    return !isNodesEqual(someList);
}

template <typename T>
ListIter<T> List<T>::begin()
{
    return ListIter<T>(head);
}

template <typename T>
ListIter<T> List<T>::end()
{
    return ListIter<T>(tail);
}

template <typename T>
ConstListIter<T> List<T>::begin() const
{
    return c_begin();
}

template <typename T>
ConstListIter<T> List<T>::end() const
{
    return c_end();
}

template <typename T>
ConstListIter<T> List<T>::c_begin() const
{
    return ConstListIter<T>(head);
}

template <typename T>
ConstListIter<T> List<T>::c_end() const
{
    return ConstListIter<T>(tail);
}

template <typename T>
std::shared_ptr<ListNode<T>> List<T>::initNode(const T &data, std::shared_ptr<ListNode<T>> ptrNode)
{
    time_t t_time = time(NULL);
    std::shared_ptr<ListNode<T>> newNode;
    newNode = std::make_shared<ListNode<T>>();
    if (!newNode)
    {
        throw ListMemoryError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    newNode->setData(data);
    newNode->setNext(ptrNode);
    this->sizeList += 1;

    return newNode;
}

template <typename T>
void List<T>::addList(const List &ListToAdd)
{
    T data = ListToAdd.head->getData();
    std::shared_ptr<ListNode<T>> nextNode = ListToAdd.head->getNext();
    std::shared_ptr<ListNode<T>> nodeToAdd = initNode(data, nextNode);
    std::shared_ptr<ListNode<T>> cur = this->head;

    if (this->isEmpty())
    {
        cur = nodeToAdd;
        this->head = cur;
    }
    else
    {
        for (; cur->getNext(); cur = cur->getNext())
            ;
        cur->setNext(nodeToAdd);
        cur = cur->getNext();
    }

    std::shared_ptr<ListNode<T>> curToAdd = nextNode;

    for (; curToAdd; curToAdd = curToAdd->getNext(), cur = cur->getNext())
    {
        data = curToAdd->getData();
        nextNode = curToAdd->getNext();
        nodeToAdd = initNode(data, nextNode);
        cur->setNext(nodeToAdd);
    }
    this->tail = nodeToAdd;
}

template <typename T>
bool List<T>::isNodesEqual(const List<T> &someList) const
{
    std::shared_ptr<ListNode<T>> curL = this->head;
    std::shared_ptr<ListNode<T>> curR = someList.head;
    for (; curL && curR && curL->getData() == curR->getData();)
    {
        curL = curL->getNext();
        curR = curR->getNext();
    }

    return (curL == nullptr && curR == nullptr) ? true : false;
}

template <typename T>
bool List<T>::isEmpty() const
{
    return (this->head == nullptr) ? true : false;
}

template <typename T>
std::ostream &operator<<(std::ostream &stream, List<T> &list)
{
    stream << "List";
    ListIter<T> iter = list.begin();
    if (!iter.checkRange())
    {
        stream << " is empty";
    }
    else
    {
        stream << ":";
        for (; iter.checkRange(); iter.next())
        {
            stream << " " << iter.getCur();
        }
    }

    return stream;
}

#endif
