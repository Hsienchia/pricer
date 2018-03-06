#ifndef PAYOFF_H
#define PAYOFF_H

class payoff
{
public:
  payoff(){};
  virtual double operator()(double _spot) const = 0;
  virtual ~payoff(){};
  virtual payoff* clone() const =0;

private:
};

class payoffCall : public payoff
{
public:
  payoffCall(double _strike);
  virtual double operator()(double _spot) const;
  virtual ~payoffCall(){};
  virtual payoff* clone() const;

private:
  double strike;
};

class payoffPut : public payoff
{
public:
  payoffPut(double _strike);
  virtual double operator()(double _spot) const;
  virtual ~payoffPut(){};
  virtual payoff* clone() const;

private:
  double strike;
};

class payoffDoubleDigital : public payoff
{
public:
  payoffDoubleDigital(double _lower, double _upper);
  virtual double operator()(double _spot) const;
  virtual ~payoffDoubleDigital(){};
  virtual payoff* clone() const;

private:
  double lower;
  double upper;
};

#endif