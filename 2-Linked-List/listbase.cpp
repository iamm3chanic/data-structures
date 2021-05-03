#ifndef _LISTBASE_CPP_
#define _LISTBASE_CPP_

#include "listbase.h"

ListBase::ListBase() : sizeList(0) {}

ListBase::~ListBase() = default;

size_t ListBase::size() const
{
    return sizeList;
}

#endif //_LISTBASE_CPP_
