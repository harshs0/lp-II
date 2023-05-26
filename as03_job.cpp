#include <bits/stdc++.h>
using namespace std;

void calwaittime(int ar[], int bt[], int n)
{
    int wt[n];
    float sum = 0;
    float average;

    wt[0] = 0;

    cout << "PR"
         << "  "
         << "AT"
         << "   "
         << "BT"
         << "   "
         << "WT" << endl;
    cout << 1 << "  " << ar[0] << " " << bt[0] << " " << wt[0] << endl;

    for (int i = 1; i < n; i++)
    {
        wt[i] = (ar[i - 1] + bt[i - 1] + wt[i - 1] - ar[i]);
        cout << i + 1 << " " << ar[i] << " " << bt[i] << "  " << wt[i] << endl;
    }

    for (int i = 0; i < n; i++)
        sum = sum + wt[i];

    average=sum/n;
    cout<<"Average waiting time is : "<<average<<endl;
}

int main()
{
    int n;
    int ar[50];
    int bt[50];
    cout << "Enter the number of processes : " << endl;
    cin >> n;
    cout << "Enter the arriving time for the processes : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "p" << i + 1 << ": ";
        cin >> ar[i];
    }

    cout << "Enter the burst time for the processes : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "p" << i + 1 << ": ";
        cin >> bt[i];
    }

    calwaittime(ar, bt, n);
}