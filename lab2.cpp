#include <iostream>
using namespace std;

/*
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

    Wektor(Wektor&& vec) : length(0), capacity(0), num_el(0), wektor(nullptr)
    {
        length   = vec.length;
        capacity = vec.capacity;
        num_el   = vec.num_el;
        wektor   = vec.wektor;

        vec.wektor   = nullptr;
        vec.length   = 0;
        vec.capacity = 0;
        vec.num_el   = 0;
    }

    ~Wektor() { delete[] wektor; }

    void set_wektor()
    {
        for (int i = 0; i < capacity; i++) {
            *(wektor + i) = capacity - i;
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

            double* wektor_new = new double[new_length];
            for (int i = 0; i < new_length; i++) {
                *(wektor_new + i) = 0.0;
            }
            for (int i = 0; i < length; i++) {
                *(wektor_new + i) = *(wektor + i);
            }
            delete[] wektor;
            wektor   = wektor_new;
            capacity = new_length;
            length   = new_length;
        }
    }

    double& operator[](int index)
    {
        if (index > length) {
            change_length(index);
        }
        return wektor[index];
    }

    Wektor& operator=(const Wektor& vec)
    {
        if (&vec == this)
            return *this;
        if (length != vec.length) {
            // cout << vec.wektor[vec.length - 1] << endl;
            change_length(vec.length);

            // cout << "done";
        }
        for (int i = 0; i < length; i++) {
            wektor[i] = *(vec.wektor + i);
        }
        return *this;
    }

    Wektor& operator=(Wektor&& vec)
    {
        if (&vec == this) {
            return *this;
        }

        delete wektor;
        wektor     = vec.wektor;
        vec.wektor = nullptr;
        return *this;
    }

    int get_length() { return length; }
    int get_capacity() { return capacity; }

private:
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

    cout << A.get_length() << " " << A.get_capacity() << endl;
    Wektor B{2};
    B.set_wektor();
    B.print();
    A = B;
    A.print();
    cout << A.get_length() << " " << A.get_capacity();
}
*/