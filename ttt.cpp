#include <iostream>
#include <limits>

using namespace std;

char grid[3][3] = {  {'.', '.', '.'}
                    ,{'.', '.', '.'}
                    ,{'.', '.', '.'}};
int rows = sizeof(grid)/sizeof(grid[0]);
int columns = sizeof(grid[0])/sizeof(grid[0][0]);


void drawGrid(){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            cout<<"| " << grid[i][j];
        }
        cout<<"|"<<endl;
    }
}


void menu(){
    cout << "\nSelect a number from this refrence grid to give input:- \n";
    cout << "1|2|3|\n";
    cout << "4|5|6|\n";
    cout << "7|8|9|\n";
}

void updateGrid(int choice, char symbol) {
    if (choice < 1 || choice > 9) {
        cout << "Invalid move!" << endl;
        return;
    }

    int row = (choice - 1) / 3; // map 1-9 → row
    int col = (choice - 1) % 3; // map 1-9 → col

    if (grid[row][col] == '.') { // check if empty
        grid[row][col] = symbol;
    } else {
        cout << "Block already taken!" << endl;
    }
    drawGrid();
    cout << endl;
}

int Input(){
    int p=0;
    cin >> p;

    return p;
}

bool isEmpty() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (grid[i][j] == '.') {
                return true; // found at least one empty space
            }
        }
    }
    return false; // no empty spaces left
}

bool CheckWin() {
    // Check rows
    for (int i = 0; i < rows; i++) {
        if (grid[i][0] != '.' && grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]) {
            cout << "Player " << (grid[i][0] == 'X' ? "1 (X)" : "2 (O)") << " wins!\n";
            return true;
        }
    }

    // Check columns
    for (int j = 0; j < columns; j++) {
        if (grid[0][j] != '.' && grid[0][j] == grid[1][j] && grid[1][j] == grid[2][j]) {
            cout << "Player " << (grid[0][j] == 'X' ? "1 (X)" : "2 (O)") << " wins!\n";
            return true;
        }
    }

    // Check main diagonal
    if (grid[0][0] != '.' && grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) {
        cout << "Player " << (grid[0][0] == 'X' ? "1 (X)" : "2 (O)") << " wins!\n";
        return true;
    }

    // Check anti-diagonal
    if (grid[0][2] != '.' && grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) {
        cout << "Player " << (grid[0][2] == 'X' ? "1 (X)" : "2 (O)") << " wins!\n";
        return true;
    }

    return false; // no winner yet
}



int main() {
    cout << "///////////////////////////////////////////////////////////////////////\n";
    menu();
    do {
        cout << "///////////////////////////////////////////////////////////////////////\n";
        cout << "Player 1 (X) turn: ";
        int player1 = Input();
        updateGrid(player1, 'X');
        if (CheckWin()) break; // check after player 1 move

        if (!isEmpty()) break; // stop if board is full

        cout << "///////////////////////////////////////////////////////////////////////\n";
        cout << "Player 2 (O) turn: ";
        int player2 = Input();
        updateGrid(player2, 'O');
        if (CheckWin()) break; // check after player 2 move

    } while (isEmpty());

    if (!CheckWin()) {
        cout << "It's a draw!\n";
    }

    // Pause before exit
    cout << "\nPress Enter to exit...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear leftover input
    cin.get(); // wait for Enter

    return 0;
}
