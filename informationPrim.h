#ifndef NODOPRIM_H
#define NODOPRIM_H
#include<iostream>
using namespace std;

class InformationPrim
{
public:
    InformationPrim(string inicio,string fin, int peso);
    string nombreInicio;
    string nombreFin;
    int peso;
    bool operator ==(InformationPrim m) {
            if(nombreInicio==m.nombreInicio && nombreFin== m.nombreFin)
                return true;
            return false;
    }
};

#endif // NODOPRIM_H
