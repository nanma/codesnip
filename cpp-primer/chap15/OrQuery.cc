class OrQuery: public BinaryQuery {
  friend Query operator|(const Query&, const Query&);
  OrQuery(Query left, Query right): BinaryQuery(left, right, "|") { }
  std::set<line_no> eval(const TextQuery&) const;
};

set<TextQuery::line_no> OrQuery::eval(const TextQuery& file) const
{
  set<line_no> right = rhs.eval(file),
           ret_lines = lhs.eval(file);
  ret_lines.insert(right.begin(), right.end());
  return ret_lines;
}
