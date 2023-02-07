
#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>

#define SEARCH_LIMIT 20000


int main()
{
    // initialization 
    std::vector<int> primes;

    for (int n = 3; n < SEARCH_LIMIT; n++)
    {
        bool is_prime = true;
        if (!( n % 2))
        {
            is_prime = false;
            continue;
        }
        else
        {
            for (int i = 0; i < primes.size(); i++)
            {
                if (! (n % primes[i]))
                {
                    is_prime = false;
                    break;
                }
            }
        }

        if (is_prime)
        {
            primes.push_back(n);
        }
    }

    std::ofstream myfile;
    myfile.open("primes.txt");
    
    // Manually print 1 and 2, then everything after
    //printf("1\n");
    //printf("2\n");
    myfile << "1\n" << "2\n";
    for (int prime : primes)
    {
        myfile << prime << std::endl;
        //printf("%i \n", prime);
    }
    std::cout << "All primes found in the search range\n";
}
