#ifndef List_H
#define	List_H

#include "city.h"
#include "list.cpp"

class List;

template <class T>
class ListNode
{
    City data;
    ListNode *next;
    ListNode(const City &c, ListNode *node);
    friend class List;
};  // class ListNode

template <class T>
class  List
{
    ListNode *head;
    ListNode *tail;
    static int count;
public:
    List();
    List(const List& orig);
    ~List();
    static int getCount();
    List&  operator += (const City &rhs);
    List& operator -= (const City &rhs);
    const City& operator [] (int index) const;
    City& operator [] (int index);
    
}; // class List

#endif	// List_H

