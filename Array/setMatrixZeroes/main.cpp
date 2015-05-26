
//Set Matrix Zeroes

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{
    size_t m = matrix.size();
    size_t n = matrix[0].size();

    int* row = new int[m];
    int* col = new int[n];

    memset(row, -1, sizeof(int)*m);
    memset(col, -1, sizeof(int)*n);

    for(size_t i = 0; i < m; i++) {
        for(size_t j = 0; j < n; j++) {
            if(matrix[i][j] == 0) {
                row[i] = 0;
                col[j] = 0;
            }
        }
    }

    for(size_t i = 0; i < m; i++) {
        if(row[i] == 0) {
            for(size_t j = 0; j < n; j++)
                matrix[i][j] = 0;
        }
    }

    for(size_t i = 0; i < n; i++) {
        if(col[i] == 0) {
            for(size_t j = 0; j < m; j++)
                matrix[j][i] = 0;
        }
    }

    delete []row;
    delete []col;
}

void printMatrix(vector<vector<int>> &matrix)
{
    size_t m = matrix.size();
    size_t n = matrix[0].size();

    for(size_t i = 0; i < m; i++) {
        for(size_t j = 0; j < n; j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

int main()
{
    vector<vector<int>> matrix;
    vector<int> num;
    matrix.push_back(num);
    matrix.push_back(num);
    matrix.push_back(num);
    for(size_t i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < 4; j++) {
            matrix[i].push_back(j+1);
        }
    }
    matrix[1][2] = 0;

    printMatrix(matrix);
    setZeroes(matrix);
    cout<<"After set zero: "<<endl;
    printMatrix(matrix);
    return 0;
}
