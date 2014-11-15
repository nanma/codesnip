#include<String>
using std::string;
class Person {
 public:
  Person(const string &nm, const string &addr): name(nm), address(addr) {

  }
  string get_name() const {
    return name;
  }
  string get_address() const {
    return address;
  }
  
 private:
  string name;
  string address;
}
