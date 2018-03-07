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

    VanillaOption call(payoffCall(s), e);

    constantPara vol(v);
    constantPara rate(r);

    statsMean gatherer;
    simpleMC(call, s, vol, rate, gatherer);
    vector<vector<double>> res = gatherer.getResSoFar();

    cout << endl
         << "For the call price, the results are " << endl;

    for (unsigned long i = 0; i < res.size(); ++i)
    {
        for (unsigned long j = 0; j < res[i].size(); ++j)
            cout << res[i][j] << " ";
        cout << endl;
    }

    return 0;
}