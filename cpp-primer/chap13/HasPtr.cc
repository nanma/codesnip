class HasPtr {
 public:
  HasPtr(int *p, int i): ptr(p), val(i) { }
  int *get_ptr() const { return ptr; }
  int get_int() const { return val; }
  void set_ptr(int *p) { ptr = p; }
  void set_int(int i) { val = i; }
  int get_ptr_val() const { return *ptr; }
  void set_ptr_val(int val) const { *ptr = val; }
 private:
  int *ptr:
  int val;
}
