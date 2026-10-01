#include <iostream>

using namespace std;

void sort_elements (int arr[], int size)
{
    int i, j, temp;
    for (i = 0; i < size - 1; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (arr[j] > arr[i])    //xắp sếp giảm dần
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = {10, 67, 89, 31};
    int size = 4;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    sort_elements (arr, size);
    cout << "\nMang sau khi sap xep thanh dang giam dan: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}