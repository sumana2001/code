/*
Along one side of a road there is a sequence of vacant plots of land. Each plot has a different area. So the areas form a sequence A[1],A[2],...A[N]
You want to by K acres of land to build a house. You want to find all segments of continguous plots of whose sum is exactly K.
*/
#include <iostream>
using namespace std;

void housing(int *arr, int n, int k)
{
    int i = 0, j = 0, curr = 0;
    while (j < n)
    {
        curr += arr[j];
        j++;
        while (curr > k and i < j)
        {
            curr -= arr[i];
            i++;
        }
        if (curr == k)
        {
            cout << i << "-" << j - 1 << endl;
        }
    }
}

int main()
{
    int plots[] = {1, 3, 2, 1, 4, 1, 3, 2, 1, 1};
    int n = sizeof(plots) / sizeof(plots[0]);
    int k = 8;
    housing(plots, n, k);
    return 0;
}