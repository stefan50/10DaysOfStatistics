// Programme that calculates weighted mean

#include <iostream>
#include <iomanip>
using namespace std;

float weighted_mean(float nums[],float weights[], int num_of_arr);

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int num_of_arr = 0;
    cin >> num_of_arr;
    float numbers[num_of_arr];
    float weights[num_of_arr];
    for(int i = 0; i < num_of_arr; i++)
    {
        cin >> numbers[i];
    }
    for(int i = 0; i < num_of_arr; i++)
    {
        cin >> weights[i];
    }
    cout << fixed << setprecision(1) << weighted_mean(numbers,weights,num_of_arr);
    return 0;
}

float weighted_mean(float nums[],float weights[], int num_of_arr)
{
    float sum_num = 0;
    float sum_den = 0;
    for(int i = 0;i < num_of_arr; i++)
    {
        sum_num += nums[i]*weights[i];
        sum_den += weights[i];
    }
    return sum_num/sum_den;
}
