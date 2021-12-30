/*!
 *\file R2.cpp
 *\author{REGUEIRO ESPIÑO, Ramón Daniel et TRIDON, Bastien}
 *
 */
#include <stdio.h>
#include "R2.h"

R2::R2(double y1, double y2){
    y1_=y1;
    y2_=y2;
}
R2::R2(const R2& v){
    y1_=v.get_y1();
    y2_=v.get_y2();
}
std::ostream & operator<<(std::ostream & st, const R2& v){
    st<<"(";
    st<<v.get_y1();
    st<<",";
    st<<v.get_y2();
    st<<")";
    return st;
}
R2 operator*(const double l,const R2& v){
    R2 w;
    w.set_y1(l*v.get_y1());
    w.set_y2(l*v.get_y2());
    return w;
}
R2 operator+(const R2& l,const R2& v){
    R2 w;
    w.set_y1(l.get_y1()+v.get_y1());
    w.set_y2(l.get_y2()+v.get_y2());
    return w;
}
