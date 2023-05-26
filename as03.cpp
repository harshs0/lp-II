// selection sort
#include <bits/stdc++.h>
using namespace std;

void sel(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min=i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            min=j;
        }
        if(min!=i)
        swap(arr[i],arr[min]); 
    }
}

void printt(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the size of array : " << endl;
    cin >> n;
    int arr[50];

    cout << "Enter the elements : ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sel(arr, n);
    cout << "Sorted array is : " << endl;
    printt(arr, n);
}