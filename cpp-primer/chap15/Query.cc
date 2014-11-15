class Query {
  friend Query operator~(const Query&);
  friend Query operator|(const Query&, const Query&);
  friend Query operator&(const Query&, const Query&);
 public:
  Query(const std::string&);
  Query(const Query &c): q(c.q), use(c.use) { ++*use; }
  ~Query() { decr_use(); }
  Query& operator=(const Query&);
  std::set<TextQuery::line_no> eval(const TextQuery &t) const { return q->eval(t); }
  std::ostream &display(std::ostream &os) const {return q->display(os); }
 private:
  Query(Query_base *query) : q(query), use(new std::size_t(1)) { }
  Query_base *q;
  std::size_t *use;
  void decr_use() { if (--*use == 0 ) { delete q, delete use; } }
};

inline Query operator&(const Query &lhs, const Query &rhs)
{
  return new AndQuery(lhs, rhs);
}

inline Query operator|(const Query &lhs, const Query &rhs)
{
  return new OrQuery(lhs, rhs);
}

inline Query operator~(const Query &oper)
{
  return new NotQuery(oper);
}

inline std::ostream& operator<<(std::ostream &os, const Query &q)
{
  return q.display(os);
}
