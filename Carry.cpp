#include "Carry.h"
#include <iostream>

using namespace std;

int Carry::ct = 0;

Carry::Carry()
{
    ++ct;
    n = 0;
    pc = nullptr;
    cout << "default constructor called; number of objects: " << ct << endl;
    ShowObject();
}

Carry::Carry(int k) : n(k)
{
    ++ct;
    cout << "int constructor called; number of objects: " << ct << endl;
    pc = new char[n];
    ShowObject();
}

Carry::Carry(int k, char ch) : n(k)
{
    ++ct;
    cout << "int, char constructor was called; number of objects: " << ct << endl;
    pc = new char[n];
    for (int i = 0; i < n; i++)
        pc[i] = ch;
    ShowObject();
}

Carry::Carry(const Carry &f) : n(f.n)
{
    ++ct;
    cout << "copy const called; number of objects: " << ct << endl;
    pc = new char[n];
    for (int i = 0; i < n; i++)
        pc[i] = f.pc[i];
    ShowObject();
}

Carry::Carry(Carry &&f) :n(f.n)
{
    ++ct;
    cout << ("move constructor called; number of objects: ") << ct << endl;
    pc = f.pc;
    f.pc = nullptr;
    f.n = 0;
    ShowObject();
}

Carry::~Carry()
{
    cout << "destructor called; objects left: " << --ct << endl;
    cout << "deleted object:\n";
    ShowObject();
    delete[] pc;
}

Carry Carry::operator+(const Carry &f) const
{
    cout << "Entering operator+()\n";
    Carry temp = Carry(n + f.n);
    for (int i = 0; i < n; i++)
        temp.pc[i] = pc[i];
    for (int i = 0; i < temp.n; i++)
        temp.pc[i] = f.pc[i - n];
    cout << "temp object:\n";
    cout << "Leaving operator +()\n";
    return temp;
}

void Carry::ShowObject() const
{
    cout << "number of elements: " << n;
    cout << "Data address: " << (void*)pc << endl;
}

void Carry::ShowData() const
{
    if (n == 0)
        cout << "(object empty)";
    else
        for (int i = 0; i < n; i++)
            cout << pc[i];
    cout << endl;
}