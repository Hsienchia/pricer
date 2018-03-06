#include "simpleMC.h"
#include <iostream>
using namespace std;

int main()
{
    double e, s, p, v, r;

    cout << "Enter expiry:\n";
    cin >> e;
    cout << "\nEnter strike:\n";
    cin >> s;
    cout << "\nEnter spot:\n";
    cin >> p;
    cout << "\nEnter volatility:\n";
    cin >> v;
    cout << "\nEnter rate of return:\n";
    cin >> r;

    payoffCall vanillaCall(s);
    payoffPut vanillaPut(s);
    VanillaOption call(vanillaCall, e);
    VanillaOption put(vanillaPut, e);

    cout << "The prices are " << simpleMC(call, p, v, r) << " for the call and " << simpleMC(put, p, v, r) << " for the put." << endl;
    return 0;
}