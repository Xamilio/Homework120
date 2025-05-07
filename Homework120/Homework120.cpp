#include <iostream>
using namespace std;

void printArray(int** arr, int rows, int cols)
{
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

int** addRowToEnd(int** arr, int& rows, int cols, int* newRow)
{
    int** newArr = new int* [rows + 1];
    for (int i = 0; i < rows; ++i)
        newArr[i] = arr[i];
    newArr[rows] = newRow;
    ++rows;
    delete[] arr;
    return newArr;
}

int** addRowToStart(int** arr, int& rows, int cols, int* newRow)
{
    int** newArr = new int* [rows + 1];
    newArr[0] = newRow;
    for (int i = 0; i < rows; ++i)
        newArr[i + 1] = arr[i];
    ++rows;
    delete[] arr;
    return newArr;
}

int** addRowAtPosition(int** arr, int& rows, int cols, int* newRow, int pos)
{
    if (pos < 0 || pos > rows) return arr;
    int** newArr = new int* [rows + 1];
    for (int i = 0; i < pos; ++i)
        newArr[i] = arr[i];
    newArr[pos] = newRow;
    for (int i = pos; i < rows; ++i)
        newArr[i + 1] = arr[i];
    ++rows;
    delete[] arr;
    return newArr;
}

int** deleteRow(int** arr, int& rows, int cols, int pos)
{
    if (pos < 0 || pos >= rows) return arr;
    delete[] arr[pos];
    int** newArr = new int* [rows - 1];
    for (int i = 0, j = 0; i < rows; ++i)
    {
        if (i == pos) continue;
        newArr[j++] = arr[i];
    }
    --rows;
    delete[] arr;
    return newArr;
}

int main()
{
    setlocale(LC_ALL, "ukr");
    int rows = 2, cols = 3;
    int** arr = new int* [rows];
    for (int i = 0; i < rows; ++i)
    {
        arr[i] = new int[cols];
        for (int j = 0; j < cols; ++j)
            arr[i][j] = i * cols + j;
    }

    cout << "Початковий масив:\n";
    printArray(arr, rows, cols);

    int* newRow1 = new int[cols] {10, 11, 12};
    arr = addRowToEnd(arr, rows, cols, newRow1);

    int* newRow2 = new int[cols] {20, 21, 22};
    arr = addRowToStart(arr, rows, cols, newRow2);

    int* newRow3 = new int[cols] {30, 31, 32};
    arr = addRowAtPosition(arr, rows, cols, newRow3, 2);

    arr = deleteRow(arr, rows, cols, 1);

    cout << "Оновлений масив:\n";
    printArray(arr, rows, cols);

    for (int i = 0; i < rows; ++i) delete[] arr[i];
    delete[] arr;
}
