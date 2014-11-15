class Message {
 public:
  Message(const std::string &""):contents (str) { }
  Message(const Message&);
  Message& operator=(const Message&);
  ~Message();
  void save(Folder&);
  void remove(Folder&);
  void addFldr(Folder*);
  void remFldr(Folder*);
 private:
  std::string contents;
  std::set<Folder*> folders;
  void put_Msg_in_Folders(const std::set<Folder*>&);
  void remove_Msg_from_Folders();
};

Message::Message(const Message &m):
    contents(m.contents), folders(m.folders)
{
  put_Msg_in_Folders(folders);
}

void Message::put_Msg_in_Folders(const set<Folder*> &rhs)
{
  for(std::set<Folder*>::const_iterator beg = rhs.begin(); beg != rhs.end(); ++beg)
  {
    (*beg)->addMsg(this);
  }
}

Message& Message::operator=(const Message &rhs)
{
  if (&rhs != this) {
    remove_Msg_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    put_Msg_in_Folders(rhs.folders);
  }
  return *this;
}

void Message::remove_Msg_from_Folders()
{
  for(std::set<Folder*>::const_iterator beg = folders.begin(); beg != folders.end(); ++beg)
    (*beg)->remMsg(this);
}

void Message::addFldr(Folder* fld)
{
  folders.insert(fld);
}

void Message::remFldr(Folder* fld)
{
  folders.erase(fld);
}

void Message::save(Folder& f)
{
  addFldr(&f);
  f.addMsg(contents);
}

void Message::remove(Folder& f)
{
  remFldr(&f);
  f.remMsg(contents);
}


