#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys, urllib, json
import os
import shutil
from load_dir import *
import time
import logging
import pdb 

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
  logger = get_log()
  for root, dirs, files in list_dirs:   
    for f in files:
      time.sleep(2)
#      pdb.set_trace()    
      book = os.path.join(root, f)
      logger.info(book)
      ext = f.split('.')[-1]
      if ext == 'jpg' or ext == 'opf':
        logger.info('trash:' + book)
        shutil.move(book, trash_dir)
        continue
      title = f[0:f.rfind('.')]
      size = os.path.getsize(book)
      uniq_name = title + str(size)
      if uniq_name in book_size:
        logger.info('trash:' + book)
        shutil.move(book, trash_dir)
        continue
      book_size.add(uniq_name)
      tags = get_tags(title.replace('-', ' '))
      if tags == []:
        logger.info(book + ': retrieved no tag')
        shutil.move(book, notag_dir)
      for tag in tags:
        if tag in dir_dict.keys():
          des_dir = dir_dict[tag]
          if os.path.exists(os.path.join(des_dir, f)):
            des_size = os.path.getsize(os.path.join(des_dir, f))
            if size == des_size:
              logger.info('trash:' + book)
              if os.path.exists(os.path.join(trash_dir, title + '.' + ext)):
                title = title + '(2)'
                new_book = os.path.join(root, title + '.' + ext)
                os.rename(book, new_book)
                shutil.move(new_book, trash_dir)
              else:
                shutil.move(book, trash_dir)
            else:
              new_book = os.path.join(root, uniq_name + '.' + ext)
              os.rename(book, new_book)
              logger.info(uniq_name + ":" + des_dir)
              shutil.move(new_book, des_dir)
            break
          logger.info(title + ":" + des_dir)
          shutil.move(book, des_dir)
          break
      if os.path.exists(book):
        logger.info('no dir:' + title)
        if os.path.exists(os.path.join(notag_dir, title + '.' + ext)):
          #TODO: add more name here
          title = title + '(2)'
          new_book = os.path.join(root, title + '.' + ext)
          os.rename(book, new_book)
          shutil.move(new_book, notag_dir)
        else:
          shutil.move(book, notag_dir)
      time.sleep(3)
 
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

if __name__ == "__main__":
  main()
