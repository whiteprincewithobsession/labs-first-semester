#include <iostream>
int main()
{
    int row, col;
    int** mtrx1, ** mtrx2, ** mtrx3;
    std::cin >> row;

    mtrx1 = new int* [row];
    for (int i = 0; i < row; i++)
    {
        mtrx1[i] = new int[row];
        for (int j = 0; j < row; j++)
        {
            std::cin >> mtrx1[i][j];
        }
    }
    std::cin >> col;
    mtrx2 = new int* [col];
    for (int i = 0; i < col; i++)
    {
        mtrx2[i] = new int[col];
        for (int j = 0; j < col; j++)
        {
            std::cin >> mtrx2[i][j];
        }
    }

    mtrx3 = new int* [row];
    for (int i = 0; i < row; i++)
    {
        mtrx3[i] = new int[col];
        for (int j = 0; j < col; j++)
        {
            mtrx3[i][j] = 0;
            for (int k = 0; k < col; k++)
                mtrx3[i][j] += mtrx1[i][k] * mtrx2[k][j];
        }
    }

    for (int i = 0; i < row; i++)
    {
        int j;
        for (j = 0; j < col; j++) {
            if (j == col) {
                std::cout << mtrx3[i][j];
            }
            if (i == row && j == col) {
                std::cout << mtrx3[i][j];
            }
            else if (j != col) {
                std::cout << mtrx3[i][j] << " ";
            }
        }
        if (i == row && j == col) {
            break;
        }
        else {
            std::cout << '\n';
        }
    }
    std::cout << '\n' << mtrx3[row - 1][col - 1];
}