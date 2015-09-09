import math

def form_string(values):
    result = ""
    for value in values:
        result += value
        result += " "
    result = result.strip()
    return result

def is_match(hotel_list, input_list, amenities):
    s1 = form_string(hotel_list)
    s2 = form_string(input_list)
    if s2.lower() in s1.lower():
        return True
    if s1.lower() == s2.lower():
        return True
    return False

if __name__ == "__main__":
    n = int(raw_input())
    hotel_amenities = []
    for i in range(n):
        amenity = raw_input()
        hotel_amenities.append(amenity)
    hotel_string = raw_input()
    hotel_words_list = hotel_string.split()
    results = []
    for amenity in hotel_amenities:
        input_list = amenity.split()
        flag = 0
        length = len(input_list) - 1
        for i in range(0, len(hotel_words_list) - length):
            hotel_list = hotel_words_list[i:i+length+1]
            if is_match(hotel_list, input_list, hotel_amenities):
                flag = 1
                break
        if flag == 1: results.append(amenity)
    results.sort()
    for res in results:
        print res
