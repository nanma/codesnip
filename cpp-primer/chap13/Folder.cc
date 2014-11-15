class Folder {
 public:
  Folder() { }
  Folder(const Folder&);
  ~Folder();

  void save(Message&);
  void remove(Message&);

  void addMsg(Message*);
  void remMsg(Message*);
 private:
  std::set<Message*> messages;

  void put_Fldr_in_Messages(const std::set<Message*>&);

  void remove_Fldr_from_Messages();
};

Folder::Folder(const Folder& f):
    messages(f.messages)
{
  put_Fldr_in_Messages(f);
}

void Folder::put_Fldr_in_Messages(const std::set<Message*>& rhs)
{
  for(std::set<Message*>::const_iterator beg = rhs.begin(); beg != rhs.end(); ++beg)
  {
    (*beg)->addFldr(this);
  }
}

Folder& Folder::operator=(const Folder& rhs)
{
  if(&rhs != this) {
    remove_Fldr_from_Messages();
    messages = rhs.messages;
    put_Fldr_in_Messages(rhs.messages);
  }
  return this;
}

void remove_Fldr_from_Messages()
{
  for(std::set<Message*>::const_iterator beg = messages.begin(); beg != messages.end(); ++beg)
  {
    (*beg)->remFldr(this);
  }
}

Foler::~Folder()
{
  remove_Fldr_from_Messages();
}

void Folder::save(Message& msg)
{
  addMsg(&msg);
  msg.addFldr(this);
}

void Folder::remove(Message& msg)
{
  remMsg(&msg);
  msg.remFldr(this);
}

void Folder::addMsg(Message* msg)
{
  messages.insert(msg);
}

void Folder::remMsg(Message* msg)
{
  messages.erase(msg);
}
