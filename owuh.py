from functools import lru_cache

wt = ""
st = 0
letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
order = 0
mul = 1
cur = ""
def get_score(s):
    score = 0
    for c in s:
        score += ord(c)-ord('A')+1
    return score

#@lru_cache(maxsize=None)
def get_order(cc,curs):
    global wt
    global st
    global mul
    global cur
    ans = 0
    ns = 0
    #print(cur)
    if cur != "" and cc == cur[-1]:
        return 0
    cur+=cc
    
    if cur != "":
        ns = curs+ord(cc)-ord('A')+1
    if ns == st:
        #print(cur)
        if cur == wt:
            mul = 0
            print("howwy mowwy")
        return 1
    if ns > st:
        return 0
    print(cur)
    for c in letters:
       ans+=get_order(c,ns)
       cur = cur[:-1]
       if mul == 0:
           return ans
    return ans

wt = input()
st = get_score(wt)
n = get_order('',0)
print(n)

