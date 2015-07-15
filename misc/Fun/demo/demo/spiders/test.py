from scrapy.spider import BaseSpider
from scrapy.selector import HtmlXPathSelector
from demo.items import CraigslistSampleItem

class MySpider(BaseSpider):
  name = "craig"
  allowed_domains = ["craigslist.org"]
  start_urls = ["http://sfbay.craigslist.org/npo/"]

  def parse(self, response):
      hxs = HtmlXPathSelector(response)
      titles = hxs.select("//span[@class='pl']")
      items = []
      for titles in titles:
          item = CraigslistSampleItem()
          item ["title"] = titles.select("a/text()").extract()
          item ["link"] = titles.select("a/@href").extract()
          items.append(item)
      return items