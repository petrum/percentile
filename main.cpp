#include <iostream>
#include <vector>
#include <cassert>

#define LOG std::cerr << __FUNCTION__ << std::endl

int main(int argc, char* argv[])
{
    assert(argc == 2);
    double percentile = std::stod(argv[1]);
    std::cerr << "Percentile = " << percentile << "%\n";
    double n;
    while (std::cin >> n)
    {
        std::cout << n << std::endl;
    }
    return 0;
}
