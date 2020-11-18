///////// HackerRank Binary search

///// Equal circle segments

/*
Given the radii of a number of circles and a number of segments to cut, 
determine the largest area of segments of equal area that can be cut. 
Return the value, rounded to 4 decimals and cast as a string.
*/

bool check(double &x ,vector<double> &A, int &K){
    int k = 0;
       for(auto a : A){
        k += a/x;
         if(k >= K) return true;
       }
       return false;
}

double maximum_serving_area(vector<int> v,int k){
    double l=0, m=0, x;
      vector<double> A;
      for(int i=0; i<v.size(); i++)  {
        x = (double)v[i]*3.14159265359*v[i];
        m = max(m,x);
        A.push_back(x);
      }
      while(m-l >= 1e-5){
        x = (l+m)/2;
        if(check(x,A,k)) l=x;
        else m=x;
      }
      return x;
}

string largestSegment(vector<int> radius, int segments) {
    double res = maximum_serving_area(radius, segments);
    string ans ="";
    stringstream stream;
    stream<<fixed<<setprecision(4)<<res;
    if(stream>>ans){
        return ans;
    }
    return " ";
}

///////////////////////
























