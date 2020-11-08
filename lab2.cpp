#include <iostream>
using namespace std;

class Wektor
{
public:
    Wektor() { wektor = new double[0]; }
    Wektor(int num_elements) : num_el{num_elements}, dlugosc{num_elements}, pojemnosc{num_elements}
    {
        wektor = new double[num_el];
        for (int i = 0; i < num_el; i++) {
            *(wektor + i) = 0.0;
        }
    }
    ~Wektor() { delete[] wektor; }

    void print()
    {
        for (int i = 0; i < dlugosc; i++) {
            cout << wektor[i] << "\n";
        }
    }

    double* wektor;
    int     num_el;
    int     get_dlugosc() { return dlugosc; }
    int     get_pojemnosc() { return pojemnosc; }

private:
    int dlugosc;
    int pojemnosc;
};

int main()
{
    Wektor A(10);
    A.print();
    cout << A.get_dlugosc() << " " << A.get_pojemnosc() << endl;
}
