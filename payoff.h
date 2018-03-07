#ifndef PAYOFF_H
#define PAYOFF_H

class payoffInner
{
public:
  payoffInner(){};
  virtual double operator()(double _spot) const = 0;
  virtual ~payoffInner(){};
  virtual payoffInner *clone() const = 0;
};

class payoff
{
public:
  payoff(const payoff &origin);
  payoff(const payoffInner &inner);

  inline double operator()(double spot) const;
  ~payoff();
  payoff &operator=(const payoff &origin);

private:
  payoffInner *thePayOff;
};

inline double payoff::operator()(double spot) const
{
  return (*thePayOff)(spot);
}

class payoffCall : public payoffInner
{
public:
  payoffCall(double _strike);
  virtual double operator()(double _spot) const;
  virtual ~payoffCall(){};
  virtual payoffInner *clone() const;

private:
  double strike;
};

class payoffPut : public payoffInner
{
public:
  payoffPut(double _strike);
  virtual double operator()(double _spot) const;
  virtual ~payoffPut(){};
  virtual payoffInner *clone() const;

private:
  double strike;
};

class payoffDoubleDigital : public payoffInner
{
public:
  payoffDoubleDigital(double _lower, double _upper);
  virtual double operator()(double _spot) const;
  virtual ~payoffDoubleDigital(){};
  virtual payoffInner *clone() const;

private:
  double lower;
  double upper;
};

#endif