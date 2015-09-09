import math
import decimal

#CONSTANTS
SPEEDS_DICT = {"metro":20, "bike":15, "foot":5}
PI = 3.14159265359
#END OF CONSTANTS

def convert_deg_to_rad(degree):
    radians = degree * PI / 180
    return radians

def find_distance(p1, p2):
    earth_rad = 6371
    p1_lat  = convert_deg_to_rad(p1[0])
    p1_long = convert_deg_to_rad(p1[1])
    p2_lat  = convert_deg_to_rad(p2[0])
    p2_long = convert_deg_to_rad(p2[1])
    return math.acos((math.sin(p1_lat) * math.sin(p2_lat)) + \
                     (math.cos(p1_lat) * math.cos(p2_lat) * math.cos(p2_long - p1_long))) * earth_rad

def calc_distance(transport, minutes):
    return SPEEDS_DICT[transport] * minutes * 1.0 / 60

if __name__ == "__main__":
    n = int(raw_input())
    attractions = []
    for i in range(n):
        tid, latitude, longitude = raw_input().split()
        tid, latitude, longitude = int(tid), float(latitude), float(longitude)
        attractions.append((tid, latitude, longitude))
    m = int(raw_input())
    for j in range(m):
        hlat, hlong, transport, minutes = raw_input().split()
        hlat, hlong, minutes = float(hlat), float(hlong), float(minutes)
        max_distance = calc_distance(transport, minutes)
        max_distance = round(max_distance, 2)
        results = []
        for i in range(0, len(attractions)):
            p1 = (attractions[i][1], attractions[i][2])
            p2 = (hlat, hlong)
            temp_dist = find_distance(p1, p2)
            temp_dist = round(temp_dist, 2)
            if temp_dist <= max_distance:
                results.append([temp_dist, attractions[i][0]])
        results.sort(key=lambda x: [x[0], x[1]])
        for i in range(0, len(results)):
            print results[i][1],
        print
