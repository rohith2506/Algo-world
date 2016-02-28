
from bisect import bisect_left

class Solution:
  def findall(self,t,p):
      pos=list()
      val=0
      while True:
          try:
             val=t.index(p,val+1)
             pos.append(val)
          except:
              break
      return pos

  def check(self,t,glob,k,num):
      keys=glob.keys()
      keys.sort()
      n=len(keys)
      print keys
      for i in range(len(keys)):
          cover=set(glob[keys[i]])
          key=keys[i]
          covered=1
          for j in range(num-1):
            key=key+k
            nxt=bisect_left(keys,key)
            if nxt<n and keys[nxt]==key:
                covered+=1
                cover.update(glob[key])
                if(len(cover))<j: break

          if covered==num and len(cover)==num:
              print keys[i],t[keys[i]:keys[i]+num*k]

  def search_complex(self,t,plst):
      glob={}
      for i in range(len(plst)):
          ppos=self.findall(t,plst[i])
          for pos in ppos:
              try:
                 glob[pos].add(i)
              except:
                  glob[pos]=set([i])
      self.check(t,glob,len(plst[0]),len(plst))

raw_string = raw_input()
words = raw_input().split()
print Solution().search_complex(raw_string, words)