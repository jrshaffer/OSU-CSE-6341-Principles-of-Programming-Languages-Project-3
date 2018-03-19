#ifndef NODE_H
#define NODE_H
#include <string>

using namespace std;

// structure to represent node
struct node
{
  string value;
  string type;
  string atom;
  bool list;
  node *left;
  node *right;
};

#endif
