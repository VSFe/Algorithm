domain = {}
link = []
baseScore = []
totalScore = []

def findOuterLink(idx):
    addScore = 0
    idxDomain = domain[idx]
    for i in range(len(link)):
        if i == idx:
            continue
        portal = link[i]
        if idxDomain in portal:
            addScore += float(baseScore[i]) / float(len(link[i]))

    totalScore[idx] = totalScore[idx] + addScore

def parse(page, idx, word):
    parsedPage = page.split('\\n')
    outerLink = []
    textList = []
    score = 0

    for text in parsedPage:
        text = text.strip()
        print(text)

        if(text[1:5] == "meta"):
            metaOption = text.split(' ')
            for option in metaOption:
                if(option[0:7] == "content"):
                    startIdx = option.find("\\") + 2
                    endIdx = option.find("\\", startIdx)
                    domain[idx] = option[startIdx:endIdx]

        if(text.find("<a href") != -1):
            prevIdx = text.find("<a href")
            startIdx = text.find("\\", prevIdx) + 2
            endIdx = text.find("\\", startIdx)
            outerLink.append(text[startIdx:endIdx])

        if(text.find(">") != len(text) - 1):
            startIdx = text.find(">")
            endIdx = text.find("<", startIdx)
            if(endIdx == -1):
                newText = text[startIdx+1:]
            else:
                newText = text[startIdx + 1: endIdx]
            left = 0
            for i in range(len(newText)):
                if not(newText[i] >= 'A' and newText[i] <= 'z'):
                    if(i == left):
                        left = left + 1
                    else:
                        textList.append(newText[left:i])
                        if newText[left:i].lower() == word:
                            score = score + 1
                        left = i + 1
            if(left != len(newText)):
                textList.append(newText[left:])
                if newText[left:].lower() == word:
                    score = score + 1
        if(text.find("<") != 0):
            endIdx = text.find("<")

    link.append(outerLink)
    baseScore.append(score)

def solution(word, pages):
    size = len(pages)
    word = word.lower()
    for i in range(size):
        parse(pages[i], i, word)
        totalScore.append(baseScore[i])
    
    for i in range(size):
        findOuterLink(i)

    answer = -1
    value = -1

    for i in range(size):
        if value < totalScore[i]:
            answer = i
            value = totalScore[i]

    print(domain)
    print(link)
    print(baseScore)
    print(totalScore)
    print(answer)

# Driver
if __name__ == "__main__":
    size = int(input())
    word = input()
    pages = []
    for i in range(size):
        tmp = input()
        pages.append(tmp)

    solution(word, pages)