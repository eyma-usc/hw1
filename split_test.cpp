#include<iostream>
#include "split.h"
using namespace std;


int main(int argc, char *argv[])
{

  Node* node5 = new Node(6, nullptr);
  Node* node4 = new Node(2, node5);
  Node* node3 = new Node(3, node4);
  Node* node2 = new Node(1, node3);
  Node* node1 = new Node(4, node2);
  Node* in = node1;

  Node* odds = nullptr;
  Node* evens = nullptr;

  split(in, odds, evens);
  int count = 1;

  cout << "odds" << endl;
  while(odds != nullptr)
  {
    cout << count << ": " << odds->value << endl;
    odds = odds->next;
    count++;
  }
  count = 1;

    cout << "evens" << endl;
  while(evens != nullptr)
  {
    cout << count << ": " << evens->value << endl;
    evens = evens->next;
    count++;

  }
  delete node1;
  delete node2;
  delete node3;
  delete node4;
  delete node5;

}