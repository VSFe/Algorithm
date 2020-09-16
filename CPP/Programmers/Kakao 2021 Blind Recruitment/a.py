def step5to7(id):
    
    if id == '':
        id = 'a'

    if len(id) >= 16:
        id = id[0:15]
        if id[-1] == '.':
            id = id[0:14]   

    while(len(id) <= 2):
        id += id[-1]

    return id

def step1to4(id):
    id = id.lower()

    new_str = ''
    for c in id:
        if c >= 'a' and c <= 'z':
            new_str = new_str + c
        elif c >= '0' and c <= '9':
            new_str = new_str + c
        elif c == '-' or c == '_' or c == '.':
            new_str = new_str + c

    id = new_str
    new_str = ''
    
    for c in id:
        if c == '.' and len(new_str) >= 1 and new_str[-1] == '.':
            continue
        new_str = new_str + c

    id = new_str
    leftside = 0
    rightside = len(id)

    if id[0] == '.':
        leftside += 1
    
    if id[-1] == '.':
        rightside -= 1

    return id[leftside:rightside]

def solution(new_id):
    # print(step1to4(new_id))
    return step5to7(step1to4(new_id))

# Driver
if __name__ == "__main__":
    aa = input()
    print(solution(aa))