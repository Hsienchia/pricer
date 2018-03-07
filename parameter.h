#ifndef PARAMETER_H_
#define PARAMETER_H_

class parameterInner
{
public:
  parameterInner() {}
  virtual parameterInner *clone() const = 0;
  virtual double integral(double init, double fin) const = 0;
  virtual double integralSqr(double init, double fin) const = 0;
  virtual ~parameterInner() {}
};

class parameter
{
public:
  parameter(const parameterInner &inner);
  parameter(const parameter &origin);
  parameter &operator=(const parameter &origin);
  virtual ~parameter();

  inline double integral(double init, double fin) const;
  inline double integralSqr(double init, double fin) const;

  double mean(double init, double fin) const;
  double rms(double init, double fin) const;

private:
  parameterInner *para;
};

inline double parameter::integral(double init, double fin) const
{
  return para->integral(init, fin);
}

inline double parameter::integralSqr(double init, double fin) const
{
  return para->integralSqr(init, fin);
}

class constantPara : public parameterInner
{
public:
  constantPara(double _constant);

  virtual parameterInner *clone() const;
  virtual double integral(double init, double fin) const;
  virtual double integralSqr(double init, double fin) const;

private:
  double constant;
  double constantSqr;
};

#endif