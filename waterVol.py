def get_trough_vol(water_arr):
    #print "Water array:", water_arr
    start = water_arr[0]
    end = water_arr[len(water_arr) - 1]
    if start < end:
        level = start
    else:
        level = end
    volume = 0
    for height in water_arr:
        if (level - height > 0):
            volume += level - height
    return volume

def evaluate_water_volume(buildings):
    end = len(buildings) - 1
    current = 0
    volume = 0
    state = "processing"
    water_arr = []
    while (current != end):
        if( state == "processing" or state == "trough" and buildings[current] >= buildings[current+1]):
            #mark_start = current
            state = "trough"
            water_arr.append(buildings[current])
        elif ((state == "trough" or state == "end_trough") and buildings[current] <= buildings[current+1]):
            #mark_end = current + 1
            state = "end_trough"
            water_arr.append(buildings[current])
        elif((state == "end_trough" and buildings[current] > buildings[current+1])):
            state = "processing"
            water_arr.append(buildings[current])
            volume += get_trough_vol(water_arr)
            #but this could be the next trough so
            water_arr = []
            water_arr.append(buildings[current])
        current += 1
    if (state == "end_trough"):
        water_arr.append(buildings[current])
        volume += get_trough_vol(water_arr)
    print volume

if __name__ == "__main__":
    #take input
    num_tests = int(raw_input());
    for test in range(num_tests):
        num_buildings = int(raw_input())
        raw_buildings = raw_input().split()
        assert(len(raw_buildings) == num_buildings)
        buildings = []
        for building in raw_buildings:
            buildings.append(int(building))
        evaluate_water_volume(buildings)
