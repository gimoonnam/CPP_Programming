#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;

test 1

class Checker{
public:
    static void PrintBoard(vector<vector<char>>& board){
        for (int i=0; i<board.size() ; ++i)
        {
            for (int j=0; j<board[0].size() ; ++j)
            {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
        cout << endl;
    }

	static void PrintSubBox(vector<vector<char>>& board, int startCol, int startRow ){
        for (int i=startCol; i< startCol+3; ++i)
        {
            for (int j=startRow; j<startRow+3 ; ++j)
            {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
        cout << endl;
    }


    static bool isValidSudoku(vector<vector<char>>& board){
        vector<vector<bool>> subBoxes(9, vector<bool>(10, false));
        vector<vector<bool>> visitedColNums(9, vector<bool>(10, false));
        vector<vector<bool>> visitedRowNums(9, vector<bool>(10, false));

        for (int i=0; i<board.size() ; ++i)
        {
            for (int j=0; j<board[0].size() ; ++j)
            {
                if(board[i][j]=='.') continue;

                int num = board[i][j]-'0';
                int subBoxIdx = i/3 *3 + j/3;

                if(visitedColNums[i][num] || visitedRowNums[j][num]
                   || subBoxes[subBoxIdx][num])
                    return false;

                visitedColNums[i][num]=true;
                visitedRowNums[j][num]=true;
                subBoxes[subBoxIdx][num] = true;
            }
        }
        return true;
    }
};


class Solver{
public:
	static bool solveSudokuCell(int row, int col, vector<vector<char>>& board)
    {
        if( col == board.size()){
            col = 0;
            row++;
        }

        if(row == board[0].size()){
            return true; // end of this program
        }


        if(board[row][col] != '.'){
            return solveSudokuCell(row, ++col, board);
        }


        for(int value = 1; value <= board.size() ; value++){
            char charToPlace = (char)(value+'0');

            if (canPlaceValue(board, row, col, charToPlace)) {
                board[row][col] = charToPlace;
                if (solveSudokuCell(row, col + 1, board)) { // recurse with our VALID placement
                    return true;
                }
            }
        }

        board[row][col] = '.';
        return false;
    }

private:
    static bool canPlaceValue(vector<vector<char>>& board, int row, int col, char charToPlace){

        for(int i=0; i<board.size(); ++i){
            if(charToPlace == board[row][i] || charToPlace == board[i][col]) return false;
        }

        int regionSize = 3;
        int I = row/regionSize;
        int J = col/regionSize;

        int topLeftOfSubBoxRow = regionSize * I; // the row of the top left of the block
        int topLeftOfSubBoxCol = regionSize * J; // the column of the tol left of the block

        for (int i = 0; i < regionSize; i++) {
            for (int j = 0; j < regionSize; j++) {
                if (charToPlace == board[topLeftOfSubBoxRow + i][topLeftOfSubBoxCol + j]) {
                    return false;
                }
            }
        }

        return true;
    }

};

int main(){
    vector<vector<char>> board{
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

	Checker::PrintBoard(board);
	if(Checker::isValidSudoku(board)){
		cout << "is valid sudoku" << endl;
	}
	else {
		cout << "is not valid sudoku" << endl;
	}

    cout << " \n" << endl;

    if(Solver::solveSudokuCell(0,0,board)){
        Checker::PrintBoard(board);
    }


	return EXIT_SUCCESS;
}
