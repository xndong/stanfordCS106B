#include <iostream>
#include <array>

using namespace std;

template <typename T, int col, int row>
void printTwoDimensionArray(array<array<T, col>, row> &twoDimensionArray);
template <typename T, int col, int row>
void printTwoDimensionArray2(array<array<T, col>, row> &twoDimensionArray);

template <typename T, int col, int row, int printCol, int printRow>
void printPartTwoDimensionArray(array<array<T, col>, row> &twoDimensionArray);
template <typename T, int col, int row, int printColStart, int printColEnd, int printRowStart, int printRowEnd>
void printPartTwoDimensionArray(array<array<T, col>, row> &twoDimensionArray);

int main()
{
    /**
     * 由于std::array容器是static memory分配，所以下面代码肯定在编译时是wrong的
     * int numbers;
     * cin >> numbers;
     * array<int, numbers> arr;
     * 其错误与C语言中如下代码的错误一样
     * int n = 100;
     * int arr[n];
     * int arr[...]是静态内存分配，是在compile time时就要分配好。但是n = 100只有在代码运行的run time时候才发生，也就是说在run time期间 variable n存储了100（value）。
     * 所以会发生错误。
     */

    array<array<int, 8>, 10> twoDimensionArray;
    for (int i = 0; i < 10; i++)
    {
        twoDimensionArray[i].fill(0);
    }

    printTwoDimensionArray<int, 8, 10>(twoDimensionArray);
    cout << endl;
    printTwoDimensionArray2<int, 8, 10>(twoDimensionArray);
    cout << endl;

    //print part of the twoDimensionArray
    printPartTwoDimensionArray<int, 8, 10, 4, 4>(twoDimensionArray);
    /**
     * template parameter must be assigned value explictly during complile time('static'). Not 'dynamic' in run time.
     * 因此下面的代码编译时会出现error。
     * 
     * int row, col, printRow, printCol;
     * row = twoDimensionArray.size();
     * col = twoDimensionArray[0].size();
     * cout << "Input rows and columns you want to print: ";
     * cin >> printRow;
     * cin >> printCol;
     * printPartTwoDimensionArray<int, col, row, printCol, printRow>(twoDimensionArray);
     * 因为这4个varible都必须在代码运行时（runtime阶段）才能获得value。
     * -----------------------------------------------------------------------
     * int a = 4, b = 4;
     * printPartTwoDimensionArray<int, 8, 10, a, b>(twoDimensionArray);
     * 同样不行，因为a=4,b=4也都是在run time才有value,在compile阶段是没有value的。但是template parameter要在compile阶段就知道value。contradict！
     * just as memory allocate: int a[n],这种code pattern是static memory allocate, i.e. 在complile阶段就得知道value。
     * 然而n必须在run time阶段才能获得值。
     */
    return 0;
}

// we also include nontype template parameter: col, row
template <typename T, int col, int row>
void printTwoDimensionArray(array<array<T, col>, row> &twoDimensionArray)
{
    for (auto line : twoDimensionArray)
    {
        for (auto element : line)
        {
            cout << element << " ";
        }
        cout << endl;
    }
}

template <typename T, int col, int row>
void printTwoDimensionArray2(array<array<T, col>, row> &twoDimensionArray)
{
    for (int x = 0; x < row; x++)
    {
        for (int y = 0; y < col; y++)
            cout << twoDimensionArray[x][y] << " ";
        cout << endl;
    }
}

/**
 * print part of two dimension array
 */
template <typename T, int col, int row, int printCol, int printRow>
void printPartTwoDimensionArray(array<array<T, col>, row> &twoDimensionArray)
{
    for (int x = 0; x < printRow; x++)
    {
        for (int y = 0; y < printCol; y++)
            cout << twoDimensionArray[x][y] << " ";
        cout << endl;
    }
}

template <typename T, int col, int row, int printColStart, int printColEnd, int printRowStart, int printRowEnd>
void printPartTwoDimensionArray(array<array<T, col>, row> &twoDimensionArray)
{
    for (int x = printRowStart; x < printRowEnd; x++)
    {
        for (int y = printColStart; y < printColEnd; y++)
            cout << twoDimensionArray[x][y] << " ";
        cout << endl;
    }
}

/**
 * container properties/features
 * please visit cplusplus.com to learn more about the features of container array
 * 1. fixed-size
 * 2. compile-time i.e. non dynamic memory management
 */