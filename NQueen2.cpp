#include <iostream>
#include<bitset>
using namespace std;

bitset<30> col, diag1, diag2; 

void solve(int row, int n, int &ans){
    if(row==n){
        ans+=1; 
        return; 
    }

    for(int c = 0; c < n; c++){
        if(!col[c] && !diag1[row -c + n - 1] && !diag2[row + c]){
            col[c] = diag1[row - c + n -1] = diag2[row + c] = 1; 
            solve(row + 1, n, ans); 
            col[c] = diag1[row - c + n -1] = diag2[row + c] = 0;
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
