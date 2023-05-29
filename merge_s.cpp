#include <iostream>
#include <omp.h>

using namespace std;

void mergesort(int a[], int i, int j);
void merge(int a[], int i1, int j1, int i2, int j2);

void mergesort(int a[], int i, int j)
{
    int mid;
    if (i < j)
    {
        mid = (i + j) / 2;

        #pragma omp parallel sections
        {
            #pragma omp section
            {
                mergesort(a, i, mid);
            }
            #pragma omp section
            {
                mergesort(a, mid + 1, j);
            }
        }
        merge(a, i, mid, mid + 1, j);
    }
}

void merge(int a[], int first, int mid, int mid2, int last)
{
    int temp[1000];
    int i, j, k;

    i = first;
    j = mid2;
    k = 0;

    while (i <= mid && j <= last)
    {
        if (a[i] < a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = a[i++];
    }

    while (j <= last)
    {
        temp[k++] = a[j++];
    }

    for (i = first;i<=last; i++)
    {
        a[i] = temp[i - first];
    }
}

int main()
{
    int *a, n, i;
    double start_time, end_time, seq_time, par_time;

    cout << "Enter the total number of elements: ";
    cin >> n;

    a = new int[n];

    cout << "Enter the elements: ";
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // Parallel algorithm
    //start_time = omp_get_wtime();
    mergesort(a, 0, n - 1);
    //end_time = omp_get_wtime();
    par_time = end_time - start_time;
    //cout << "Parallel Time: " << par_time << " seconds" << endl;

    cout << "Sorted array: ";
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    delete[] a;
    return 0;
}