#!/usr/bin/python
#-*- encoding: utf-8 -*-    
#cron命令：
#crontab -e
#30 17 * * 1-5 /home/tools/send_daily_report.py >>/home/tools/reportlog.txt 2>&1
#含义：每周1-5的17：30分执行脚本

import smtplib
from email.mime.text import MIMEText
from email.header import Header
import time
import random
import os
import sys

mailto_list=["xxx@yyy.com","zzz@yyy.com"]
mail_host="mail.yyy.com"
mail_user="USER"
mail_pass="PASSWD"
mail_postfix="yyy.com"

def send_mail(to_list,sub,content):
    '''
    to_list:收信人
    sub:主题
    content:内容
    send_mail("name@163.com","sub","content")
    '''
    me=mail_user+"<"+mail_user+"@"+mail_postfix+">"
    msg = MIMEText(content, 'plain','utf-8')
    msg['Subject'] = sub
    msg['From'] = me
    msg['To'] = ";".join(to_list)
    try:
        s = smtplib.SMTP()
        s.connect(mail_host)
        s.login(mail_user,mail_pass)
        s.sendmail(me, to_list, msg.as_string())
        s.close()
        return True
    except Exception, e:
        print str(e)
        return False

def send_report():
    report = get_content()
    content = ""
    index = 1
    for line in report:
        content = content + str(index) + "." + line
        index += 1
    print content
    day_name = {'Mon':'一','Tue':'二','Wed':'三','Thu':'四','Fri':'五','Sat':'六','Sun':'日'}
    en_day_name = time.strftime('%a',time.localtime(time.time()))
    date = time.strftime('%Y年%m月%d日 星期' + day_name[en_day_name], time.localtime(time.time()))
    subject = Header('日报 ' + date, 'utf-8')
    if send_mail(mailto_list, subject, content):
        print "发送成功"
    else:
        print "发送失败"

def get_content():
    contents = open('report.txt', 'r')
    line = contents.readline()
    report = []
    cur_cont = []
    date = time.strftime('%Y年%m月%d日', time.localtime(time.time()))
    while line:
        if line.startswith(date):
            line = contents.readline()
            while line and line != "\n":
                report.append(line)
                line = contents.readline()
            break
        line = contents.readline()
    if report == []:
        report = get_spare_content()
    return report

def get_spare_content():
    contents = open('spare_report.txt', 'r')
    line = contents.readline()
    spare_report = []
    while line:
        spare_report.append(line)
        line = contents.readline()
    size = len(spare_report)
    report = []
    first = random.randint(0, size - 1)
    second = random.randint(0, size - 1)
    if second == first:
        second = (second + 1) % size
    report.append(spare_report[first]);
    report.append(spare_report[second]);
    return report

if __name__ == '__main__':
    os.chdir(os.path.dirname(sys.argv[0]))
    send_report()
