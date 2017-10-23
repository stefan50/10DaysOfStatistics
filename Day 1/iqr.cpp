//Programme that evaluates IQR (interquartile range) = Q3 - Q1

#include <iostream>
#include <algorithm> 
#include <stdlib.h>
#include <iomanip>
using namespace std;

float median(float* arr,int num);

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    int sum = 0;
    cin >> n;
    float* arr;
    float nums[n];
    int quantities[n];
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }
    for(int i=0; i<n; i++)
    {
        cin >>  quantities[i];
    }
    for(int i=0; i<n; i++)
    {
        sum += quantities[i];
    }
    arr = (float*)malloc(sizeof(float)*sum);
    for(int i = 0,k = 0; i < sum; i += quantities[k], k++)
    {
        for(int j = 0;j < quantities[k]; j++)
        {
            *(arr+i+j) = nums[k];
        }
    }
    sort(arr,arr+sum);
    float q2 = median(arr,sum);
    float q3;
    if(sum%2 == 0)
    {
        q3 = median(arr+sum/2,sum/2);
    }
    else
    {
        q3 = median(arr+n/2+1,sum/2);
    }
    float q1 = median(arr,sum/2);
    cout << fixed << setprecision(1) << q3-q1 << endl;
    free(arr);
    return 0;
}

float median(float* arr,int num)
{
    float to_return = 0;
    if(num % 2 != 0)
    {
        num /= 2;
        to_return = *(arr+num);
    }
    else
    {
        num /= 2;
        to_return = (*(arr+num) + *(arr+num-1))/2;
    }
    return to_return;
}
