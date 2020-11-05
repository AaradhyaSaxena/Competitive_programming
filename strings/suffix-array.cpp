///// suffix array

#include <iostream> 
#include <cstring> 
#include <algorithm> 
using namespace std; 
  
struct suffix 
{ 
    int index; 
    char *suff; 
}; 
  
int cmp(struct suffix a, struct suffix b) 
{ 
    return strcmp(a.suff, b.suff) < 0? 1 : 0; 
} 
  
int *buildSuffixArray(char *txt, int n) 
{ 
    struct suffix suffixes[n]; 
  
    for (int i = 0; i < n; i++){ 
        suffixes[i].index = i; 
        suffixes[i].suff = (txt+i); 
    } 
  
    sort(suffixes, suffixes+n, cmp); 
  
    int *suffixArr = new int[n]; 
    for (int i = 0; i < n; i++) 
        suffixArr[i] = suffixes[i].index; 
  
    return  suffixArr; 
} 
  
void printArr(int arr[], int n){ 
    for(int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
} 
  
int main() 
{ 
    char txt[] = "banana"; 
    int n = strlen(txt);
    int *suffixArr = buildSuffixArray(txt,  n);

    printArr(suffixArr, n); 
    return 0; 
} 


///////////////
///////////////////
////////////

//// Longest Common Prefix
/// Kasai algorithm

vector<int> kasai(string s, vector<int> sa)
{
    int n=s.size(),k=0;
    vector<int> lcp(n,0);
    vector<int> rank(n,0);

    for(int i=0; i<n; i++) rank[sa[i]]=i;

    for(int i=0; i<n; i++)
    {
        if(rank[i]==n-1) {k=0; continue;}
        int j=sa[rank[i]+1];
        while(i+k<n && j+k<n && s[i+k]==s[j+k]) k++;
        lcp[rank[i]]=k;
        if(k>0) k--;
    }
    return lcp;
}


//////////
////////////////
/////////////

