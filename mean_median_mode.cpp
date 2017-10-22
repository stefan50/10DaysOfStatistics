//Programme that calculates mean, median, mode

#include <iostream>
using namespace std;

struct num_in_arr
{
    int quantity = 0;
    float number;
};

float mean(float arr[],int num);
float median(float arr[],int num);
float mode(float arr[],int num);

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int num_of_arr = 0;
    cin >> num_of_arr;
    float nums[num_of_arr];
    for(int i = 0; i < num_of_arr; i++)
    {
        cin >> nums[i];
    }
    sort(nums,nums+num_of_arr);
    for(int i = 0; i < num_of_arr; i++)
    {
        //cout << nums[i] << endl;
    }
    cout << mean(nums,num_of_arr) << endl << median(nums,num_of_arr) << endl << mode(nums,num_of_arr);
    return 0;
}

float mean(float arr[],int num)
{
    float mean_num; 
    for(int i = 0; i < num; i++)
    {
        mean_num += arr[i];
    }
    mean_num /= num;
    return mean_num;
}
float median(float arr[],int num)
{
    float to_return = 0;
    if(num % 2 != 0)
    {
        num /= 2;
        to_return = arr[num];
    }
    else
    {
        num /= 2;
        to_return = (arr[num] + arr[num-1])/2;
    }
    return to_return;
}
float mode(float arr[],int num)
{
    float answer;
    num_in_arr arr_num;
    int num_found = 0;
    for(int i = 0; i < num; i++)
    {
        num_found = 0;
        answer = arr[i];
        for(int j = i; j < num; j++)
        {
            if(arr[j] == answer)
            {
                num_found++;
            }
        }
        if(arr_num.quantity < num_found)
        {
            arr_num.quantity = num_found;
            arr_num.number = answer;
        }
    }   
    return arr_num.number;
}
