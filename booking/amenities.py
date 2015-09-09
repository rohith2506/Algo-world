import math

def is_matched(hotel_amenties, traveller_amenities):
    for amenity in traveller_amenities:
        if amenity not in hotel_amenties:
            return False
    return True

if __name__ == "__main__":
    n = int(raw_input())
    hotel_details = []
    for i in range(n):
        resp = raw_input().split()
        hid, price = int(resp[0]), int(resp[1])
        amenities = resp[2:]
        hotel_details.append((hid, price, amenities, len(amenities)))
    m = int(raw_input())
    for j in range(m):
        resp = raw_input().split()
        tprice, amenities = int(resp[0]), resp[1:]
        results = []
        for i in range(0, len(hotel_details)):
            hotel_amenties = hotel_details[i][2]
            hotel_price = hotel_details[i][1]
            if is_matched(hotel_amenties, amenities) and tprice >= hotel_price:
                results.append((-len(hotel_amenties), hotel_price, hotel_details[i][0]))
        if not results:
            print 
        else:
            results.sort(key=lambda x: [x[0], x[1], x[2]])
            for i in range(0, len(results)):
                print results[i][2],
            print
