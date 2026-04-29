#include <bits/stdc++.h>
using namespace std;
void bruteMergeTwoSortedArrays(int arr1[], int arr2[], int n, int m)
{
    int len = n + m;
    int arr3[len];
    int left = 0, right = 0, index = 0;
    while (left < n && right < m)
    {
        if (arr1[left] <= arr2[right])
        {
            arr3[index++] = arr1[left++];
        }
        else
        {
            arr3[index++] = arr2[right++];
        }
    }
    while (left < n)
    {
        arr3[index++] = arr1[left++];
    }
    while (right < m)
    {
        arr3[index++] = arr2[right++];
    }

    for (int i = 0; i < len; i++)
    {
        if (i < n)
        {
            arr1[i] = arr3[i];
        }
        else
        {
            arr2[i - n] = arr3[i];
        }
    }
}
void optimal01MergeTwoSortedArrays(int arr1[], int arr2[], int n, int m)
{
    int left = n - 1;
    int right = 0;
    while (left >= 0 && right < m)
    {
        if (arr1[left] >= arr2[right])
        {
            swap(arr1[left], arr2[right]);
            left--;
            right++;
        }
        else
        {
            break;
        }
    }

    sort(arr1, arr1 + n);
    sort(arr2, arr2 + n);
}
void optimal02MergeTwoSortedArrays(int arr1[], int arr2[], int n, int m)
{
    int len = n + m;
    int gap = (len / 2) + (len % 2);
    while (gap > 0)
    {
        int left = 0;
        int right = left + gap;
        while (right < len)
        {
            if (left < n && right >= n)
            {
                if (arr1[left] > arr2[right - n])
                {
                    swap(arr1[left], arr2[right-n]);
                }
            }
            else if (left >= n)
            {
                if (arr2[left - n] > arr2[right - n])
                {
                    swap(arr2[left-n], arr2[right-n]);
                }
            }
            else
            {
                // arr1 arr1
                if (arr1[left] > arr1[right])
                {
                    swap(arr1[left], arr1[right]);
                }
            }
            left++;
            right++;
        }
        if (gap == 1)
            {
                break;
            }
        gap = (gap / 2) + (gap % 2);
    }
}
int main()
{
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {0, 2, 6, 8, 9};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    optimal02MergeTwoSortedArrays(arr1, arr2, size1, size2);
    for (int i = 0; i < size1; i++)
    {
        cout << arr1[i] << " ";
    }
    for (int i = 0; i < size2; i++)
    {
        cout << arr2[i] << " ";
    }
    return 0;
}