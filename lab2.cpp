#include <iostream>
using namespace std;

class Wektor
{
public:
    Wektor(int num_elements) : length{num_elements}, capacity{num_elements}, num_el{num_elements}
    {
        wektor = new double[num_el];
        for (int i = 0; i < num_el; i++) {
            *(wektor + i) = 0.0;
        }
    }
    Wektor(const Wektor& A) : length{A.length}, capacity{A.length}, num_el{A.length}, wektor{}
    {
        wektor = new double[num_el];
        for (int i = 0; i < num_el; i++) {
            wektor[i] = A.wektor[i];
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
        for (int i = 0; i < length; i++) {
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
                //  cout << *(wektor + i) << " ";
                //  cout << *(wektor_new + i) << " ";
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

    int     get_length() { return length; }
    int     get_capacity() { return capacity; }
    double& operator[](int index)
    {
        if (index > length) {
            change_length(index);
        }
        return wektor[index];
    }

private:
    //  double* wektor;
    int     length;
    int     capacity;
    int     num_el;
    double* wektor;
};

int main()
{
    Wektor A{5};
    A.set_wektor();
    A.print();
    /*
    cout << A.get_length() << " " << A.get_capacity() << endl;
    A.change_length(2);
    A[0] = 41.;
    A.print();
    double a = A[10];
    cout << a << " ";
    a++;
    cout << A[0] << " " << a << endl;
    A.print();*/
    Wektor B{A};
    B.print();
}
