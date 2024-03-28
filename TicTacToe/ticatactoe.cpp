#include <iostream>
#include <vector>

using namespace std;

//Creating game board 3x3
vector<vector<char>> board(3,vector<char>(3,' '));

//Check the game status

char checkstatus()
{
    //check row
    for(int i=0; i<3;i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return board[i][0];
    }

    //check coulumn
     for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return board[0][i];
    }

    // cross check
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return board[0][0];
    
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return board[0][2];

    // game continues
    return ' ';
}








void printboard()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<< board[i][j];
            if(j<2) cout << " |";
        }
        cout << endl;
        if(i<2) cout << "--------"<< endl;
    }
    cout<< endl;
}



int main()
{
    int row,coulumn ;
    char player ='X';
    int movecount =0;

    while(true)
    {
        //print game board in screen
        printboard();
        cout<<"Turn in "<<player <<"  Enter the row and column you want to make a move on (1-3):";
        cin>>row>> coulumn;
 
        row--;
        coulumn--;

        //invalid move check
        if(row <0 || row >=3 || coulumn<0 || coulumn >=3 || board[row][coulumn]!=' ')
        {
            cout<<"Invalid move. Please try again."<<endl;
        }

        //process the move into board
        board[row][coulumn]=player;
        movecount++;

        //check the game status
        char status = checkstatus();
        if(status =='X'|| status=='0')
        {
            printboard();
            cout<<"Game ends! Winner is :"<<status<<endl;
            break;
        }
        else if(movecount ==9)
        {
            printboard();
            cout<<"Game is draw!"<<endl;
            break;
        }
        player =(player=='X') ? 'O' : 'X';
    }

    return 0;
}


