/*
    Multiples of 3 and 5:
    https://projecteuler.net/problem=1

    If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
    Find the sum of all the multiples of 3 or 5 below 1000.
*/
#include <iostream>
#include <numeric>
#include <vector>

constexpr bool is_multiple(size_t mult, size_t value)
{
    return (mult % value) == 0;
}

constexpr bool is_multiple(const std::vector<size_t> &multiplicators, size_t value)
{
    for (const size_t &multiplicator : multiplicators)
    {
        if (is_multiple(value, multiplicator))
        {
            return true;
        }
    }
    return false;
}

std::vector<size_t> get_multiples(std::vector<size_t> &multiplicators, size_t from, size_t to)
{
    std::vector<size_t> result;
    for (size_t i = from; i < to; i++)
    {
        if (is_multiple(multiplicators, i))
        {
            result.push_back(i);
        }
    }
    return result;
}

int main(int argc, char **argv)
{
    std::vector<size_t> multiplicators = {3, 5};
    auto numbers_multiples = get_multiples(multiplicators, 0, 1000);
    size_t result = std::accumulate(numbers_multiples.begin(), numbers_multiples.end(),
                                    decltype(numbers_multiples)::value_type(0));
    std::cout << "result: " << result << std::endl;

    if (result != 233168)
    {
        std::cout << "error: result must be equal to 233168 [!]" << std::endl;
        return -1;
    }

    return 0;
};
