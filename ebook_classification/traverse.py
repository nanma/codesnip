#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys, urllib, json
import os
import shutil
import time
import logging
import pdb

from load_dir import *
from send2trash import send2trash

LOG_FILENAME = './ebook.log'
SRC_PATH = 'D:/百度云同步盘/book/kindle书籍'
TRASH_DIR = 'D:/trash/'
NOTAG_DIR = 'D:/notag/'

def get_tags(name):
  url = 'http://api.douban.com/v2/book/search?q=' + urllib.quote(name.encode('utf8'))
  wp = urllib.urlopen(url)
  content = wp.read()
  value = json.loads(content)
  keys = value.keys()
  tags = []
  if len(value['books'])!= 0:
    for tag in value['books'][0]['tags']:
      tags.append(tag['name'])
  return tags

def traverse(dir_dict):
  path = SRC_PATH
  trash_dir = TRASH_DIR
  notag_dir = NOTAG_DIR
  list_dirs = os.walk(unicode(path, 'utf8'))
  book_size = set()
#  logger = get_log()
  for root, dirs, files in list_dirs:   
    for f in files:
#      pdb.set_trace()    
      book = os.path.join(root, f)
#      logger.info(book)
      title = f[0:f.rfind('.')]
      ext = f.split('.')[-1]
      if ext == 'jpg' or ext == 'opf':
        logger.info('trash:' + book)
        mv_file(f, root, trash_dir)
        continue
      tags = get_tags(title.replace('-', ' '))
      if tags == []:
        logger.info(book + ': retrieved no tag')
        mv_file(f, root, notag_dir)
      for tag in tags:
        if tag in dir_dict.keys():
          des_dir = dir_dict[tag]
          mv_file(f, root, des_dir)
          break
      if os.path.exists(book):
        mv_file(f, root, notag_dir)
      time.sleep(2)

def mv_file(f, src_dir, des_dir):
  title = f[0:f.rfind('.')]
  book = os.path.join(src_dir, f)
  if os.path.exists(os.path.join(des_dir, f)):
    size = os.path.getsize(book)
    des_size = os.path.getsize(os.path.join(des_dir, f))
    if size == des_size:
      logger.info('delete:' + book)
      send2trash(book)
    else:
      ext = f.split('.')[-1]
      uniq_name = title + str(size) + '.' + ext
      if (os.path.exists(os.path.join(des_dir, uniq_name))):
        logger.info('delete:' + book)
        send2trash(book)
      else:
        new_book = os.path.join(src_dir, uniq_name)
        os.rename(book, new_book)
        logger.info(uniq_name + ":" + des_dir)
        shutil.move(new_book, des_dir)
  else:
    logger.info(f + ":" + des_dir)
    shutil.move(book, des_dir)
 
def get_log():
  logger = logging.getLogger('logger')
  logger.setLevel(logging.DEBUG)
  fh = logging.FileHandler(LOG_FILENAME)
  fh.setLevel(logging.DEBUG)
  ch = logging.StreamHandler()
  ch.setLevel(logging.DEBUG)
  formatter = logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s')
  fh.setFormatter(formatter)
  ch.setFormatter(formatter)
  logger.addHandler(fh)
  logger.addHandler(ch)
  logger.info('start')  
  return logger
  
def main():
#  tags = get_tags('三国演义')
#  for tag in tags:
#    print tag
  dirs = load_dir()
#  for v in dirs.keys():
 #   print v + ':' + dirs[v]
  traverse(dirs)

logger = get_log()

if __name__ == "__main__":
  main()
