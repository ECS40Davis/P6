// File:   main.cpp
// Author: l0v379o8
//
// Created on May 16, 2015, 2:15 PM

#include <iostream>
using namespace std;


class Shape
{
public:
  friend ostream& operator << (ostream &os, Shape &shape)
  {
      shape.write();
      return os;
  } // operator<<
  
  virtual void write() = 0;
}; // class Shape


class IntersectingLines: public Shape 
{
public:
  IntersectingLines(){};
  void write()
  {
      cout << "    /\\\n\
   /  \\\n\
  /    \\\n\
 /      \\\n\
/        \\\n";
  }; // write intersecting lines
  
}; // class IntersectingLines


class BaseLine: public Shape
{
public:
  BaseLine(){};
  void write()
  {
        cout << "----------\n";
  }; // write baseline
  
}; // class BaseLine


class ParallelLines: public Shape
{
public:
  ParallelLines(){};
  void write()
  {
    cout << "|        |\n\
|        |\n\
|        |\n";
  }; // write parallel lines
  
}; // class ParallelLines


class BlankLines: public Shape
{
public:
  BlankLines(){};
  void write()
  {
      cout << "\n\n";
  }; // write blank lines
  
}; // class BlankLines


class Circle: public Shape
{
public:
  Circle(){};
  void write()
  {
      cout << "    *\n\
  *   *\n\
   * *\n";
  }; // write circle
  
}; // class Circle


int main(int argc, char** argv)
{
//    cout << "1\n";
    Shape *shapes[9];
    IntersectingLines intersectlin;
    BaseLine baselin;
    ParallelLines parallellin;
    BlankLines blankelin;
    Circle circl;
//    cout << "2\n";
    shapes[0] = &intersectlin;
    shapes[1] = &baselin;
    shapes[2] = &parallellin;
    shapes[3] = &baselin;
    shapes[4] = &blankelin;
    shapes[5] = &circl;
    shapes[6] = &intersectlin;
    shapes[7] = &baselin;
    shapes[8] = &intersectlin;
//    cout << "3\n";

    for (int i = 0; i < 9; i++)
    {
        cout << *shapes[i];
    } // print all elements
    
//    cout << "4\n";
    return 0;
} // main
