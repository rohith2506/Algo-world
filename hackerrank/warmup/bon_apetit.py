n, k = map(int, raw_input().split())
items = map(int, raw_input().split())
b_charged = int(raw_input())
is_okay, difference = False, 0

for i in range(0, len(items)):
    b_actual = (sum(items) - items[i])
    if b_actual == 2 * b_charged:
        is_okay = True
        break
    else:
        difference = max(difference, (b_charged - (b_actual / 2)))

if is_okay:
    print "Bon Appetit"
else:
    print difference
