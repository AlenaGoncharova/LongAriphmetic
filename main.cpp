#include <iostream>

#include "verylargeint.h"

using namespace std;

int main()
{
    //cout << "Hello World!" << endl;
    //veryLargeInt veryLargeInt(456888888);
    veryLargeInt *a=new veryLargeInt("-1002");
    veryLargeInt *b=new veryLargeInt("3");
    a->output();
    cout <<" + ";
    b->output();
    cout <<" = ";
    *a += *b;
    a->output();
    cout << "\n";
    a->output();
    int c = -245669000;
    cout <<" * " << c;
    *a *= c;
    cout <<" = ";
    a->output();


//    vector<int> b;
//    b.insert(b.end(),5);
//    n->difference(b,0);
//    n->output();

    //veryLargeInt veryLargeInt("450189525");
    return 0;
}
