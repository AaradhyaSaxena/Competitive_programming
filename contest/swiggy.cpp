///////////////////

////// SWIGGY

// Count number of occurrences (or frequency) in a sorted array

#include <bits/stdc++.h> 
using namespace std; 

int binarySearch(int arr[], int l, int r, int x) 
{ 
    if (r < l) 
        return -1; 
    int mid = l + (r - l) / 2; 
    if (arr[mid] == x) 
        return mid; 
    if (arr[mid] > x) 
        return binarySearch(arr, l, mid - 1, x); 
    return binarySearch(arr, mid + 1, r, x); 
} 
  
int countOccurrences(int arr[], int n, int x){ 
    int ind = binarySearch(arr, 0, n - 1, x); 
    if (ind == -1) return 0; 
  
    int count = 1; 
    int left = ind - 1; 
    while (left >= 0 && arr[left] == x) 
        count++, left--; 
  
    int right = ind + 1; 
    while (right < n && arr[right] == x) 
        count++, right++; 
  
    return count; 
} 
  
int main() { 
    int arr[] = { 1, 2, 2, 2, 2, 3, 4, 7, 8, 8 }; 
    int n = sizeof(arr) / sizeof(arr[0]), x = 2; 
    cout << countOccurrences(arr, n, x); 
    return 0; 
}

////////////////
////////////////

//////// stocks buy and sell

#include <bits/stdc++.h>
using namespace std;
 
void stockBuySell(int price[], int n)
{
    if (n == 1)
        return;
 
    int i = 0;
    while (i < n - 1) {
        while( (i < n - 1) && (price[i + 1] <= price[i]) ){
            i++;
        }
        if (i == n - 1) break;
        int buy = i++;

        while ((i < n) && (price[i] >= price[i - 1])){
            i++;
        }
        int sell = i - 1;
        cout << "Buy on day: " << buy << "\t Sell on day: " << sell << endl;
    }
}
 
int main(){
    int price[] = { 100, 180, 260, 310, 40, 535, 695 };
    int n = sizeof(price) / sizeof(price[0]);
 	stockBuySell(price, n);
    return 0;
}

/////////////////
//////////////////////

//// distinct substrings

#include<bits/stdc++.h>
using namespace std;

void printAllSubstrings(string s, int n) 
{
    for (int i = 0; i < n; i++)
    {
        char temp[n - i + 1];
        int tempindex = 0;
        for (int j = i; j < n; j++)
        {
            temp[tempindex++] = s[j];
            temp[tempindex] = '\0';
            printf("%s\n", temp);
        }
    }
}
 
int main() 
{
    string s = "Geeky";
    printAllSubstrings(s, s.length());
    return 0;
}

///////////////
/////////////////////////
//// is cicular


bool isCircular(char path[]) 
{ 
  int x = 0, y = 0; 
  int dir = N; 
  
  for (int i=0; path[i]; i++) 
  { 
      char move = path[i]; 
      if (move == 'R') 
        dir = (dir + 1)%4; 
      else if (move == 'L') 
        dir = (4 + dir - 1)%4; 
  
     else // if (move == 'G') 
    { 
         if (dir == N) y++; 
         else if (dir == E) x++; 
         else if (dir == S) 
            y--; 
         else // dir == W 
            x--; 
      } 
  } 
  
   // If robot comes back to (0, 0), then path is cyclic 
  return (x == 0 && y == 0); 
} 
  
// Driver program 
int main() 
{ 
    char path[] = "GLGLGLG"; 
    if (isCircular(path)) 
      cout << "Given sequence of moves is circular"; 
    else
      cout << "Given sequence of moves is NOT circular"; 
} 

////////////////
////////////////////////
///////////////////
































============================




