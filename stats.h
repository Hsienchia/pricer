#ifndef STATS_H_
#define STATS_H_

#include <vector>

class stats
{
    public:
    stats() {}

    virtual void dumpOne(double result)=0;
    virtual std::vector<std::vector<double>> getResSoFar() const=0;
    virtual stats* clone() const=0;
    virtual ~stats() {}
};

class statsMean : public stats
{
    public:
    statsMean();
    virtual void dumpOne(double result);
    virtual std::vector<std::vector<double>> getResSoFar() const;
    virtual stats* clone() const;
    
    private:
    double runningSum;
    unsigned long pathsDone;
};

#endif