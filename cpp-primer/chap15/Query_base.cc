class Query_base {
  friend class Query;
 protected:
  typedef TextQuery::line_no line_no;
  virtual ~Query_base() { }
 private:
  virtual std::set<line_no> eval(const TextQuery&) const = 0;
  virtual std::ostream& display(std::ostream& = std::cout) const = 0;
};

