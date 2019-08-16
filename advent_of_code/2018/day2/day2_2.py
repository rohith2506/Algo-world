def compare(box1, box2):
    letter_diff = 0
    for i in range(len(box1)):
        if box1[i] != box2[i]: letter_diff += 1
    return letter_diff

def find_common_letters(box1, box2):
    common_letters = ""
    for i in range(len(box1)):
        if box1[i] == box2[i]: common_letters += box1[i]
    return common_letters

values = [line.strip() for line in open("day2.txt", "r").readlines()]

for i in range(len(values)):
    for j in range(i+1, len(values)):
        if compare(values[i], values[j]) == 1:
            result = find_common_letters(values[i], values[j])
            print result
