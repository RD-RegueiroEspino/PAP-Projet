/*!
 *\file R2.h
 *\author{REGUEIRO ESPIÑO, Ramón Daniel et TRIDON, Bastien}
 */
#ifndef R2_h
#define R2_h
#include <ostream>
/*!
 * \class {R2}
 * \brief {Classe représentant R^2 et contenant les opérations qu'on a besoin pour la manipuler}
 */
class R2{
protected:
    double y1_;
    double y2_;
public:
    R2(double y1=0, double y2=0);
    ~R2(){}
    R2(const R2& v);
    
    double get_y1() const {return y1_;}
    double get_y2() const {return y2_;}
    void set_y1(const double y1){y1_=y1;}
    void set_y2(const double y2){y2_=y2;}
    
    /*!
     * \brief {Arrondir aux nombres entiers pour connaître la possition avec des pixels.}
     */
    R2 & roundR();
    friend std::ostream & operator<<(std::ostream & st, const R2& v);
};

R2 operator*(const double l,const R2& v);
R2 operator+(const R2& l,const R2& v);
R2 operator-(const R2& l,const R2& v);
#endif /* R2_h */
