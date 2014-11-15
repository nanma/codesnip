class NotQuery: public Query_base {
  friend Query operator~(const Query &);
  NotQuery(Query q): query(q) { }
  std::set<line_no> eval(const TextQuery&) const;
  std::ostream& display(std::ostream &os) const { return os << "~(" << query << ")"; }
  const Query query;
};

set<TextQuery::line_no> NotQuery::eval(const TextQuery& file) const
{
  set<TextQuery::line_no> has_val = query.eval(file);
  set<line_no> ret_lines;
  for (TextQuery::line_no n = 0; n != file.size(); ++n)
    if ( has_val.find(n) == has_val.end())
      ret_lines.insert(n);
  return ret_lines;
}
