from facepy import GraphAPI

access_token = 'CAACEdEose0cBAK17KfWK7auUK7DkUDcZAhx2M1u1bZCmNpXEcZBERFRRPd3pgUz1Itujy3JVKVeSg7Sdwu4yZAfa\
vfjJqPZALsD1LrfZApGbdUBfb5oM3AItuGdgRzoWCwc6UjVoS87MLDgp6C6k5DnnhCWPQfmhSxuN4ZChhk7qPh2QNJVDePZBLjdy9C7gwZAXuAXKKRtGSsAZDZD'

graph = GraphAPI(access_token)

# Get my latest posts
graph.get('me/posts')

# Post a photo of a parrot
graph.post(
    path = 'me/photos',
    source = open('hello')
)