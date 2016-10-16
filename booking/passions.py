'''
Some hash table problem
@Author: Rohith Uppala
'''

import math

def find_distance(p1, p2):
    earth_radius = 6371
    p1_lat, p1_long = math.radians(p1['lat']), math.radians(p1['long'])
    p2_lat, p2_long = math.radians(p2['lat']), math.radians(p2['long'])
    return math.acos((math.sin(p1_lat) * math.sin(p2_lat)) + (math.cos(p1_lat) * math.cos(p2_lat) * math.cos(p1_long - p2_long))) * earth_radius

if __name__ == "__main__":
    n = int(raw_input())
    passions = []
    for i in range(n):
        temp_passions = raw_input().split()[1:]
        for psn in temp_passions:
            if psn not in passions: passions.append(psn)
    m = int(raw_input())
    destinations = {}
    dest_distances = {}
    for i in range(m):
        dest_passions = raw_input().split()
        lat, lon = dest_passions[1], dest_passions[2]
        lat, lon = float(lat), float(lon)
        city = dest_passions[0]
        psns = dest_passions[4:]
        destinations[city] = psns
        dest_distances[city] = {'lat': lat, 'long': lon}
    dstns = destinations.keys()
    x,y,distance,maxi = "", "", 10e9,0
    for i in range(0, len(dstns)):
        for j in range(i+1, len(dstns)):
            cx, cy = dstns[i], dstns[j]
            cx_psns, cy_psns = destinations[cx], destinations[cy]
            main_passions = []
            main_passions.extend(cx_psns)
            for tmp in cy_psns:
                if tmp not in main_passions: main_passions.append(tmp)
            intersection_lst = list(set(passions).intersection(main_passions))
            if len(intersection_lst) > maxi:
                maxi = len(intersection_lst)
                x, y, distance = cx, cy, find_distance(dest_distances[cx], dest_distances[cy])
            elif len(intersection_lst) == maxi:
                new_distance = find_distance(dest_distances[cx], dest_distances[cy])
                if new_distance < distance:
                    x, y, distance = cx, cy, new_distance
    result = [x,y]
    result.sort()
    for res in result: print res,
