import math
import decimal

def calc_max_score(hotel_cities, budget):
    cities = [[[-1,-1] for j in range(len(hotel_cities[i]))] for i in range(len(hotel_cities))]
    
    # base condition
    for j in range(0, len(hotel_cities[0])):
        price, score = hotel_cities[0][j][0], hotel_cities[0][j][1]
        cities[0][j][0] = budget - price
        cities[0][j][1] = score

    # Main Algorithm
    for i in range(1, len(cities)):
        for j in range(0, len(cities[i])):
            p1, s1 = hotel_cities[i][j][0], hotel_cities[i][j][1]
            tempprice, tempscore, tempindex = 0, 0, -1
            for k in range(0, len(cities[i-1])):
                p2, s2 = cities[i-1][k][0], cities[i-1][k][1]
                if p2 - p1 >= 0 and s1 + s2 > tempscore:
                    tempscore = s1 + s2
                    tempprice = p2 - p1
                    tempindex = k
            cities[i][j][0] = tempprice
            cities[i][j][1] = tempscore

    last_index, max_score = len(cities) - 1, -1
    for i in range(0, len(cities[last_index])):
        price, score = cities[last_index][i][0], cities[last_index][i][1]
        if price != - 1 and score > max_score:
            max_score = score
    return max_score


if __name__ == "__main__":
    cities, budget = raw_input().split()
    cities, budget = int(cities), int(budget)
    hotel_cities = []   
    for i in range(cities):
        num_hotels = int(raw_input())
        hotels = []
        for j in range(num_hotels):
            price, score = raw_input().split()
            price, score = int(price), float(score)
            hotels.append([price, score])
        hotel_cities.append(hotels)
    result = calc_max_score(hotel_cities, budget)
    if result != -1:
        print round(result, 2)
    else:
        print result
