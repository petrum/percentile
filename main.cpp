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
    top.push(d);
    double total = top.size() + bottom.size();
    double ratio = bottom.size() / total;
    if (ratio < percentile)
    {
        //std::cerr << "before correction ratio = " << ratio << std::endl;
        double downgraded = top.top();
        top.pop();
        bottom.push(downgraded);
    }
    ratio = bottom.size() / total;
    //std::cerr << "bottom.size = " << bottom.size() << ", top.size = " << top.size() << ", bottom.top = " << 
    //    bottom.top() << ", top.bottom = " << top.top() << ", ratio = " << ratio << ", get = " << get() << "\n";
}

double Percentile::get() const
{
    return top.size() ? top.top() : std::numeric_limits<double>::quiet_NaN();
}

int main(int argc, char* argv[])
{
    assert(argc == 2);
    double d = std::stod(argv[1]);
    //std::cerr << "- percentile = " << d << "%\n";
    Percentile p(d / 100);
    std::size_t i = 0;
    double n;
    while (std::cin >> n)
    {
        ++i;
        //std::cout << "in " << n << std::endl;
        p.add(n);
        std::cout << p.get() << std::endl;
        if (i % 1000 == 0)
            std::cerr << i << "\n";
    }
    return 0;
}
