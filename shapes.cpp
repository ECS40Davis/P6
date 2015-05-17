// File:   main.cpp
// Author: l0v379o8
//
// Created on May 16, 2015, 2:15 PM

#include <cstdlib>
#include <cstdio>
#include <iostream>
using namespace std;


class Shape
{
public:
  Shape(){};  
  friend ostream& operator << (ostream &os, const Shape &shape)
  {
      return os << shape.write();
  } // operator<<
  
  virtual const char* write()const = 0;
}; // class Shape


class IntersectingLines: public Shape 
{
public:
  IntersectingLines(){};
  const char* write()const
  {
      return "    /\\    \n\
   /  \\   \n\
  /    \\  \n\
 /      \\ \n\
/        \\\n";
  }; // write intersecting lines
  
}; // class IntersectingLines


class BaseLine: public Shape
{
public:
  BaseLine(){};
  const char* write()const
  {
        return "----------\n";
  }; // write baseline
  
}; // class BaseLine


class ParallelLines: public Shape
{
public:
  ParallelLines(){};
  const char* write()const
  {
    return "|        |\n\
|        |\n\
|        |\n";
  }; // write parallel lines
  
}; // class ParallelLines


class BlankLines: public Shape
{
public:
  BlankLines(){};
  const char* write()const
  {
      return "\n\n\n";
  }; // write blank lines
  
}; // class BlankLines


class Circle: public Shape
{
public:
  Circle(){};
  const char* write()const
  {
      return "    *     \n\
  *   *   \n\
   * *    \n";
  }; // write circle
  
}; // class Circle


int main(int argc, char** argv)
{
    Shape *shapes[9];
    IntersectingLines intersectlin;
    BaseLine baselin;
    ParallelLines parallellin;
    BlankLines blankelin;
    Circle circl;
    shapes[0] = &intersectlin;
    shapes[1] = &baselin;
    shapes[2] = &parallellin;
    shapes[3] = &baselin;
    shapes[4] = &blankelin;
    shapes[5] = &circl;
    shapes[6] = &intersectlin;
    shapes[7] = &baselin;
    shapes[8] = &intersectlin;

    for (int i = 0; i < 9; i++)
    {
        cout << *shapes[i];
    } // print all elements
    
    return 0;
} // main
