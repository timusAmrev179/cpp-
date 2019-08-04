#include <iostream>
#include<bitset>
using namespace std;


/*
using bitset<> saves memory since it allocates memory bit by bit. 
Where in case of general array[] it would have allocated byte for storing single value.  
*/
bitset<30> col, diag1, diag2; 



void solve(int row, int n, int &ans){
    if(row==n){
        ans+=1; 
        return; 
    }

    for(int c = 0; c < n; c++){
        
        /*
            if you observe nXn board then you will get to know that the two diagonal have some characteristic feature. 
            In diagonal going from left to right, i.e., diag1 and diagonal going from right to left i.e., diag2 , 
            the element falling there feel something common about their address. 
            
            in diag1: 
                the address of all element gives the same result when row number - col number is done.
            in diag2:
                the address of all element falling at this diagonal line gives same result when row number + col number is done. 
                
                
            the idea is, if any element fall in lets say address difference of 3 then the next element element falling the same left to right
            diagonal will have the same difference, we have declared our diag1 bitset to check if there is any element already in diag1 line 
            or not. If the diag1 shows positive for the position mapped to 3 then diagonal does occupy the element and no more queen can be placed
            safely there. The same theory follows for diag 2 also.. 
            
        */
        
        //checking the column and two diagonal for the possible attack.
        if(!col[c] && !diag1[row -c + n - 1] && !diag2[row + c]){
        //No attack!
            //place the queen..
            col[c] = diag1[row - c + n -1] = diag2[row + c] = 1; 
            //go for next row..
            solve(row + 1, n, ans); 
            //while returning..
            col[c] = diag1[row - c + n -1] = diag2[row + c] = 0;// back track...
        }
    }
}

int main() {
    int n;
    cin>> n;
    int ans= 0; 
    solve(0, n, ans); 
    cout<<ans<<endl;

}
