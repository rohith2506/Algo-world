def get_col_threat(row, col, queens):
    lthreats, rthreats = 0, 0
    for i in range(0, len(queens)):
        r, c = i, queens[i]
        if r == row and c == col: continue
        if c == col and c > col: rthreats = rthreats + 1
        if c == col and c < col: lthreats = lthreats + 1
    return min(rthreats, 1) + min(lthreats, 1)

def get_row_threat(row, col, queens):
    lthreats, rthreats = 0, 0
    for i in range(0, len(queens)):
        r, c = i, queens[i]
        if r == row and c == col: continue
        if r == row and r > row: rthreats = rthreats + 1
        if r == row and r < row: lthreats = lthreats + 1
    return min(rthreats, 1) + min(lthreats, 1)
    
def get_d1_threat(row, col, queens):
    lthreats, rthreats = 0, 0
    for i in range(0, len(queens)):
        r, c = i, queens[i]
        if r == row and c == col: continue
        if r - row == c - col and r > row: rthreats = rthreats + 1
        if r - row == c - col and r < row: lthreats = lthreats + 1
    return min(lthreats, 1) + min(rthreats, 1)

def get_d2_threat(row, col, queens):
    lthreats, rthreats = 0, 0
    for i in range(0, len(queens)):
        r, c = i, queens[i]
        if r == row and c == col: continue
        if r - row == col - c and r > row: lthreats = lthreats + 1
        if r - row == col - c and r < row: rthreats = rthreats + 1
    return min(lthreats, 1) + min(rthreats, 1)

def maxThreats(queens):
    res = 0
    for i in range(0, len(queens)): queens[i] = queens[i] - 1
    for i in range(0, len(queens)):
        row, col = i, queens[i]
        row_threat = get_row_threat(row, col, queens)
        col_threat = get_col_threat(row, col, queens)
        d1_threat = get_d1_threat(row, col, queens)
        d2_threat = get_d2_threat(row, col, queens)
        res = max(res, (row_threat + col_threat + d1_threat + d2_threat))
    return res

queens = map(int, raw_input().split())
print maxThreats(queens)
