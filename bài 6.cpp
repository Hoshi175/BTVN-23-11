#include <iostream>

using namespace std;

int add_diagonal (int arr[3][3], int row, int col)
{
    int tong = 0;   // Khởi tạo biến tong để lưu tổng các phần tử trên đường chéo chính và luôn phải để bằng 0 nếu không để thì nó sẽ lấy giá trị nào đó
    for (int i = 0; i < row && i < col; ++i)
    {
        tong += arr[i][i];  //Cộng dồn các phần tử trên đường chéo và thay cho "tong = tong + arr[i][i]"
    }
    return tong;
}
int main()
{
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };  //Tạo bảng 3x3 nhưng không có xuất ra màn hình
    cout <<"Tong duong cheo: " << add_diagonal(arr, 3, 3) ;
    return 0;
}