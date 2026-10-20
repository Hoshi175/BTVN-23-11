#include <iostream>
using namespace std;

// Nhân arr1 với arr2 và lưu kết quả vào result.
void multiplication(int arr1[][2], int row1, int col1,
                    int arr2[][2], int row2, int col2,
                    int result[][2])
{
    // Nếu kích thước không phù hợp, đánh dấu kết quả bằng -1.
    if (col1 != row2)
    {
        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                result[i][j] = -1;
            }
        }
        return;
    }

    // Mỗi phần tử kết quả là tổng tích các phần tử tương ứng của một hàng và một cột.
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            result[i][j] = 0;

            // Cộng lần lượt arr1[i][k] * arr2[k][j].
            for (int k = 0; k < col1; k++)
            {
                result[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
}

int main()
{
    int a[2][2] = {{1, 2}, {3, 4}};
    int b[2][2] = {{5, 6}, {7, 8}};
    int result[2][2];

    multiplication(a, 2, 2, b, 2, 2, result);

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << result[i][j] << (j == 1 ? '\n' : ' ');
        }
    }

    return 0;
}