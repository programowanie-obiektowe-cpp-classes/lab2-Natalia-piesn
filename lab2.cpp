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

    void set_wektor()
    {
        for (int i = 0; i < capacity; i++) {
            *(wektor + i) = i;
        }
    }
    void print()
    {
        for (int i = 0; i < capacity; i++) {
            cout << *(wektor + i) << "\n";
        }
    }

    void change_length(int new_length)
    {
        if (new_length <= capacity) {
            length = new_length;
            for (int i = length; i < capacity; i++) {
                *(wektor + i) = 0.0;
            }
        }
        else {
            double* wektor_new = (double*)realloc(wektor, new_length * sizeof(double));
            for (int i = 0; i < length; i++) {
                *(wektor_new + i) = *(wektor + i);
            }
            for (int i = capacity; i < new_length; i++) {
                *(wektor_new + i) = 0.0;
            }
            capacity = new_length;
            length   = new_length;
            wektor   = wektor_new;
            delete[] wektor_new;
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
    Wektor A{15};
    A.set_wektor();
    A.print();
    cout << A.get_length() << " " << A.get_capacity() << endl;

    A.change_length(5);
    A.print();
    cout << A.get_length() << " " << A.get_capacity() << endl;

    A.change_length(20);
    A.print();
    cout << A.get_length() << " " << A.get_capacity() << endl;
    A.change_length(12);
    A.print();
    cout << A.get_length() << " " << A.get_capacity() << endl;
}
