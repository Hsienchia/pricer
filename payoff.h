#ifndef PAYOFF_H
#define PAYOFF_H

class payoff
{
  public:
    enum OptionType
    {
        call,
        put
    };
    payoff(double _strike, OptionType _type);
    double operator()(double spot) const;

  private:
    double strike;
    OptionType type;
};

#endif