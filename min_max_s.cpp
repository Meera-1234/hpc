#include <iostream>
#include <vector>
#include <omp.h>
#include <climits>
using namespace std;
void min_reduction(vector<int> &arr)
{
    int min_value = INT_MAX;
    // algorithms which combine an array of elements producing a single value as a result
    #pragma omp parallel for reduction(min : min_value)
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < min_value)
        {
            min_value = arr[i];
        }
    }
    cout << "Minimum value: " << min_value << endl;
}
void max_reduction(vector<int> &arr)
{
    int max_value = INT_MIN;
    #pragma omp parallel for reduction(max : max_value)
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > max_value)
        {
            max_value = arr[i];
        }
    }
    cout << "Maximum value: " << max_value << endl;
}
void sum_reduction(vector<int> &arr)
{
    int sum = 0;
    #pragma omp parallel for reduction(+ : sum)
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }
    cout << "Sum: " << sum << endl;
}
void average_reduction(vector<int> &arr)
{
    int sum = 0;
    #pragma omp parallel for reduction(+ :sum)
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }
    cout << "Average: " << (double)sum / arr.size() << endl;
}
int main()
{
    vector<int> arr = {5, 2, 19, 1, 7, 6, 8, 3, 4};

    min_reduction(arr);
    max_reduction(arr);
    sum_reduction(arr);

   // double start = omp_get_wtime();
    average_reduction(arr);
    //double end = omp_get_wtime();
    //double time = end - start;

    //cout << "Time: " << time << " seconds" << endl;
}