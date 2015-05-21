// Author: Jessica Ma
#include <iostream>
#include <cstdlib>
#include "list.h"
using namespace std;

template <typename T>
int List<T>::count = 0;


template <typename T>
ListNode<T>::ListNode(const T &d, ListNode<T> *n) : data(d), next(n)
{
  
}  // ListNode<T>())


template <typename T>
List<T>::List() : head(NULL)
{
} // List<T>()


template <typename T>
List<T>::~List() 
{
  for (ListNode<T> *ptr = head; ptr; ptr = head)
  {
    head = ptr->next;
    delete ptr;
  }  // for each node
} // ~List<T>()


template <typename T>
int List<T>::getCount()
{
  return count;
}  // getCount()

template <typename T>
List<T>&  List<T>::operator += (const T &rhs)
{
    ListNode<T> *ptr, *prev = NULL;
    
    for (ptr = head; ptr && (ptr->data < rhs); ptr = ptr->next)
    {
        prev = ptr;
    } // go through the elements
   
    if (ptr)
    {
        
        if (!prev) // beginning of the list
            head = new ListNode<T>(rhs, ptr);
        else // not beginning of the list
            prev->next = new ListNode<T>(rhs, ptr);
    } // if not at the end of the list
    
    else // end of the list
        if (!prev) // list was empty    
                head = new ListNode<T>(rhs, NULL);
        else // append to end of list
            prev->next = new ListNode<T>(rhs, NULL);
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
      head = ptr->next;
    else // removing node after the first
      prev->next = ptr->next;
    
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
