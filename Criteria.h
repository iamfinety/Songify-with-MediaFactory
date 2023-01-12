#ifndef CRITERIA_H
#define CRITERIA_H

#include <iostream>
#include <string>
#include "Song.h"                                                                                                                   

using namespace std;
class Criteria{
    friend ostream& operator<<(ostream&, Criteria&);
    public:
        virtual bool matches(const Song&)=0;
        virtual void print(ostream&) const = 0;
};
class A_Criteria :  virtual public Criteria{
    public:
        A_Criteria(const string& artist);
        virtual bool matches(const Song& song);
        virtual void print(ostream&) const;
    private:
        string artist;
};
class C_Criteria : virtual public Criteria{
    public:
        C_Criteria(const string& category);
        virtual bool matches(const Song& song);
        virtual void print(ostream&) const;
    private:
        string category;
};
class AorC_Criteria : public A_Criteria, public C_Criteria{
    public:
        AorC_Criteria(const string& artist, const string& category);
        virtual bool matches(const Song& song);
        virtual void print(ostream&) const;
};
#endif