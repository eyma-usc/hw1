/* Write your test code for the ULListStr in this file */

#include <iostream>
#include "ulliststr.h"
#include "ulliststr.cpp"
using namespace std;


int main(int argc, char* argv[])
{
  ULListStr dat;

  dat.push_back("0");
  dat.push_back("1");
  dat.push_back("2");
  dat.push_back("3");
  dat.push_back("4");
  dat.push_back("5");
  dat.push_front("ooga");
  dat.push_front("booga");
  dat.push_front("hooga");
  dat.push_front("googa");
  dat.push_back("6");
  dat.push_back("7");
  dat.push_back("8");
  dat.push_back("9");
  dat.push_back("10");
  dat.push_back("11");
  dat.push_front("tooga");
  dat.push_front("sooga");
  dat.push_front("wooga");
  dat.push_front("pooga");
  dat.push_back("12");
  dat.push_back("13");
  dat.push_back("14");
  dat.push_back("15");
  dat.pop_back();
  dat.pop_back();
  dat.pop_back();
  dat.pop_front();
  dat.pop_front();
  dat.pop_front();
  dat.pop_front();
  dat.pop_front();
  dat.pop_front();  
  dat.pop_front();
  dat.pop_front();


  cout << dat.get(1) << endl;
  cout << dat.get(2) << endl;
  cout << dat.get(3) << endl;
  cout << dat.get(4) << endl;
  cout << dat.get(5) << endl;
  cout << dat.get(6) << endl;
  cout << dat.get(7) << endl;
  cout << dat.get(8) << endl;
  cout << dat.get(9) << endl;
  cout << dat.get(10) << endl;
  cout << dat.get(11) << endl;
  cout << dat.get(12) << endl;
  


  return 0;
}
