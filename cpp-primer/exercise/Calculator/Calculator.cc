#include "Calculator.h"
#include <stack>
#include <iostream>
#include <vector>

using std::stack;
using std::cout;
using std::endl;
using std::vector;

Calculator::Calculator(const string& exp) {
  string rpExp = buildRPExp(exp);
  cout << rpExp << endl;
  Node * node = buildTree(rpExp);
  cout << "result = " << node->calc() << endl;
}

string Calculator::buildRPExp(const string& exp) {
  stack<char> s1, s2;
  s1.push('#');
  char ch;
  for (int i = 0; i < exp.size(); ++i) {
    cout << "i = " << i << ": ";
    cout << s1.top();
    cout << ";" << s1.size() << ", " << s2.size() << endl;
    switch (exp[i]) {
      case '(':
        s1.push(exp[i]);
        break;
      case ')':
        while (s1.top() != '(') {
          s2.push(s1.top());
          s1.pop();
        }
        s1.pop();
        break;
      case '+':
        ;
      case '-':
        ch = s1.top();
        while (ch != '#') {
          if (ch == '(') {
            break;
          } else {
            s1.pop();
            s2.push(ch);
          }
          ch = s1.top();
        }
        for (ch = s1.top(); s1.top() != '#';) {
          if (ch == '(') {
            break;
          } else {
            s1.pop();
            s2.push(ch);
          }
        }
        s1.push(exp[i]);
        break;
      case '*':
        ;
      case '/':
    	ch = s1.top();
    	while (ch != '+' && ch != '-' && ch != '#') {
          if (ch == '(') {
            break;
          } else {
            s1.pop();
            s2.push(ch);
          }
          ch = s1.top();
    	}
        s1.push(exp[i]);
        break;
      default:
        s2.push(exp[i]);
    }
  }
  while (s1.top() != '#') {
    s2.push(s1.top());
    s1.pop();
  }
  string ret(s2.size(), '\0');
  for (int i = ret.size() - 1; i >= 0; --i) {
    ret[i] = s2.top();
    s2.pop();
  }
  return ret;
}

double Calculator::result() {
  return 0;
}

Node* Calculator::buildTree(const string& exp) {
  stack<Node*> numStack;
  Node *node1, *node2, *node3;
  for (int i = 0; i < exp.size(); ++i) {
    switch (exp[i]) {
      case '+':
        node2 = numStack.top();
        numStack.pop();
        node1 = numStack.top();
        numStack.pop();
        node3 = new AddNode(node1, node2);
        numStack.push(node3);
        break;
      case '*':
        node2 = numStack.top();
        numStack.pop();
        node1 = numStack.top();
        numStack.pop();
        node3 = new MultNode(node1, node2);
        numStack.push(node3);
        break;
      default:
        node1 = new NumNode(exp[i] - '0');
        numStack.push(node1);
        break;
    }
  }
  return numStack.top();
}

int main() {
  Calculator calc("(1+3)*4+(2+2)*3");
  return 0;
}
