/*
 * Question: Find if a number is a perfect square
 *
 * Solution1: Simplest solution is based on the fact that a perfect square is sum of 
 * consecutive odd numbers.
 * 4 = 1 + 3
 * 9 = 1 + 3 + 5
 * 16= 1 + 3 + 5 + 7
 */

bool isPerfectSquare(long long n)
{
    long long  i=1;
    long long sum =0;
    while(sum < n)
    {
        sum+=i;
        i+=2;
    }

    if (sum == n)
        return true;

    return false;
}
#include <iostream>

using namespace std;

int main()
{
    cout<<isPerfectSquare(125)<<endl;
    cout<<isPerfectSquare(625)<<endl;
    cout<<isPerfectSquare(7225)<<endl;
}
