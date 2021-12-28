#include <iostream>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;

void Selectionsort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}

int *random(int size)
{
    srand(time(NULL));
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % size;
    }
    return arr;
}

int main()
{
    int *arr;
    ofstream out;
    out.open("Input.txt");

    for (int size = 0; size < 1000; size += 5) //Taken  with an increment of 5
    {
        //Case A (Most Swap Involved) Worst Case
     

        arr = random(size);
        arr[0] = size; //Keeping the largest element in the beggining

        auto start = high_resolution_clock::now();
        Selectionsort(arr, size);
        auto stop = high_resolution_clock::now();
        auto worst_case = duration_cast<microseconds>(stop - start);

        //Case B (Least Swap Involved Case) Best Case
 

        auto start1 = high_resolution_clock::now();
        Selectionsort(arr, size);
        auto stop1 = high_resolution_clock::now();
        auto best_case = duration_cast<microseconds>(stop1 - start1);

        //Finding out the Average Case
       

        double sum = 0;
        for (int i = 0; i < 5; i++)
        {
            arr = random(size);

            auto start2 = high_resolution_clock::now();
            Selectionsort(arr, size);
            auto stop2 = high_resolution_clock::now();

            auto total = (duration_cast<microseconds>(stop2 - start2));
            sum = sum + total.count();
        }

        double average_case = 0.0;
        average_case = sum / 5;

        out << size << " " << (double)worst_case.count() << " " << (double)best_case.count() << " " << average_case << endl;
    }

    out.close();
    return 0;
}