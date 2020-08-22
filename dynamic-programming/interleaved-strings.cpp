//////https://practice.geeksforgeeks.org/problems/interleaved-strings/1

/// Interleaved strings

bool isInterleave(string A, string B, string C)
{
    if( !A.length() && !B.length() && !C.length() )
        return true;
    if( !C.length() )
        return false;
    
    bool x = (A.length() && C[0] == A[0] && isInterleave(A.substr(1), B, C.substr(1) ));
    bool y = (B.length() && C[0] == B[0] && isInterleave(A, B.substr(1), C.substr(1) ));
    
    return x || y;
}