#include <iostream>
using namespace std;


int main() {
    // static 2-d array:
    int arr[3][4];


    int m =3;
    int n = 4;
    // 1-d dynamic array:
    int *arr1 = new int[n];
 
    // creating 2-d dynamic array [m][n]:
    int **arr2D = new int*[m]; // created a 1d array with n columns.
    for(int i=0; i<m; i++) {   // merging those 1d colums as rows to create 2d array.
        arr2D[i] = new int[n];
    }

    // taking input in the array:
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++) {
            cin >> arr2D[i][j];
        }
    }

    // reading the array:
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++) {
            cout << arr2D[i][j] << " ";
        }
        cout << endl;
    }

}