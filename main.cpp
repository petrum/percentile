#include <iostream>
#include <vector>
#include <cassert>
#include <queue>

#define LOG std::cerr << __FUNCTION__ << std::endl

struct Percentile
{
    Percentile(double d) : percentile(d) {}
    void add(double);
    double get() const;
private:
    double percentile;
    std::priority_queue <double, std::vector<double>, std::greater<double>> top; //min heap
    std::priority_queue <double> bottom; //max heap

};

void Percentile::add(double)
{

}

double Percentile::get() const
{
    return 0;
}

int main(int argc, char* argv[])
{
    assert(argc == 2);
    double d = std::stod(argv[1]);
    std::cerr << "- percentile = " << d << "%\n";
    Percentile p(d);
    double n;
    while (std::cin >> n)
    {
        p.add(n);
        std::cout << p.get() << std::endl;
    }
    return 0;
}
