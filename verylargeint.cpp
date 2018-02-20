#include "verylargeint.h"

#include <iostream>

veryLargeInt::veryLargeInt()
{
    number.push_back(0);
    sign = 0;
}

veryLargeInt::veryLargeInt(int number_int)
{
    unsigned int a;
    sign = 0;
    if (number_int < 0)
        sign = 1;
    number_int = abs(number_int);
    a = number_int % 10;
    while (number_int > 0)
    {
        number.insert(number.end(),a);
        number_int = number_int / 10;
        a = number_int % 10;
    }
}

veryLargeInt::veryLargeInt(string str)
{
    string c;
    unsigned int a;
    sign = 0;
    for (short int i = str.size() - 1; i >= 0 ; i--)
    {
        c = str[i];
        if (i == 0 && c == "-")
            sign = 1;
        else
        {
            a = atoi(c.c_str());
            if (a != 0 || c == "0")
                number.insert(number.end(), a);
            else
            {
                number.clear();
                number.insert(number.end(), 0);
                break;
            }
        }
    }
}

void veryLargeInt::output()
{
    if (sign == 1)
        cout << "-";
    for (int i = (int) number.size() - 1; i >= 0; i--)
    {
        cout << number.at(i);
    }
}

vector<int> veryLargeInt::getNumber( bool *get_sign)
{
    *get_sign = sign;
    return number;
}

veryLargeInt operator += (veryLargeInt &a, veryLargeInt &b)
{
    short int length;
    if (a.sign == b.sign)
    {
        // определяем длину массива суммы
        if (a.number.size() > b.number.size())
        {
            length = a.number.size() + 1;
            a.number.insert(a.number.end(),0);
            for (int i = b.number.size(); i < length; i++ )
                b.number.push_back(0);
        }
        else
        {
            length = b.number.size() + 1;
            for (int i = a.number.size(); i < length; i++ )
                a.number.push_back(0);
        }

        for (int i = 0; i < length - 1; i++)
        {
            a.number.at(i) += b.number.at(i);
            a.number.at(i + 1) += (a.number.at(i) / 10);
            a.number.at(i) %= 10;
        }

        if (a.number.at(length - 1) == 0)
            a.number.erase(a.number.end()-1);
    }
    else
    {
        if (a.sign == 1)
        {
            a.sign = 0;
            a -= b;
            a.sign = !a.sign;
        }
        else
        {
            b.sign = 0;
            a -= b;
        }
    }
    return a;
}

veryLargeInt operator += (veryLargeInt &a, int &b)
{
    veryLargeInt *c=new veryLargeInt(b);
    a += *c;
}

short int veryLargeInt::comparison(vector<int> b)
{
    short int length, flag_l = 3; // если к == 3, значит числа одинаковой длинны
    length = number.size();
    if (number.size() > b.size())
    {
        length = number.size();
        flag_l = 1; // если к == 1, значит первое число длиннее второго
    }
    else if (b.size() > number.size())
    {
        length = b.size();
        flag_l = 2; // если к == 2, значит второе число длиннее первого
    }
    else // если числа одинаковой длинны, то необходимо сравнить их веса
        for (int i = 0; i < length;)
        {
            if (number[i] > b[i])
            {
                flag_l = 1;
                break;
            }

            if(b[i] > number[i])
            {
                flag_l = 2;
                break;
            }
        }
    return flag_l;
}

void diff(vector<int> *number1, vector<int> *number2)
{
    int length = number1->size();
    for (int i = number2->size(); i < length ; i++ )
        number2->push_back(0);
    for (int i = 0; i < length ; i++)
    {
        if (i < (length - 1))
        {
            number1->at(i + 1)--;
            number1->at(i)+=10;
        }
        number1->at(i) -= number2->at(i);

        if (number1->at(i) / 10 > 0)
        {
            number1->at(i + 1)++;
            number1->at(i) %= 10;
        }
    }
    if (number1->at(length - 1) == 0)
        number1->erase(number1->end()-1);
}

veryLargeInt operator -= (veryLargeInt &a, veryLargeInt &b)
{
    if (a.sign == b.sign)
    {
        short int flag_l = a.comparison(b.number);
        if (flag_l == 1)
            diff(&a.number, &b.number);
        else
        {
            diff(&b.number, &a.number);
            a.number = b.number;
            if (a.sign == 0)
                a.sign = 1;
            else
                a.sign = 0;
        }
    }
    else
    {
        if (a.sign == 1)
        {
            b.sign = 1;
            a += b;
        }
        else
        {
            b.sign = 0;
            a += b;
        }
    }
    return a;
}

veryLargeInt operator -= (veryLargeInt &a, int &b)
{
    veryLargeInt *c=new veryLargeInt(b);
    a -= *c;
}

//veryLargeInt operator *= (veryLargeInt &a, veryLargeInt &b)
//{
//    vector<int> c;
//    long int length = a.number.size() + b.number.size() + 1;
//    for (int i = 0; i < length; i++)
//        c.insert(c.end(),0);

//    for (int i = 0; i < a.number.size(); i++)
//        for (int j = 0; j < b.number.size(); j++)
//            c.at(i + j ) += a.number.at(i) * b.number.at(j);

//    for (int i = 0; i < length - 1; i++)
//    {
//        c.at(i + 1) += c.at(i) / 10;
//        c.at(i) %= 10;
//    }

//    while (c.at(length - 1) == 0)
//    {
//        c.erase(c.end() - 1);
//        length--;
//    }
//    a.number = c;

//    if (a.sign == b.sign)
//        a.sign = 0;
//    else
//        a.sign = 1;
//    return a;
//}

//veryLargeInt operator *= (veryLargeInt &a, int &b)
//{
//    veryLargeInt *c=new veryLargeInt(b);
//    a *= *c;
//    return a;
//}


veryLargeInt veryLargeInt::operator *= (veryLargeInt &b)
{
    vector<int> c, number2;
    bool b_sign = 0;
    number2 = b.getNumber(&b_sign);
    long int length = number.size() + number2.size() + 1;
    for (int i = 0; i < length; i++)
        c.insert(c.end(),0);

    for (int i = 0; i < number.size(); i++)
        for (int j = 0; j < number2.size(); j++)
            c.at(i + j ) += number.at(i) * number2.at(j);

    for (int i = 0; i < length - 1; i++)
    {
        c.at(i + 1) += c.at(i) / 10;
        c.at(i) %= 10;
    }

    while (c.at(length - 1) == 0)
    {
        c.erase(c.end() - 1);
        length--;
    }
    number = c;

    if (sign == b_sign)
        sign = 0;
    else
        sign = 1;
    return *this;
}

veryLargeInt veryLargeInt::operator *= (int &b)
{
    veryLargeInt *c=new veryLargeInt(b);
    *this *= *c;
    return *this;
}
