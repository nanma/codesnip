#include <cstring>
#include <algorithm>

class Istring {
public:
  Istring(): data_(new char[1]) {
    *data_ = '\0';
  }

  Istring(const char* str): data_(new char[strlen(str) + 1]) {
    strcpy(data_, str);
  }

  Istring(const Istring& rhs): data_(new char[rhs.size() + 1]) {
    strcpy(data_, rhs.c_str());
  }

  ~Istring() {
    delete[] data_;
  }

  Istring& operator=(Istring rhs) {
    swap(rhs);
    return *this;
  }

  size_t size() const {
    return strlen(data_);
  }

  const char* c_str() const {
    return data_;
  }

  void swap(Istring& rhs) {
    std::swap(data_, rhs.data_);
  }
  
private:
  char* data_;
  
};
