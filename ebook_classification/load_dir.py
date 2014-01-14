#!/usr/bin/env python
# -*- coding: utf-8 -*-
import os

BOOK_PATH = 'D:\\百度云同步盘\\01.personal\\book'

def load_dir():
  list_dirs = os.walk(unicode(BOOK_PATH, 'utf8'))
  dir_dict = {}
  for root, dirs, files in list_dirs: 
    for d in dirs:
      if not root.find('01.computer') == -1 or not root.find(unicode('kindle书籍', 'utf8')) == -1:
#        print 'computer'
        continue
      if d not in dir_dict:
        dir_dict[d] = os.path.join(root, d)
  return dir_dict

def main():
  dirs = load_dir()
# for v in dirs.keys():
#    print v + ':' + dirs[v]

if __name__ == "__main__":
  main()
