import mechanize
from mechanize import Browser
import cookielib
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
import time
from bs4 import BeautifulSoup

source = open("in.html","rb")
soup = BeautifulSoup(source)
val = soup.findAll(attrs = {"class":"question_link"})
print len(val)
questions_list = []
for x in val:
	questions_list.append(x['href'])
print questions_list