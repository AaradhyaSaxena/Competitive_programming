###### nference

from collections import defaultdict
string = "abaab"
curr = 0
elements = []
for char in string:
  curr_char = ord(char) - ord('a')
  curr = curr^(1<<curr_char)
  elements.append(curr)
MAP = defaultdict(lambda : 0)

result = 0;
for element in elements:
  for val in range(-1,26):
    if val == -1:
      curr = 0
    else:
      curr = (1<<val)
    curr_xor = curr^element;
    result += MAP[curr_xor];
  MAP[element] +=1 ;
print(result)


## Number of substrings that are scramble pallindromes.

################
####################