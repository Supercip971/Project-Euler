/*
    10001st prime:
    https://projecteuler.net/problem=7

    By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

    What is the 10 001st prime number?
*/
#include <iostream>
#include <numeric>
#include <vector>

bool is_prime(long number)
{
    if (number == 0 || number == 1 || number % 2 == 0)
    {
        return false;
    }

    for (long i = 2; i <= number / 2; i++)
    {
        if (number % i == 0)
        {
            return false;    
        }
    }
    return true;
}

long get_nth_prime(long value)
{
    long count = 1; // start to count with 1
    long from = 2;
    long current = 0;
    while (count < value)
    {
        if (is_prime(from))
        {
            current = from;
            count++;
        }
        
        if (from == 2)
        {
            from ++;
        }
        else
        {
            from += 2; // skip pair numbers
        }
    }
    return current;
}


int main(int argc, char **argv)
{

    long result = get_nth_prime(10001);

    if (result != 104743)
    {
        std::cout << "[FAIL] result: " << result << "should have been " << 104743 << std::endl;
        return -1;
    }

    std::cout << "result: " << result << std::endl;
    return 0;
}
