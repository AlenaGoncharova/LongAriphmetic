#ifndef VERYLARGEINT_H
#define VERYLARGEINT_H

#include <string>
#include <vector>

using namespace std;

class veryLargeInt
{
public:
    veryLargeInt();
    veryLargeInt(int number_int);
    veryLargeInt(string str);
    ~veryLargeInt(){}
    friend veryLargeInt operator += (veryLargeInt &a, veryLargeInt &b);
    friend veryLargeInt operator += (veryLargeInt &a, int &b);
    friend veryLargeInt operator -= (veryLargeInt &a, veryLargeInt &b);
    friend veryLargeInt operator -= (veryLargeInt &a, int &b);
    //friend veryLargeInt operator *= (veryLargeInt &a, veryLargeInt &b);
    veryLargeInt operator *= (veryLargeInt &b);
    //friend veryLargeInt operator *= (veryLargeInt &a, int &b);
    veryLargeInt operator *= (int &b);
    vector<int> getNumber( bool *get_sign);
    void output();
    short comparison(vector<int> b);
    void multiplication(vector<int> b);

private:
    vector<int> number;
    bool sign;
};

#endif // VERYLARGEINT_H
