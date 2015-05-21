#ifndef LIST_H
#define	LIST_H

#include "city.h"

template <typename T>
class List;


template <typename T>
class ListNode
{
  T data;
  ListNode<T> *next;
  ListNode(const T &d, ListNode<T> *n);
  friend class List<T>;
};  // class ListNode


template <typename T>
class List 
{
  ListNode<T> *head;
  static int count;
public:
  List();
  List(const List& orig);
  ~List();
  static int getCount();
 List&  operator += (const T &rhs);
 List& operator -= (const T &rhs);
 const T& operator [] (int index) const;
 T& operator [] (int index);

 template <typename D>
 friend ostream& operator << (ostream &os, const List<D> &rhs);

}; // class List 


#include "list.cpp"

#endif	// LIST_H 

