#include <iostream>
#include <string>
using namespace std;

int main()
{
    // pointers and arrays:
    int arr[6] = {1, 2, 3, 4, 5, 6};
    cout << "address of first memory block of arr is " << arr << endl;
    cout << "address of first memory block of arr is " << &arr << endl;
    cout << "address of first memory block of arr is " << &arr[0] << endl;
    cout << "address of first memory block of arr is " << &arr[5] << endl;

    cout << "value at arr[3] is " << *&arr[3] << endl; // deknha chah rha tha ki * & ke saath use ho sakta hai ki nhi

    // ye to kuch naya tha:
    int i = 3;
    cout << i[arr] << endl; // ye bilkul valid hai, expecting value 4.
                            /*
                            uses the concept arr[i] = *(arr + i)
                            => i[arr] = *(i + arr)
                            */

    cout << "----------------------------------------------------------" << endl;
    cout << sizeof(&arr) << endl;
    cout << sizeof(arr) << endl;
    cout << "----------------------------------------------------------" << endl;

    // char array and its differences form int arr:
    int in[5] = {1, 2, 3, 4, 5};
    char ch[5] = "abcd";
    char ch2[5] = {'a', 'b', 'c', 'd'};

    cout << in<< endl;   // implementation of cout fun is different for int arr and char arr.
    cout << ch << endl;  // should get address of first ch block but getting value of ch.



}