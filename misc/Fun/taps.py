'''
This Gives All company details visited NITW until today
@Author: Rohit
'''
# Required headers for mechanize in python
import mechanize
from mechanize import Browser
import cookielib
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

#login as user
r = br.open("http://2013.tapsnitw.org/user/")
for f in br.forms():
    print "gekko"
    print f
br.select_form(nr=1)
br.form['username']='tapsug107254'
br.form['passwd'] = '8885376049'
br.submit()

number = 202
cnt = 0
fname = open("output.txt","wb+")
print "Name\t\tcategory\t\tJob Type\t\tsalary\t\tNo.of.selections"
for num in range(number,number+200):
	main_url = base_url + str(num)
	page = br.open(main_url)
	html = page.read()
	soup = BeautifulSoup(html)
	labels = soup.findAll('table')
	if(len(labels)<5):
		values = soup.findAll('div',attrs={'id' : 'main'})
		str1 = values[0].renderContents().strip()
		if main_str in str1:
			pass
	else:
		company_details = labels[1].findAll('td')
		company_details_2 = labels[2].findAll('td')
		fname.write(company_details[3].renderContents().strip())
		fname.write("\n")
		print company_details[3].renderContents().strip()+"\t\t"+company_details[12].renderContents().strip()+"\t\t"+\
		company_details[15].renderContents().strip()+"\t\t"+company_details_2[2].renderContents().strip()+"\t\t"+\
		company_details_2[14].renderContents().strip()
		cnt = cnt + 1
print "Total Number of Companies visited:",cnt