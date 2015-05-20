// Author: Sean Davis
#include <iostream>
#include <cstdlib>
#include "list.h"
using namespace std;

int List::count = 0;

template <class T>
ListNode::ListNode(const City &c, ListNode *node) : city(c), next(node)
{
    
}  // ListNode())

template <class T>
List<T>::List() : head(NULL), tail(NULL)
{
} // List()

template <class T>
List<T>::~List()
{
    for (ListNode *ptr = head; ptr; ptr = head)
    {
        head = ptr->next;
        delete ptr;
    }  // for each node
} // ~List()

template <class T>
int List::getCount()
{
    return count;
}  // getCount()

template <class T>
List&  List::operator += (const City &rhs)
{
    if (tail)
        tail = tail->next = new ListNode(rhs, NULL);
    else // an empty list
        head = tail = new ListNode(rhs, NULL);
    
    count++;
    return *this;
}  // operator+=

template <class T>
List& List::operator -= (const City &rhs)
{
    ListNode *ptr, *prev = NULL;
    
    for (ptr = head; ptr && ! (ptr->city == rhs); ptr = ptr->next)
        prev = ptr;
    
    if (ptr)
    {
        count--;
        
        if (!prev)  // found at front of list
        {
            head = ptr->next;
            
            if (!head)  // head == NULL so now empty list
                tail = NULL;
        }  // if removing first node
        else // removing node after the first
        {
            prev->next = ptr->next;
            
            if (tail == ptr)
                tail = prev;
        }  // else removing after the first node
        
        delete ptr;
    }  // if found
    
    return *this;
}  // operator -=

template <class T>
const City& List::operator [] (int index) const
{
    int pos = 0;
    ListNode *ptr;
    
    for (ptr = head; ptr && pos != index; ptr = ptr->next, pos++);
    
    if (!ptr)
    {
        cout << "Error in array indexing!\n";
        exit(1);
    }  // if index beyond end of list
    
    return ptr->city;
}  // const operator[]

template <class T>
City& List::operator [] (int index)
{
    int pos = 0;
    ListNode *ptr;
    
    for (ptr = head; ptr && pos != index; ptr = ptr->next, pos++);
    
    if (!ptr)
    {
        cout << "Error in array indexing!\n";
        exit(1);
    } // if index beyond end of the array.
    
    return ptr->city;
}  // non-const operator[]
