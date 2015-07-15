import mechanize
from mechanize import Browser
import cookielib
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
import time
from bs4 import BeautifulSoup
import requests
import urllib
import math
import time
BASE_URL = "https://www.quora.com"
TOKEN = 'CAACEdEose0cBAHR5FVs8lX18ZB6wRN8kDPBAHMCZBkzQ53q4CgXmII0RsJ2XhJFxTowxfz1DupCECy4WWVgsHYC8e8cs\
mnB8oEw5S6eF937f2ZBWuTZBobEZBJSrZC1Dj094if09ANn1klZCa44JoetjkFMIJRaLUvrRF94ZBj1lLL3tk3uMVzKVSpf6ZBF7CuIUlq5V7anBJiwZDZD'

proxies = {
    'http' : 'http://172.30.0.11:3128',
    'https' : 'https://172.30.0.11:3128'
}

def pre():
	source = open("in.html","rb")
	soup = BeautifulSoup(source)
	val = soup.findAll(attrs = {"class":"question_link"})
	print len(val)
	questions_list = []
	for x in val:
		questions_list.append(x['href'])
	print questions_list
	return questions_list

def go(questions):
	for q in questions:
		url = 'https://graph.facebook.com/660926997282831/feed'
		msg = BASE_URL + q
		print msg
		payload = {'access_token': TOKEN, 'message': msg}
		response = requests.post(url,data=payload,proxies=proxies)
#		rsp = requests.get(url, data = payload1, proxies = proxies)
		print response.url
 #   result1 = json.loads(rsp.text)
#    print result1

if __name__ == "__main__":
	q = pre()
	go(q)
