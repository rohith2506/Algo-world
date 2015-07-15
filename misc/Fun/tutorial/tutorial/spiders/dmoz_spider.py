from scrapy.spider import BaseSpider

class DmozSpider(BaseSpider):
    name = "euler"
    allowed_domains = ["projecteuler.net"]
    start_urls = [
        "http://www.projecteuler.net",
    ]

    def parse(self, response):
        print response.body
        print response.url
