#include <iostream>
using namespace std;

class NQueen
{
public:
    void printSolution(int board[][8], int N);
    void solveNQUtil(int board[][8], int col, int N);
    bool isSafe(int board[][8], int row, int col, int N);
    void solveNQ(int N);
};

void NQueen::printSolution(int board[][8], int N)
{
    static int solutionCount = 0;
    cout << "Solution " << ++solutionCount << ":\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j])
                cout << "P ";
            else
                cout << ". ";
        }
        cout << "\n";
    }
    cout << "\n";
}

bool NQueen::isSafe(int board[][8], int row, int col, int N)
{
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

void NQueen::solveNQUtil(int board[][8], int col, int N)
{
    if (col >= N)
    {
        printSolution(board, N);
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i, col, N))
        {
            board[i][col] = 1;
            solveNQUtil(board, col + 1, N);
            board[i][col] = 0; // Backtrack
        }
    }
}

void NQueen::solveNQ(int N)
{
    int board[8][8]; // Assuming the board size is fixed at 8x8
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            board[i][j] = 0;
        }
    }

    solveNQUtil(board, 0, N);
}

int main()
{
    int N;
    cout << "Enter the number of queens: ";
    cin >> N;
    if(N==2 || N==3){
        cout<<"No solution for "<<N<<"\n";
    }
    NQueen nq;

    clock_t start = clock();
    nq.solveNQ(N);
    clock_t end = clock();

    double execution_time = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "The time taken by NQueen is " << fixed << execution_time << " seconds";
    return 0;
}
