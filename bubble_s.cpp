#include <iostream>
#include <omp.h>
using namespace std;
void bubble(int *a, int n)
{
    #pragma omp parallel for num_threads(5)
    for (int i = 0; i < n - 1; i++)
    {
        #pragma omp parallel for
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

void bubbleSerial(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

void swap(int &a, int &b)
{
    int test;
    test = a;
    a = b;
    b = test;
}
int main()
{
    int *a, n;
    cout << "enter total no of elements=>\n";
    cin >> n;
    a = new int[n];
    cout << "enter elements=>\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
   // double start_time = omp_get_wtime(); // start timer for sequential algorithm
    bubbleSerial(a, n);
    //double end_time = omp_get_wtime(); // end timer for sequential algorithm
    cout << "sorted array is sequential=>\n";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    //cout << "Time taken by sequential algorithm: " << end_time - start_time << " seconds" << endl;
    //start_time = omp_get_wtime(); // start timer for parallel algorithm
    bubble(a, n);
    //end_time = omp_get_wtime(); // end timer for parallel algorithm
    cout << "sorted array is=>\n";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    //cout << "Time taken by parallel algorithm: " << end_time - start_time << " seconds" << endl;
    return 0;
}