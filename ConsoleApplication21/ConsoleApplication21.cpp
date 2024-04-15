#include <iostream>
#include <cstdlib> 

using namespace std;

void matrixToArray(int matrix[][5], int size, int array[]) {
    int k = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            array[k++] = matrix[i][j];
        }
    }
}

int findMax(int array[], int size) {
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

int main() {
    const int size = 5;
    int matrix[size][size];
    int sum = 0;

    cout << "Matrix 5x5:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 20 - 10; 
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nSum of elements in rows with positive numbers:" << endl;
    for (int i = 0; i < size; i++) {
        bool positive = true;
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] <= 0) {
                positive = false;
                break;
            }
        }
        if (positive) {
            int rowSum = 0;
            for (int j = 0; j < size; j++) {
                rowSum += matrix[i][j];
            }
            cout << "Row " << i + 1 << ": " << rowSum << endl;
            sum += rowSum;
        }
    }
    cout << "Total sum: " << sum << endl;

    int array[size * size];
    matrixToArray(matrix, size, array);

    int maxElement = findMax(array, size * size);
    cout << "\nMax element in one-dimensional array " << maxElement << endl;

    return 0;
}
