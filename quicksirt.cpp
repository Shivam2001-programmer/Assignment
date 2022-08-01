#include <iostream>
using namespace std;
class QuickSort
{
    int n, a[100];

public:
    void Run();
    void swap(int &, int &);
    void print(int[], int);
    int partition(int[], int, int);
    void quicksort(int[], int, int);
};
void QuickSort::Run()
{
    cout << "\n Enter the size of the array:";
    cin >> n;
    cout << "\n Now Enter the element of the Array(max element 1000):";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    a[n + 1] = 1000;
    quicksort(a, 0, n + 1);
    print(a, n);
}
void QuickSort::swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void QuickSort::print(int a[], int size)
{
    cout << "\n This is the array:";
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int QuickSort::partition(int a[], int l, int h)
{
    int pivot = a[l];
    int i = l, j = h;
    while (i < j)
    {
        do
        {
            i++;
        } while (a[i] <= pivot);

        do
        {
            j--;

        } while (a[j] > pivot);
        if (i < j)
        {
            swap(a[i], a[j]);
        }
    }

    swap(a[l], a[j]);

    return j;
}
void QuickSort::quicksort(int a[], int l, int h)
{
    if (l < h)
    {
        int q = partition(a, l, h);
        quicksort(a, l, q);
        quicksort(a, q + 1, h);
    }
}
int main()
{
    QuickSort q;
    q.Run();
    return 0;
}