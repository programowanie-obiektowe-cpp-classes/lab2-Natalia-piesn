#include <iostream>
using namespace std;

class Wektor
{
public:
    Wektor(int num_elements) { double* wektor = new double[num_elements]; }
    ~Wektor() { delete[] wektor; }
    void    print() { cout << wektor[4]; }
    int     num_elements;
    double* wektor = new double[num_elements];
};
int main()
{
    Wektor A(5);
    A.print();
}
