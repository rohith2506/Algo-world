'''
Merge overlapping intervals
'''

def is_overlapped(l1, l2):
    if l2[0] >= l1[0] and l2[0] <= l1[1]:
        return True
    else:
        return False

def get_covered_track(tracks):
    non_overlapping_tracks, result = [], 0
    non_overlapping_tracks.append(tracks[0])
    for i in range(1, len(tracks)):
        prev, present = non_overlapping_tracks.pop(), tracks[i]
        if is_overlapped(prev, present):
            non_overlapping_tracks.append((prev[0], max(prev[1], present[1])))
        else:
            non_overlapping_tracks.append(prev)
            non_overlapping_tracks.append(present)
    for track in non_overlapping_tracks:
        result = result + (track[1] - track[0] + 1)
    return result

def get_total_train_cells(track_dict):
    result = 0
    for row, tracks in track_dict.items():
        result = result + get_covered_track(tracks)
    return result

n, m, k = map(int, raw_input().split())
track_dict = {}
for cnt in range(0, k):
    r, c1, c2 = map(int, raw_input().split())
    if r not in track_dict:
        track_dict[r] = []
    track_dict[r].append((c1, c2))

total_train_cells = get_total_train_cells(track_dict)
print (n * m) - total_train_cells
