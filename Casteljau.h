//
//  Casteljau.h
//  Bezier
//
//  Created by Ramón Daniel Regueiro Espiño on 20/12/21.
//

#ifndef Casteljau_h
#define Casteljau_h
#include "R2.h"

class Casteljau: public R2 {
private:
    double val1_;
    double val2_;
public:
    Casteljau(const double val1,const double val2);
    ~Casteljau(){}
    double pol();
};

double Casteljau::pol();
Casteljau::Casteljau(const double val1,const double val2){
    val1_=val1;
    val2_=val2;
}

#endif /* Casteljau_h */
