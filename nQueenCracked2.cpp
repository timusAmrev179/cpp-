
#include <iostream>
using namespace std;

bool isSafe(int board[][10], int i, int j, int n){
    
    for(int x= 0; x<i; x++){
    //check if there is any queen placed above the position..
        if(board[x][j]){
            return false; 
        }
    }

    //diagonal right.. 
    int x= i; 
    int y= j; 
    while(x>=0 && y>=0){
        if(board[x][y])
            return false; 
        x--; 
        y--; 
    }

//diagonal right
    x= i; 
    y= j; 

    while(x>=0 && y<n){
        if(board[x][y])
            return false; 

        x--; 
        y++; 
    }

return true; 
}

bool solveNQueen(int board[][10], int i, int n){
    if(i==n){
        //you have successfully placed queens in n rows(0.....n-1); 
        //print the board; 
        for(int i= 0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]==1)
                    cout<<"Q "; 
                
                cout<<"_ ";
            }
            cout<<endl; 
        }

        cout<<endl; 

      return false;   
    }
    for (int j= 0; j<n; j++){
        if(isSafe(board, i, j, n)){
            //place the queen;
            board[i][j]= 1;
            bool nextQueenRakhPaye= solveNQueen(board, i+1, n);
            if(nextQueenRakhPaye){
                return true; 
            } 

            board[i][j]= 0; //backtrack; 
        }

    }

    return false; 
}

int main() {
    int n; 
    cin>>n; 
    int board[10][10]= {0}; 
    if(!solveNQueen(board, 0, n))
        cout<<"No more solution "<<endl;  

}
