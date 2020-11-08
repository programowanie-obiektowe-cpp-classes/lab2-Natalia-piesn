#include <iostream>
using namespace std;

class Wektor
{
public:
    Wektor() { wektor = new double[0]; }
    Wektor(int num_elements) : num_el{num_elements}, length{num_elements}, capacity{num_elements}
    {
        wektor = new double[num_el];
        for (int i = 0; i < num_el; i++) {
            *(wektor + i) = 0.0;
        }
    }
    ~Wektor() { delete[] wektor; }

    void print()
    {
        for (int i = 0; i < capacity; i++) {
            cout << *(wektor + i) << "\n";
        }
    }

    void changeLength(int new_length)
    {
        if (new_length <= capacity) {
            length = new_length;
            for (int i = length; i < capacity; i++) {
                *(wektor + i) = 0.0;
            }
        }
        else {
            double* wektor_new = new double[new_length];
            wektor_new         = wektor;
            delete[] wektor;
            for (int i = capacity; i < new_length; i++) {
                *(wektor_new + i) = 0.0;
            }
            capacity = new_length;
            length   = new_length;
        }
    }

    double* wektor;
    // double* wektor_new;
    int num_el;
    int get_length() { return length; }
    int get_capacity() { return capacity; }

private:
    int length;
    int capacity;
};

int main()
{
    Wektor A(10);
    for (int i = 0; i < A.get_length(); i++) {
        A.wektor[i] = i;
    }
    A.print();
    cout << A.get_length() << " " << A.get_capacity() << endl;

    A.changeLength(5);
    A.print();
    cout << A.get_length() << " " << A.get_capacity() << endl;

    A.changeLength(20);
    A.print();
    cout << A.get_length() << " " << A.get_capacity() << endl;
    A.changeLength(12);
    A.print();
    cout << A.get_length() << " " << A.get_capacity() << endl;
}
