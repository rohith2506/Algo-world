import requests
import json
import urllib

TOKEN = 'CAACEdEose0cBAGCg8V3vr86jxn4bdBeDcWKLwUTNMzB392HPQkd6QQ1xvw9m0D87obPRGdTmrbZBL\
XYt8tdFmCNqRRClKvzLlyc4H7QkjgGnFEUoMeKWdSVFydR5BWJZAFyZCe1DSvleCEYiZBcqJDvwyWDhJVXvsb4MvZB2i7gZDZD'

def get_photos():
    query = ("SELECT src FROM photo_src WHERE photo_id IN (SELECT object_id FROM photo WHERE aid IN (SELECT aid FROM album WHERE owner = 100001504719462))"" AND width > 1000 LIMIT 1000")
    payload = {'q':query,'access_token': TOKEN}
    response = requests.get('https://graph.facebook.com/fql', params=payload)
    result = json.loads(response.text)
    print result
    return result['data']

def save_photos(photos):
    counter = 0

    for photo in photos:
        counter +=1
        print "succesfully downloaded pic_%s" % counter,photo['src']
        urllib.urlretrieve(photo['src'],"pic%s" %counter)


if __name__ == '__main__':
    save_photos(get_photos())