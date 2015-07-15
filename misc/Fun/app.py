'''
for some pages full profile is coming
but for some pages only public profile is coming
why???
'''

import requests
import json
import urllib

TOKEN = 'CAACEdEose0cBAP7eHe4Cg8qCFyFYFm5g87grr8lrMG3RnGfAa82DDzhwzUwDFCXkuB4eR8NtPgRtqXGtLT\
gpLCtQchVUUU2kfwefPDYWF1HXpwhPMXo02vmjud3Ok9SLwNEB1ne79x0qBuzTFDTtmKsJ9DBkanp3Q6tZA33XsN0ThewD2tqO5S4G896IZD'


def get_movies():
    query = ("SELECT music FROM user WHERE uid = 100001504719462")
    payload = {'q':query,'access_token': TOKEN}
    response = requests.get('https://graph.facebook.com/fql', params=payload, proxies = proxies)
    result = json.loads(response.text)
    print result
    return result['data']

def save_movies(dt):
    print dt

def check():
    url = 'https://graph.facebook.com/me/friends'
    payload = {'access_token': TOKEN}
    response = requests.get(url,params=payload)
    result = json.loads(response.text)
    print result
    return result['data']

def check2(p):
    query = "SELECT music from user where uid = " + p
    print query
    payload = {'q':query,'access_token': TOKEN}
    response = requests.get('https://graph.facebook.com/fql', params=payload, proxies = proxies)
    result = json.loads(response.text)
    print result
    return result['data']

if __name__ == '__main__':
    #save_movies(get_movies())
    x = check()
    print len(x)
    for i in range(0,len(x)):
        p = x[i]['id']
        check2(p)
