#include <iostream>
using namespace std;

const int ROWS = 3;
const int COLS = 3;

void drawBoard(char [ROWS][COLS]);
void player1Input(char [ROWS][COLS], int, int);
void player2Input(char [ROWS][COLS], int, int);
bool checkWinP1(char [ROWS][COLS], bool);
bool checkWinP2(char [ROWS][COLS], bool);
int turn = 0;

int main() {
    char dash[ROWS][COLS] = {{'-','-','-'},{'-','-','-'},{'-','-','-'}};
    int row, col;
    bool player1Turn = false;
    bool winCheck = true;
    bool isFull;
    drawBoard(dash);
    while (winCheck) {
        player1Input(dash, row, col);
        player1Turn = true;
        turn+=1;
        //cout << turn << endl;
        drawBoard(dash);
        winCheck = checkWinP1(dash, winCheck);
        if (winCheck == false) {
            return 0;
        }
        if (turn == 9 && winCheck == true) {
            cout << "Tie Game!";
            return 0;
        }
        if (player1Turn) {
            player2Input(dash, row, col);
            player1Turn = false;
            turn+=1;
            //cout << turn << endl;
            drawBoard(dash);
            winCheck = checkWinP2(dash, winCheck);
            if (winCheck == false) {
                return 0;
            }
            if (turn == 9 && winCheck == true) {
                cout << "Tie Game!";
                return 0;
            }
        }
    }
}

void drawBoard(char dash[ROWS][COLS]) {
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                cout << dash[i][j] << " ";
            }
        cout << endl;
    }
}

void player1Input(char dash[ROWS][COLS], int row, int col) {
    cout << "Please enter number of row from 1 to 3, Player 1: ";
    cin >> row;
    cout << "Please enter number of col from 1 to 3, Player 1: ";
    cin >> col;
    row-=1;
    col-=1;
    if (dash[row][col] == 'X' || dash[row][col] == 'O') {
        cout << "You can't go here! Please try again." << endl;
        cout << "Please enter number of row from 1 to 3, Player 1: ";
        cin >> row;
        cout << "Please enter number of col from 1 to 3, Player 1: ";
        cin >> col;
        row-=1;
        col-=1;
    }
    dash[row][col] = 'X';
}

void player2Input(char dash[ROWS][COLS], int row, int col) {
    cout << "Please enter number of row from 1 to 3, Player 2: ";
    cin >> row;
    cout << "Please enter number of col from 1 to 3, Player 2: ";
    cin >> col;
    row-=1;
    col-=1;
    if (dash[row][col] == 'X' || dash[row][col] == 'O') {
        cout << "You can't go here! Please try again." << endl;
        cout << "Please enter number of row from 1 to 3, Player 2: ";
        cin >> row;
        cout << "Please enter number of col from 1 to 3, Player 2: ";
        cin >> col;
        row-=1;
        col-=1;
    }
    dash[row][col] = 'O';
}

bool checkWinP1(char dash [ROWS][COLS], bool winCheck) {
    if ((dash[0][0] == 'X' && dash[0][1] == 'X' && dash[0][2] == 'X') || (dash[1][0] == 'X' && dash[1][1] == 'X' && dash[1][2] == 'X') || (dash[2][0] == 'X' && dash[2][1] == 'X' && dash[2][2] == 'X') || 
        (dash[0][0] == 'X' && dash[1][1] == 'X' && dash[2][2] == 'X') || (dash[0][2] == 'X' && dash[1][1] == 'X' && dash[2][0] == 'X') || 
        (dash[0][0] == 'X' && dash[1][0] == 'X' && dash[2][0] == 'X') || (dash[0][1] == 'X' && dash[1][1] == 'X' && dash[2][1] == 'X') || (dash[0][2] == 'X' && dash[1][2] == 'X' && dash[2][2] == 'X')) {
        cout << "Player 1 has won!";
        winCheck = false;
    }
    return winCheck;
}

bool checkWinP2(char dash [ROWS][COLS], bool winCheck) {
    if ((dash[0][0] == 'O' && dash[0][1] == 'O' && dash[0][2] == 'O') || (dash[1][0] == 'O' && dash[1][1] == 'O' && dash[1][2] == 'O') || (dash[2][0] == 'O' && dash[2][1] == 'O' && dash[2][2] == 'O') || 
        (dash[0][0] == 'O' && dash[1][1] == 'O' && dash[2][2] == 'O') || (dash[0][2] == 'O' && dash[1][1] == 'O' && dash[2][0] == 'O') || 
        (dash[0][0] == 'O' && dash[1][0] == 'O' && dash[2][0] == 'O') || (dash[0][1] == 'O' && dash[1][1] == 'X' && dash[2][1] == 'O') || (dash[0][2] == 'O' && dash[1][2] == 'O' && dash[2][2] == 'O')) {
        cout << "Player 2 has won!";
        winCheck = false;
    }
    return winCheck;
}
