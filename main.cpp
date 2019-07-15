#include <iostream>
#include <vector>
#include <cassert>
#include <queue>
#include <limits>

struct Percentile
{
    Percentile(double d) : percentile(d) {}
    void add(double);
    double get() const { return top.size() ? top.top() : std::numeric_limits<double>::quiet_NaN(); }
    std::size_t size() const { return top.size() + bottom.size(); }
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
    // maintain the balance between top/bottom
    if (ratio < percentile)
    {
        double downgraded = top.top();
        top.pop();
        bottom.push(downgraded);
    }
    // maintain the order between top/bottom
    if (top.empty() || bottom.empty())
        return;
    double d1 = top.top(), d2 = bottom.top();
    if (d1 < d2)
    {
        top.pop();
        bottom.pop();
        top.push(d2);
        bottom.push(d1);
    }
}

int main(int argc, char* argv[])
{
    assert(argc == 2);
    double d = std::stod(argv[1]);
    Percentile p(d / 100);
    std::size_t i = 0;
    double n;
    while (std::cin >> n)
    {
        ++i;
        p.add(n);
        std::cout << p.get() << std::endl;
        if (i % 1000000 == 0)
            std::cerr << i << "\n";
    }
    std::cerr << "total size: " << p.size() << "\n";
    return 0;
}
