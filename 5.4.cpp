#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
class Complex
{
public:
    float re, im;
    float mod;

public:
    Complex() {}
    Complex(float re, float im) : re(re), im(im)
    {
    }
    void afisare()
    {
        std::cout << this->re << " " << this->im << "\n";
    }
    void calcul()
    {
        this->mod = 0;
        this->mod = this->re * this->re + this->im * this->im;
        this->mod = sqrt(this->mod);
    }
};
bool mod(const Complex &c1, const Complex &c2)
{
    return (c1.mod < c2.mod);
}

int main()
{
    int t, n;
    float re, im;
    std::cin >> t;
    std::vector<Complex> numere;
    for (int i = 0; i < t; i++)
    {
        std::cin >> re;
        std::cin >> im;
        numere.push_back(Complex(re, im));
        numere[i].calcul();
    }
    std::sort(numere.begin(), numere.end(), mod);
    for (int i = 0; i < t; i++)
        numere[i].afisare();

    return 0;
}
