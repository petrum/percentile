#include <iostream>
#include <vector>
#include <cassert>
#include <queue>
#include <limits>

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

void Percentile::add(double d)
{
    bottom.push(d);
    double total = top.size() + bottom.size();
    if (bottom.size() / total > percentile)
    {
        double upgraded = bottom.top();
        bottom.pop();
        top.push(upgraded);
    }
}

double Percentile::get() const
{
    return top.size() ? top.top() : std::numeric_limits<double>::quiet_NaN();
}

int main(int argc, char* argv[])
{
    assert(argc == 2);
    double d = std::stod(argv[1]);
    std::cerr << "- percentile = " << d << "%\n";
    Percentile p(d / 100);
    double n;
    while (std::cin >> n)
    {
        std::cout << "in " << n << std::endl;
        p.add(n);
        std::cout << "out " << p.get() << std::endl;
    }
    return 0;
}
