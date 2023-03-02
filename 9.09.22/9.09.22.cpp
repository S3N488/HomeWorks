#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL));
    int* arr = new int[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 21 - 10;
    }

    cout << "Original array:\n";
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;


    int countPos = 0;
    int countNeg = 0;
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] >= 0)
            countPos++;
        else
            countNeg++;
    }

    int* arrPos = new int[countPos];
    int* arrNeg = new int[countNeg];

    int posIndex = 0;
    int negIndex = 0;
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] >= 0)
        {
            arrPos[posIndex] = arr[i];
            posIndex++;
        }
        else
        {
            arrNeg[negIndex] = arr[i];
            negIndex++;
        }
    }

    cout << "Positive elements:\n";
    for (int i = 0; i < countPos; i++)
    {
        cout << arrPos[i] << " ";
    }
    cout << endl;

    cout << "Negative elements:\n";
    for (int i = 0; i < countNeg; i++)
    {
        cout << arrNeg[i] << " ";
    }
    cout << endl;

    delete[] arr;
    delete[] arrPos;
    delete[] arrNeg;

    return 0;
}
