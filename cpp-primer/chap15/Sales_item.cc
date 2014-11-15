class Sales_item {
 public:
  Sales_item(): p(0), use(new std::size_t(1)) { }
  Sales_item(const Item_base&);
  Sales_item(const Sales_item &i): p(i.p), use(i.use) { ++*use; }
  ~Sales_item() { decr_use(); }
  Sales_item& operator=(const Sales_item&);
  const Item_base *operator->() const {
    if (p)
      return p;
    else
      throw std::logic_error("unbound Sales_item");
  }
  const Item_base &operator*() const {
    if (p)
      return *p;
    else
      throw std::logic_error("unbound Sales_item");
  }
 private:
  Item_base *p;
  std::size_t *use;
  void decr_use() { if (--*use == 0) {delete *p; delete use; } }
};

Sales_item& Sales_item::operator=(const Sales_item &rhs)
{
  ++*rhs.use;
  decr_use();
  p = rhs.p;
  use = rhs.use;
  return *this;
}

