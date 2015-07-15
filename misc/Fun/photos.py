import requests
import json
import urllib

TOKEN = 'CAACEdEose0cBAGCg8V3vr86jxn4bdBeDcWKLwUTNMzB392HPQkd6QQ1xvw9m0D87obPRGdTmrbZ\
BLXYt8tdFmCNqRRClKvzLlyc4H7QkjgGnFEUoMeKWdSVFydR5BWJZAFyZCe1DSvleCEYiZBcqJDvwyWDhJVXvsb4MvZB2i7gZDZD'
def get_profile_pic():
    query = "SELECT pic from user where uid in (SELECT uid2 from friend where uid1 = me())"
    payload = {'q':query,'access_token': TOKEN}
    r = requests.get('https://graph.facebook.com/fql', params=payload)
    result = json.loads(r.text)
    print result
    return result['data']

def save_photos(photos):        
    count = 0
    for photo in photos:
        count+=1
        print "succesfully downloaded cover_pic_%s" % count,photo['pic']
        urllib.urlretrieve(photo['pic'],"pic%s" %count)

if __name__ == '__main__':
	save_photos(get_profile_pic())
