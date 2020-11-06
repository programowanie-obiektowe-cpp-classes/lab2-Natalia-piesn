#include <iostream>
using namespace std;

class Wektor
{
private:
    int dlugosc;

public:
    Wektor(int num_elements)
    {
        wektor  = new double[num_elements];
        dlugosc = num_elements;
    }
    ~Wektor() { delete[] wektor; }
    void print() { cout << wektor[4] << "\n"; }

    double* wektor;
    int     get_dlugosc() { return dlugosc; }
};

int main()
{
    Wektor A(5);
    A.print();
    cout << A.get_dlugosc() << endl;
}
