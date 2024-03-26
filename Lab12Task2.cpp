#include <iostream>
using namespace std;

void printBoard(int** board,int k){
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int f(int **board,int k,int row,int* horizontal,int* diagonalLB_RT,int* diagonalLT_RB){
    if(row==k){
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;

        return 1;
    }
    int sum = 0;
    for(int j=0;j<k;j++){
        if(horizontal[j]==0&&diagonalLB_RT[k-1-row+j]==0&&diagonalLT_RB[row+j]==0){
            board[row][j] = 1;
            horizontal[j] = 1;
            diagonalLB_RT[k-1-row+j] = 1;
            diagonalLT_RB[row+j] = 1;
            sum+=f(board,k,row+1,horizontal,diagonalLB_RT,diagonalLT_RB);
            board[row][j] = 0;
            horizontal[j] = 0;
            diagonalLB_RT[k-1-row+j] = 0;
            diagonalLT_RB[row+j] = 0;
        }
    }
    return sum;
}

int main(){
    int k=8,i,j;
    //cout << "input K - size of board and number of queens:";
    //cin >> k;
    int queensLeft = k;//LB_RT = Left to bottom + right to top, diagonal LT_RB = left to top right to bottom
    int **board = new int*[k],*diagonalLB_RT = new int[2*k-1],*diagonalLT_RB = new int[2*k-1],*horizontal = new int[k];


    for(i=0;i<k;i++){
        board[i] = new int[k];
        for(j=0;j<k;j++){
            board[i][j] = 0;
        }
        horizontal[i] = 0;
    }
    for(i=0;i<2*k-1;i++){
        diagonalLB_RT[i] = 0;
        diagonalLT_RB[i] = 0;
    }

    cout << "number of possible positions = " << f(board,k,0,horizontal,diagonalLB_RT,diagonalLT_RB) << endl;

    for(i=0;i<k;i++){
        delete[] board[i];
    }
    delete[] board,diagonalLB_RT,diagonalLT_RB,horizontal;
    return 0;
}