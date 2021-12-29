//
//  main.cpp
//  Bezier
//
//  Created by Ramón Daniel Regueiro Espiño on 18/12/21.
//

#include <iostream>
#include "R2.h"
#include "Casteljau.h"

int main() {
    std::cout<<"Preuve de R2: "<<std::endl;
    R2 v(5.3,2.1);
    R2 w=(3.1);
    std::cout<<v+w<<std::endl;
    std::cout<<2*v<<std::endl;

    Casteljau proba(3);
    proba[0]=R2(1,0);
    proba[1]=R2(0,1);
    proba[2]=R2(1,2);
    std::cout<<"Preuve du algorithme de Casteljau: "<<std::endl;
    w=pointcourbe(proba,0.7);

    std::cout<<w<<std::endl;
    return 0;
}
