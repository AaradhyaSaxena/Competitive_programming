// #include<iostream>
// using namespace std;

// const int size=10;
// long int count=0;

// void print_board(int board[size][size]){
//     for(int i=0;i<size;i++){
//     	for(int j=0;j<size;j++)
//     		cout<<board[i][j]<<" ";
//     	cout<<"\n";
//     }
// }

// bool canplace(int board[size][size],int x,int y){
//     if(x<0||y<0||x>=size||y>=size) return false;
//     return true;
// }

// void knightmove(int board[size][size],int x,int y,int n){
//     if(n==0){
//     	if(board[x][y]==0)
//     	{
//     		board[x][y]=1;
//     		count++;
//     	}
//     	return;
//     }
//     int move_x[]={-2,-1,1,2,2,1,-1,-2};
//     int move_y[]={1,2,2,1,-1,-2,-2,-1};
//     for(int i=0;i<8;i++){
//     	int movex = move_x[i]+x;
//     	int movey = move_y[i]+y;
//     	if(canplace(board,movex,movey)) {
//     		//board[movex][movey]=1;
//     		knightmove(board,movex,movey,n-1);
//     		//board[x][y]=0;
//     	}
//     	//board[movex][movey]=0;
//     }
// }

// int main(){
//     int board[10][10]={0};
//     int x,y,n;
//     cin>>x>>y>>n;
//     knightmove(board,x-1,y-1,n);
//     //print_board(board);
//     	cout<<count;
//     return 0;
// }