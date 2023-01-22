#include <iostream>
#include <cmath>

int main()
{
    int start = 1, finish;
    std::cin >> finish;
    int numRanks, armstrong, n, m, sum;
    for (armstrong = start; armstrong <= finish; armstrong++)
    {
        numRanks = 0;
        sum = 0;
        n = armstrong;
        while (n > 0)
        {
            n = n / 10;
            numRanks++;
        }
        n = armstrong;
        while (n > 0)
        {
            sum += powl(n % 10, numRanks);
            n /= 10;

        }
        if (sum == armstrong)
        {
            std::cout << sum << "\n";
        }

    }
}