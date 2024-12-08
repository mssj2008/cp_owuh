from functools import lru_cache

wt = ""
st = 0
letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
order = 0

def get_score(s):
    score = 0
    for c in s:
        score += ord(c)-ord('A')+1
    return score

@lru_cache(maxsize=None)
def get_order(cur,curs):
    global order
    global wt
    global st
    for c in letters:
        if curs != 0:
            if cur[-1] == c:
                continue
        ns = curs+ord(c)-ord('A')+1
        if ns > st:
            return
        elif ns == st:
            order+=1
            cur+=c
            if cur == wt:
                print(order)
                exit(0)
            return
        else:
            get_order(cur + c, ns)


