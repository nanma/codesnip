struct NoName {
  NoName(): pstring(new std::string), i(0), d(0) { }
  NoName(const NoName& orig): i(rog.i), d(orig.d) {
    pstring = new std::string(*(org.pstring));
  }
 private:
  std:: string *pstring;
  int i;
  double d;
}
