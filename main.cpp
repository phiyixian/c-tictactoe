/*
 (Tic-Tac-Toe) Write a program that allows two players to play the tictac- toe game. Your
program must contain the class ticTacToe to implement a ticTacToe object. Include a
3-by-3 two-dimensional array, as a private member variable, to create the board. The
constructor should initialize the empty board to all zeros. Wherever the first player moves,
place a 1 in the specified square. Place a 2 wherever the second player moves. Each
move must be to an empty square. After each move, determine whether the game has
been won or is a draw. If needed, include additional member variables.
Include some of the operations on a ticTacToe object are printing the current board,
getting a move, checking if a move is valid, and determining the winner after each move.
Add additional operations as needed.
*/

#include <iostream>

class ticTacToe {
    private:
        int board[3][3];
    public:
        ticTacToe() {
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    board[i][j] = 0;
                }
            }
        }
        
        void printBoard() {
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    std::cout << board[i][j];
                }
                std::cout << std::endl;
            }
        }
        
        void nextMove(int player) {
            int move = 0;
            std::cout << "What is the next move? ";
            std::cin >> move;
            switch (move){
                case 1:
                    board[0][0] = player;
                    break;
                case 2:
                    board[0][1] = player;
                    break;
                case 3:
                    board[0][2] = player;
                    break;
                case 4:
                    board[1][0] = player;
                    break;
                case 5:
                    board[1][1] = player;
                    break;
                case 6:
                    board[1][2] = player;
                    break;
                case 7:
                    board[2][0] = player;
                    break;
                case 8:
                    board[2][1] = player;
                    break;
                case 9:
                    board[2][2] = player;
                    break;
                }
        }
        
        bool checkWin() {
            bool win;
            for(int i = 0; i < 3; i++){
                if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] != 0){
                    win = true;
                } else if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] != 0){
                    win = true;
                } else {
                    win = false;
                }
            }
        if (board[0][0] == board[1][1] == board[2][2] && board[2][2] != 0){
                win = true;
            } else if (board[0][2] == board[1][1] == board[2][0] && board[2][0] != 0){
                win = true;
            } else {
                win = false;
            }
        if (win == true){
            std::cout << "Game ended" << std::endl;
        }
        return win;
        }
};

int main() {
    // Write C++ code here
    ticTacToe t1;
    int player = 1;
    int played = 0;
    
    do {
        t1.printBoard();
        if (played == 0){
            player = 1;
            played = 1;
        } else if (played == 1){
            player = 2;
            played = 0;
        }
        t1.nextMove(player);
    } while (t1.checkWin() == false);
    
    if(player == 1) {
        std::cout << "Player 1 wins." << std::endl;
    } else {
        std::cout << "Player 2 wins." << std::endl;
    }

    return 0;
}
