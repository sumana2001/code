/*
Along one side of a road there is a sequence of vacant plots of land. Each plot has a different area. So the areas form a sequence A[1],A[2],...A[N]
You want to by K acres of land to build a house. You want to find the smallest window of continguous plots whose sum is exactly K.
*/
#include <iostream>
#include <limits.h>
using namespace std;

void housing(int *arr, int n, int k)
{
    int i = 0, j = 0, currSum = 0, currCount = 0, minCount = INT_MAX;
    int result[2];
    while (j < n)
    {
        currSum += arr[j];
        j++;
        while (currSum > k && i < j)
        {
            currSum -= arr[i];
            i++;
        }
        if (currSum == k)
        {
            currCount = j - i;
            if (minCount > currCount)
            {
                minCount = currCount;
                result[0] = i;
                result[1] = j - 1;
            }
        }
    }
    cout << result[0] << "-" << result[1];
}

int main()
{
    int plots[] = {1, 3, 2, 1, 4, 1, 3, 2, 1, 1};
    int n = sizeof(plots) / sizeof(plots[0]);
    int k = 8;
    housing(plots, n, k);
    return 0;
}