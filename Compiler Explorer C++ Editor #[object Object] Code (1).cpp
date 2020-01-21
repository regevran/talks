#include <vector>
#include <iostream>
#include <numeric>

int prevSum()
{
    return 7;
}

int main()
{
    std::vector v = {1,2,3,4,5,6,7,8,9,10};

    int sum = prevSum();
    for ( int i = 0; i < v.size(); ++ i )
    {
        sum += v[i];
    }

    std::cout << sum << "\n";

    int sum1 = std::accumulate( v.begin(), v.end(), prevSum() );

    std::cout << sum1 << "\n";
}