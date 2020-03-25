// //// Manhattan Distance
// //// 
// //////////////////////////
// #include <bits/stdc++.h>
// using namespace std;

// int manhattan_distance(int i, int j, int x, int y)
// {
//     return abs(i- (x * 2 + y % 2)) + abs(j - y);
// }

// int arr[1000][1000];

// int main()
// {
//     int t, n, m, q, type, x, y;
//     cin >> t;
//     while(t--)
//     {
//         cin >> n >> m;
//         for(int i = 0 ; i < n ; i++)
//             for(int j = 0 ; j < m ; j++)
//                 cin >> arr[i][j];

//         cin >> q;
//         while(q--)
//         {
//             int sum = 0;
//             cin >> type;
//             if(type == 1)
//             {
//                 cin >> x >> y;
//                 for(int i = 0 ; i < 2 * n ; i++)
//                     for(int j = 0 ; j < m ; j++)
//                     {
//                         if(manhattan_distance(i, j, x, y) == 2 && i != x * 2 + y % 2)
//                             sum += arr[(i - j%2) / 2][j];
//                     }
//                 cout << sum << endl;
//             }
//             else
//             {
//                 cin >> x >> y;
//                 for(int i = 0 ; i < 2 * n ; i++)
//                     for(int j = 0 ; j < m ; j++)
//                     {
//                         if(i!= x*2 + y%2)
//                         {
//                             if(manhattan_distance(i, j, x, y) == 4 && abs(j - y) <= 2)
//                                 sum += arr[(i - j%2) / 2][j];
//                         }
//                         else
//                         {
//                             if(manhattan_distance(i, j, x, y) == 2 && abs(j - y) <= 2)
//                                 sum += arr[(i - j%2) / 2][j];
//                         }
//                     }
//                 cout << sum << endl;
//             }
//         }
//     }
//     return 0;
// }

// ////////////////

