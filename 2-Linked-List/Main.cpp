/*
 * Main.cpp
 */
#include <iostream>
#include "CList2.h"

using namespace std;
//TODO: add key EHA to catch all exceptions
void test1() 
{
try{
  cout << "\ntest1. Create lists\n";
   //int nreal;
  // CList2<int> l = CList2<int>();
  // CList2<string> m = CList2<string>();
  // CList2<float> n;
  CList2<ForTest> n;
   cout<<"SUCCESS\n";
    } catch(int err) {cout << "error=" <<err<<endl;}
}
void test2()
{
try{
  cout << "\ntest2. Add items\n";
   CList2<ForTest> n; int j=0; ForTest f;
   for(int i;i!=-1000;j++)
   {cout << "\nДЛЯ ПРЕРЫВАНИЯ ВВЕДИТЕ -1000\nВведите элемент: " ;
    cin >> i;
    f.i=i;
    n.AddAfter(f);}
   
   n.GoToBegin();
   cout << "LIST: \n" ;
    for(int i=0;i<j;i++)
   {cout << n.GetCur() << " "; n.GoToNext();}
    } catch(int err) {cout << "error=" <<err<<endl;}
}
void test3()
{
try{
  cout << "\ntest3. Destructor\n";
  CList2<ForTest> n; //ForTest f;
  //f.i=987;
  //n.AddAfter(f); n.AddAfter(f); n.AddAfter(f);
  n.Clean();
  //n.~CList2();
  cout<<"SUCCESS\n";
    } catch(int err) {cout << "error=" <<err<<endl;}
}

///////////////////////////////////////////
int main()
{ 
  int var;
 cout<<"Список тестов:\n";
 cout << "\ntest1. Create lists\n";
 cout << "\ntest2. Add itemss\n";
 cout << "\ntest3. Destructor\n";
 cout << "\ntest12. Все сразу! \n";
 cout << "\ntest13. Выйти \n";
 cout<<"Введите номер теста:";
 cin>> var;
 switch (var) {
 case 1: test1(); break;
 case 2: test2(); break;
 case 3: test3(); break;
 case 12: test1();test2();test3(); break;
 case 13: break;
   default: break;
 }      
      
 return 0;
}
