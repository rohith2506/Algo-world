var urls = [];
var casper = require('casper').create();

function tryAndScroll(casper) {
  casper.waitFor(function() {
    this.page.scrollPosition = { top: this.page.scrollPosition["top"] + 4000, left: 0 };
    return true;
  }, function() {
    var info = this.getElementInfo('p[link_loading_spinner="!loading"]');
    if (info["visible"] == true) {
      this.waitWhileVisible('p[link_loading_spinner="!loading"]', function () {
        this.emit('results.loaded');
      }, function () {
        this.echo('next results not loaded');
      }, 5000);
    }
  }, function() {
    this.echo("Scrolling failed. Sorry.").exit();
  }, 500);
}
 
casper.on('results.loaded', function () {
  tryAndScroll(this);
});
 
casper.open('https://www.quora.com/', function() {
  this.waitUntilVisible('a', function() {
    tryAndScroll(this);
  });
});

casper.then(function() {
  casper.each(this.getElementsInfo('a.topic_name'), function(casper, element, j) {
    var url = element["attributes"]["href"];
    urls.push(url);
  });
});

casper.then(function() {
  require('fs').write("outputdata.csv", data, 'w');
});