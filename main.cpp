#include <iostream>
#include <string>


const size_t SUDOKU_SIZE = 9;
const size_t STRING_in = 11;

void get_sudoku(int sudoku[][SUDOKU_SIZE]);
void print_sudoku(int sudoku[][SUDOKU_SIZE]);
int find_empty(int sudoku[][SUDOKU_SIZE]);
bool solve_sudoku(int sudoku[][SUDOKU_SIZE]);

int main() {
    int sudoku[SUDOKU_SIZE][SUDOKU_SIZE] = {0};
    std::cout << "Sudoku-Solver" << "\n" << std::endl;
    get_sudoku(sudoku);
    solve_sudoku(sudoku);
    if (solve_sudoku(sudoku)) {
        print_sudoku(sudoku);
    } else {
        std::cout << "No solution found!" << std::endl;
    }
    return 0;
}

void get_sudoku(int sudoku[][SUDOKU_SIZE]){
    int x;
    int y = 0;
    std::string line;
    std::cout << "Please enter Sudoku: \n\n";
    for (int row = 0; row < STRING_in; row++) {
        x = 0;
        std::getline(std::cin, line);
        for (int i = 0; i < line.length(); i++) {
            if(line[i] >= '0' && line[i] <= '9'){
                sudoku[y][x] = int(line[i]) - int('0');
                x++;
            }

        }
        if (!(row == 3 || row == 6)){
            y++; }
    }
}

void print_sudoku(int sudoku[][SUDOKU_SIZE]){
    for (int i = 0; i < SUDOKU_SIZE; i++) {
        if (i == 3 || i == 6){
            std::cout << "-----------------------" << std::endl;
        }
        for (int j = 0; j < SUDOKU_SIZE; j++) {
            std::cout << " ";
            if(j == 3 || j == 6){
                std::cout << "| ";
            }
            std::cout << sudoku[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << "\n";
}

int find_empty(int sudoku[][SUDOKU_SIZE]){
    for (int y = 0; y < SUDOKU_SIZE; y++) {
        for (int x = 0; x < SUDOKU_SIZE; x++) {
            if(sudoku[y][x] == 0){
                return y*9 + x;
            }
        }
    }
    return -1;
}

bool check_row(int sudoku[][SUDOKU_SIZE], int row, int number){
    for (int i = 0; i < SUDOKU_SIZE; i++) {
        if(sudoku[row][i] == number){
            return false;
        }
    }
    return true;
}

bool check_column(int sudoku[][SUDOKU_SIZE], int column, int number){
    for (int i = 0; i < SUDOKU_SIZE; i++) {
        if(sudoku[i][column] == number){
            return false;
        }
    }
    return true;
}

bool check_square(int sudoku[][SUDOKU_SIZE], int row, int column, int number){
    int row_start = (row / 3) * 3;
    int column_start = (column / 3) * 3;
    for (int i = row_start; i < row_start + 3; i++) {
        for (int j = column_start; j < column_start + 3; j++) {
            if(sudoku[i][j] == number){
                return false;
            }
        }
    }
    return true;
}

bool check_number(int sudoku[][SUDOKU_SIZE], int row, int column, int number){
    return check_row(sudoku, row, number) && check_column(sudoku, column, number) && check_square(sudoku, row, column, number);
}

bool solve_sudoku(int sudoku[][SUDOKU_SIZE]){
    int row;
    int column;
    int position = find_empty(sudoku);
    if(position == -1){
        return true;
    }
    row = position / 9;
    column = position % 9;
    for (int i = 1; i <= 9; i++) {
        if(check_number(sudoku, row, column, i)){
            sudoku[row][column] = i;
            if(solve_sudoku(sudoku)){
                return true;
            }
            sudoku[row][column] = 0;
        }
    }
    return false;
}
