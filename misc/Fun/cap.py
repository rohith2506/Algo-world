'''
from decoding captcha site
'''
from PIL import Image
import mechanize, hashlib, time, os, math, _imaging

class VectorCompare:
  def magnitude(self,concordance):
    if type(concordance) != dict:
      raise ValueError('Supplied Argument should be of type dict')
    total = 0
    for word,count in concordance.iteritems():
      total += count ** 2
    return math.sqrt(total)

  def relation(self,concordance1, concordance2):
    if type(concordance1) != dict:
      raise ValueError('Supplied Argument 1 should be of type dict')
    if type(concordance2) != dict:
      raise ValueError('Supplied Argument 2 should be of type dict')
    relevance = 0
    topvalue = 0
    for word, count in concordance1.iteritems():
      if concordance2.has_key(word):
        topvalue += count * concordance2[word]
    if (self.magnitude(concordance1) * self.magnitude(concordance2)) != 0:
      return topvalue / (self.magnitude(concordance1) * self.magnitude(concordance2))
    else:
      return 0

  def concordance(self,document):
    if type(document) != str:
      raise ValueError('Supplied Argument should be of type string')
    con = {}
    for word in document.split(' '):
      if con.has_key(word):
        con[word] = con[word] + 1
      else:
        con[word] = 1
    return con

def buildvector(im):
  d1 = {}
  count = 0
  for i in im.getdata():
    d1[count] = i
    count += 1
  return d1
v = VectorCompare()

def decode(fic):
  img = Image.open(fic)
  img = img.convert("RGBA")

  pixdata = img.load()

  for y in xrange(img.size[1]):
      for x in xrange(img.size[0]):
	  if pixdata[x, y][0] < 95:
	      pixdata[x, y] = (0, 0, 0, 255)
			  
  for y in xrange(img.size[1]):
      for x in xrange(img.size[0]):
	  if pixdata[x, y][1] < 95:
	      pixdata[x, y] = (0, 0, 0, 255)
			  
  for y in xrange(img.size[1]):
      for x in xrange(img.size[0]):
	  if pixdata[x, y][2] > 0:
			  pixdata[x, y] = (255, 255, 255, 255)

  img = img.resize((1000, 300), Image.NEAREST)
  im2 = Image.new("P",img.size,255)
  im = img.convert("P")

  pas = 5
  alone = True

  for x in range(0,im.size[1],pas):
    for y in range(0,im.size[0],pas):
      if im.getpixel((y,x)) == 0:
	for i in range(-pas,pas,1):
	  for j in range(-pas,pas,1):
	    if (y+i < im.size[0] and x+j < im.size[1] and y+i >= 0 and x+j >= 0):
	      if im.getpixel((y+i,x+j)):
		alone = False
	for i in range(-pas,pas,1):
	  for j in range(-pas,pas,1):
	    if (y+i < im.size[0] and x+j < im.size[1] and y+i >= 0 and x+j >= 0):
	      if not alone:
		im2.putpixel((y+i,x+j),0)
	alone = True

  inletter = False
  foundletter=False

  saut = 9
  start_ab = 0
  end_ab = 0
  start_or = im2.size[1]-1
  end_or = 0
  size = 0

  debut = True

  letters = []

  for y in range(0,im2.size[0],saut): # slice across
    for x in range(0,im2.size[1],1): # slice down
      pix = im2.getpixel((y,x))
      if pix != 255:
	start_or = min(start_or,x)
	end_or = max(end_or,x)
	inletter = True

    if foundletter == False and inletter == True:
      foundletter = True
      start_ab = y

    if foundletter == True and inletter == False:
      foundletter = False
      end_ab = y
      size = max(size,end_ab)
      letters.append((start_ab,end_ab,start_or,end_or))
      start_or = im2.size[1]-1
      end_or = 0
    inletter=False

  if im2.size[0]/size < 2 and __name__ != '__main__':
    return ""
  
  iconset = ['1','2','3','4','5','6','7','8','a','b','c','d','e','f','h','j','k','l','m','n','p','q','r','t','u','v','w','x','y','z',"''"]

  imageset = []

  for letter in iconset:
    for img in os.listdir('/home/infinity/Algo/Fun/iconset/%s/'%(letter)):
      temp = []
      temp.append(buildvector(Image.open("/home/infinity/Algo/Fun/iconset/%s/%s"%(letter,img))))
      imageset.append({letter:temp})

  count = 0
  res = ""
  
  for letter in letters:
    m = hashlib.md5()
    im3 =  im2.crop(( letter[0] , letter[2], letter[1],letter[3] ))
    m.update("%s%s"%(time.time(),count))
    #im3.save("./%d_%s.gif"%(count,m.hexdigest()))

    guess = []

    for image in imageset:
      for x,y in image.iteritems():
	if (x == "''"):
	  x = ''
	if len(y) != 0:
	  guess.append( ( v.relation(y[0],buildvector(im3)),x) )

    guess.sort(reverse=True)
    res += guess[0][1]
    count += 1
  return res

fname = open("captcha.jpg")
print fname
print decode(fname)