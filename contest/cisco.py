###### Cisco

######### snakes and ladder

def snakesAndLadders(self, board: List[List[int]]) -> int:
        N = len(board)

        def get(s):
            # Given a square num s, return board coordinates (r, c)
            quot, rem = divmod(s-1, N)
            row = N - 1 - quot
            col = rem if row%2 != N%2 else N - 1 - rem
            return row, col

        dist = {1: 0}
        queue = collections.deque([1])
        while queue:
            s = queue.popleft()
            if s == N*N: return dist[s]
            for s2 in range(s+1, min(s+6, N*N) + 1):
                r, c = get(s2)
                if board[r][c] != -1:
                    s2 = board[r][c]
                if s2 not in dist:
                    dist[s2] = dist[s] + 1
                    queue.append(s2)
        return -1

####################
######################

###### weighted job scheduling

class Job: 
    def __init__(self, start, finish, profit): 
        self.start  = start 
        self.finish = finish 
        self.profit  = profit 

def binarySearch(job, start_index): 
  
    lo = 0
    hi = start_index - 1

    while lo <= hi: 
        mid = (lo + hi) // 2
        if job[mid].finish <= job[start_index].start: 
            if job[mid + 1].finish <= job[start_index].start: 
                lo = mid + 1
            else: 
                return mid 
        else: 
            hi = mid - 1
    return -1
  
def schedule(job): 
    
    job = sorted(job, key = lambda j: j.finish) 
    n = len(job)  
    table = [0 for _ in range(n)] 
  
    table[0] = job[0].profit; 
  
    for i in range(1, n): 
  
        inclProf = job[i].profit 
        l = binarySearch(job, i) 
        if (l != -1): 
            inclProf += table[l]; 
  
        table[i] = max(inclProf, table[i - 1]) 
  
    return table[n-1] 
  
job = [Job(1, 2, 50), Job(3, 5, 20),Job(6, 19, 100), Job(2, 100, 200)] 
print("Optimal profit is"), 
print schedule(job) 

####################
##########################

##### volatile roy

q = [[1,2,3,4,5,6,7,8,9]]
dict = {(1,2,3,4,5,6,7,8,9):0};
primes = [3,5,7,11,13,17]
swap = [[0,1],[0,3],[1,2],[1,4],[2,5],[3,4],[3,6],[4,5],[4,7],[5,8],[6,7],[7,8]]
while q:
    u = q.pop(0)
    for s in swap:
        if u[s[0]]+u[s[1]] in primes:
            temp = u[:]
            temp[s[0]],temp[s[1]] = temp[s[1]],temp[s[0]]
            if tuple(temp) not in dict:
                dict[tuple(temp)] = 1+dict[tuple(u)]
                q.append(temp)

n = 3
for _ in range(int(input())):
    input()
    mat = []
    for i in range (n):
        t = [int(j) for j in input().split()]
        mat.extend(t)
    # print(mat)
    mat = tuple(mat)
    if mat in dict:
        print(dict[mat])
    else:
         print(-1)


####################
#######################

#### regular expression

def solution(exp):
    integer_list = [i for i in exp if i.isdigit()]
    fill_positions = []
    output = []
    answer = []
    exp_list = [i for i in exp]
    
    integer_list.sort()
    for j, exp in enumerate(exp):
        if exp == '$':
            fill_positions.append(j)
    
    backtracking(output, integer_list, len(fill_positions), [])
    
    for i in output:
        k = 0
        for j in fill_positions:
            exp_list[j] = i[k]
            k += 1
        answer.append(str(int(''.join(exp_list))))
    print(answer)
    
def backtracking(output, lst, length, cur):
    if length == 0:
        output.append(cur)
    else:
        for i in lst:
            backtracking(output, lst, length - 1 , cur + [i])
        
solution('23$$')
solution('$01')

#######################
######################

##### version comparator

def versionCompare(v1, v2): 
      
    # This will split both the versions by '.' 
    arr1 = v1.split(".")  
    arr2 = v2.split(".")  
    n = len(arr1) 
    m = len(arr2) 
      
    # converts to integer from string 
    arr1 = [int(i) for i in arr1] 
    arr2 = [int(i) for i in arr2] 
   
    # compares which list is bigger and fills  
    # smaller list with zero (for unequal delimeters) 
    if n>m: 
      for i in range(m, n): 
         arr2.append(0) 
    elif m>n: 
      for i in range(n, m): 
         arr1.append(0) 
      
    # returns 1 if version 1 is bigger and -1 if 
    # version 2 is bigger and 0 if equal 
    for i in range(len(arr1)): 
      if arr1[i]>arr2[i]: 
         return 1
      elif arr2[i]>arr1[i]: 
         return -1
    return 0
  
# Driver program to check above comparison function 
version1 = "1.0.3"
version2 = "1.0.7"
  
ans = versionCompare(version1, version2) 
if ans < 0: 
    print version1 + " is smaller"
elif ans > 0: 
    print version2 + " is smaller"
else: 
    print "Both versions are equal"

###############
####################
############












