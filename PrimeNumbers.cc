#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n)
{
    if (n<2)
        return false;

    //2 is a prime and any number divisible by 2 is not a prime`
    if (n!= 2 && (n&1)==0)
        return false;

    //skip all even numbers except 2 since if number is not divisible by 2 then it isnt divisible by any even number
    for(int i=3;i<=sqrt(n); i+=2)
    {   
        if (n%i == 0)
            return false;
    }

    //falls back here for n=2   
    return true;

}
//http://en.wikipedia.org/wiki/Sieve_of_eratosthenes
//An efficient way to generate all prime numbers upto a given limit
//
void generatePrime(int n, bool prime[])
{
    prime[0]= false;
    prime[1]= false;

    for (int i=2;i<=n; i++)
        prime[i]=true;

    for(int i=2; (i*i)<n;i ++)
    {
        if (prime[i])
        {
            //if i is prime, mark all multiples of i from 2 to n as not prime
            for(int j=i; (j*i)<=n; j++)
            {
                prime[j*i]=false;
            }
        }
    }
}

int main()
{
    cout <<isPrime(0)<<endl;
    cout <<isPrime(1)<<endl;
    cout <<isPrime(2)<<endl;
    cout <<isPrime(3)<<endl;
    cout <<isPrime(4)<<endl;
    cout <<isPrime(5)<<endl;

    bool prime[200];
    generatePrime(100, prime);
    for(int i=0;i<100;i++)
    {
        if (prime[i])
            cout <<i<<endl;
    }

}
