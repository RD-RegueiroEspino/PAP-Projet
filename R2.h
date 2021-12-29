//
//  R2.h
//  Bezier
//
//  Created by Ramón Daniel Regueiro Espiño on 18/12/21.
//

#ifndef R2_h
#define R2_h
#include <ostream>
class R2{
protected:
    double y1_;
    double y2_;
public:
    R2(double y1=0, double y2=0);
    ~R2();
    R2(const R2& v);
    
    double get_y1() const {return y1_;}
    double get_y2() const {return y2_;}
    void set_y1(const double y1){y1_=y1;}
    void set_y2(const double y2){y2_=y2;}
    
    friend std::ostream & operator<<(std::ostream & st, const R2& v);
};

R2::R2(double y1, double y2){
    y1_=y1;
    y2_=y2;
}
R2::~R2(){}
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
#endif /* R2_h */
