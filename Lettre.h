/*!
 *\file Lettre.h
 *\author{REGUEIRO ESPIÑO, Ramón Daniel et TRIDON, Bastien}
 */
#ifndef Lettre_h
#define Lettre_h
//#include "Bitmap.h"
class Lettre{
private:
    Bitmap table;
    int n_;
public:
    Lettre(const int width=60,const int heigth=60);
    void set_n(const int n){n_=n;}
    int get_n(const int n){n_=n;}
};
Lettre::Lettre(const int width=60,const int heigth=60){
    Bitmap table(width,heigth);
}

#endif /* Lettre_h */
