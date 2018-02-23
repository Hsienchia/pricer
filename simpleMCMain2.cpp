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

    payoff vanillaCall(s, payoff::call);
    payoff vanillaPut(s, payoff::put);

    cout << "The prices are " << simpleMC(vanillaCall, e, p, v, r) << " for the call and " << simpleMC(vanillaPut, e, p, v, r) << " for the put." << endl;
    return 0;
}