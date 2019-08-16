import requests
import pdb

data = {}

data['facebook_token'] = 'EAAGm0PX4ZCpsBAAp78s1m1UZBpGWuQT5ltFEemvzPsjGw5Yd1vhDMs8bh0H06cezKUrbvnjaDHdyfSxSoIPssxrbg76LCbH1YtZAcn8Hem5id7sUyhPnjCdCKEvM8pVr7xZBrxdSlFxiRe9zOPHZAXfNCCNYcJsmtIwjdhaFnUuQ1SVI5AmFqym9GL5xO4qQKB0z6EeyZCVQg6m6eJOpLdjKOZCNul6WbXVGZCqFGhOcRFnbqhUlBYPB83L9fG0ABNbeovSvfFvjVQZDZD';

data['facebook_id'] = 100001504719462;

url = "https://api.gotinder.com/auth"

resp = requests.post(url=url, data=data)

pdb.set_trace()
