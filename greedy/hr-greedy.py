####################

##### HackerRank Greedy

###### Fountain

def fountainActivation(locations):
    n = len(locations)
    extents = [0] * n
    for i in range(n):
        left =  max(0, i - locations[i])
        right = min(n, i + locations[i] + 1)
        extents[left] = max(extents[left], right)
    for i in range(1, n):
        extents[i] = max(extents[i], extents[i-1])
    answer = 1
    already_occupied = extents[0]
    for i in range(n):
        if i == already_occupied:
            answer += 1
            already_occupied = extents[i]
    return answer

############

def fountainActivation(locations):
    n = len(locations)
    intervals = [(max(1, i + 1 - locations[i]), min(n, i + 1 + locations[i])) for i in range(n)]
    intervals.sort()
    answer = 0
    already_occupied = 0
    current_max = 0
    for i in range(n):
        if already_occupied + 1 < intervals[i][0]:
            already_occupied = current_max
            current_max = intervals[i][1]
            answer += 1
        current_max = max(current_max, intervals[i][1])
    if already_occupied != n:
        answer += 1
    return answer

##########

##########################
#########################
#### conference schedule

int maxPresentations(vector<int> scheduleStart, vector<int> scheduleEnd)
{
    int n = scheduleEnd.size();
    int cnt = 0;
    vector<pair<int,int>> vec;
    for(int i=0; i<n; i++){
        vec.push_back({scheduleEnd[i], scheduleStart[i]});
    }
    sort(vec.begin(), vec.end());
    int end = vec[0].first;
    for(int i=1; i<n; i++)
    {
        if(vec[i].second>=end){
            cnt++;
            end = vec[i].first;
        }
    }
    return cnt+1;
# }

#########

