#include "simpleMC.h"
#include "parameter.h"
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
    constantPara vol(v);
    constantPara rate(r);
    VanillaOption call(vanillaCall, e);
    VanillaOption put(vanillaPut, e);

    cout << "The prices are " << simpleMC(call, p, vol, rate) << " for the call and " << simpleMC(put, p, vol, rate) << " for the put." << endl;
    return 0;
}