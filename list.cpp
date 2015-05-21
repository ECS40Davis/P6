// Author: Jessica Ma
#include <iostream>
#include <cstdlib>
#include "list.h"
using namespace std;

template <typename T>
int List<T>::count = 0;

// ListNode::ListNode(const City &c, ListNode *node) : city(c), next(node)
template <typename T>
ListNode<T>::ListNode(const T &d, ListNode<T> *n) : data(d), next(n)
{
  
}  // ListNode())


template <typename T>
List<T>::List() : head(NULL), tail(NULL) 
{
} // List()


template <typename T>
List<T>::~List() 
{
  for (ListNode<T> *ptr = head; ptr; ptr = head)
  {
    head = ptr->next;
    delete ptr;
  }  // for each node
} // ~List()


template <typename T>
int List<T>::getCount()
{
  return count;
}  // getCount()

template <typename T>
List<T>&  List<T>::operator += (const T &rhs)
{
  if (tail)
    tail = tail->next = new ListNode<T>(rhs, NULL);
  else // an empty list
    head = tail = new ListNode<T>(rhs, NULL);
  
  count++;
  return *this;
}  // operator+=


// only changed city to data?
template <typename T>
List<T>& List<T>::operator -= (const T &rhs)
{
  ListNode<T> *ptr, *prev = NULL;
  
  for (ptr = head; ptr && ! (ptr->data == rhs); ptr = ptr->next)
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


template <typename T>
const T& List<T>::operator [] (int index) const
{
  int pos = 0;
  ListNode<T> *ptr;
  
  for (ptr = head; ptr && pos != index; ptr = ptr->next, pos++);
   
  if (!ptr)
  {
     cout << "Error in array indexing!\n";
     exit(1);
  }  // if index beyond end of list

  return ptr->data; 
}  // const operator[]
 
 
template <typename T>
T& List<T>::operator [] (int index)
{
  int pos = 0;
  ListNode<T> *ptr;
   
  for (ptr = head; ptr && pos != index; ptr = ptr->next, pos++);
   
  if (!ptr)
  {
    cout << "Error in array indexing!\n";
    exit(1);
  } // if index beyond end of the array.

  return ptr->data; 
}  // non-const operator[]
