'''
Facebook and quora
alas atleast selenium works
but very very very very slowwwwww
i have to find an alternative or methods to make selenium faster
@Author: Rohit
'''
# Required headers for mechanize in python
import mechanize
from mechanize import Browser
import cookielib
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support.ui import Select
from selenium.common.exceptions import NoSuchElementException, WebDriverException
import unittest, re, urllib2
import time
from bs4 import BeautifulSoup
base_url = "http://2013.tapsnitw.org/visits/details/"
main_str = "The visit is not in DB"
# Browser
br = mechanize.Browser()

# Cookie Jar
cj = cookielib.LWPCookieJar()
br.set_cookiejar(cj)

# Browser options
br.set_handle_equiv(True)
#br.set_handle_gzip(True)
br.set_handle_redirect(True)
br.set_handle_referer(True)
br.set_handle_robots(False)

# Follows refresh 0 but not hangs on refresh > 0
br.set_handle_refresh(mechanize._http.HTTPRefreshProcessor(), max_time=1)

# Want debugging messages?
#br.set_debug_http(True)
#br.set_debug_redirects(True)
#br.set_debug_responses(True)

# User-Agent (this is cheating, ok?)
br.addheaders = [('User-agent', 'Mozilla/5.0 (X11; U; Linux i686; en-US; rv:1.9.0.1) Gecko/2008071615 Fedora/3.0.1-1.fc9 Firefox/3.0.1')]
# End Headers

class quoraBrowser():
	def __init__(self,URL):
		#Append "?share=1" to the end of URL to bypass login popup
		self.pageURL = URL + "?share=1"
	def getSource(self):
		#Launch Firefox Driver
		try:
			driver = webdriver.PhantomJS('/usr/bin/phantomjs')
			print "Launching User's Quora Page"
			#Acess webpage and scroll down to generate most recent content
			driver.get(self.pageURL)
			print "Populating page by scrolling down"
			for i in range(0,2):
				print "iam here"
				driver.execute_script("window.scrollTo(0,document.body.scrollHeight);")
			#Get page source code
			print "iam just out"
			html_source = driver.page_source
			print "iam going to out"
			html_source = html_source.encode("ascii","ignore")
			print "iam out"
			driver.close()
			print "get the hell out of here"
			return html_source
		except WebDriverException:
			driver = webdriver.PhantomJS('/usr/bin/phantomjs')
			print "Launching User's Quora Page"
			#Acess webpage and scroll down to generate most recent content
			driver.get(self.pageURL)
			print "Populating page by scrolling down"
			for i in range(0,2):
				print "iam here"
				driver.execute_script("window.scrollTo(0,document.body.scrollHeight);")
			#Get page source code
			print "iam just out"
			html_source = driver.page_source
			print "iam going to out"
			html_source = html_source.encode("ascii","ignore")
			print "iam out"
			driver.close()
			print "get the hell out of here"
			return html_source
		else:
			pass

class quoraParser():
	def __init__(self,data):
		#save the source code as a variable
		self.source = data + ""
	def findQuestions(self):
		soup = BeautifulSoup(self.source)
#		print soup
		val = soup.findAll(attrs = {"class":"question_link"})
		print len(val)
		questions_list = []
		for x in val:
			questions_list.append(x['href'])
		return questions_list

check = quoraBrowser('http://www.quora.com/Rohit-Uppala/')
source = check.getSource()
parser = quoraParser(source)
questions = parser.findQuestions()
print questions