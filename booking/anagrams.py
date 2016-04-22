import sys

def check_for_anagram(x, y):
    l1 = x.split()
    l2 = y.split()
    x, y = "", ""
    for l in l1: x = x + l
    for l in l2: y = y + l
    p = ''.join(sorted(x))
    q = ''.join(sorted(y))
    if p == q: return True
    else: return False    

def get_anagrams(words):
    anagrams = []
    visited = [0 for i in range(len(words))]
    for i in range(0, len(words)):
        temp = []
        if visited[i] == True: continue
        temp.append(words[i])
        visited[i] = True
        for j in range(i+1, len(words)):
            x, y = words[i], words[j]
            if check_for_anagram(x, y):
                temp.append(y)
                visited[j] = True
        temp.sort()
        anagrams.append(temp)
    return anagrams

words = []
while True:
    data = sys.stdin.readline()
    data = data.strip()
    if not data: break
    words.append(data)

anagrams = get_anagrams(words)
result = []
for t1 in anagrams:
    string = ""
    for t2 in t1:
        string = string + t2
        string = string + ","
    string = string.strip(",")
    result.append(string)

result.sort()
for res in result:
    print res
