/*!
 *\file Bitmap.h
 *\author{REGUEIRO ESPIÑO, Ramón Daniel et TRIDON, Bastien}
 *
 */

#ifndef Bitmap_h
#define Bitmap_h
#include <ostream>

class Bitmap{
protected:
    int width_;
    int heigth_;
    int **table_;
public:
    Bitmap(const int width,const int heigth);
    ~Bitmap();
    int get_width() const {return width_;}
    int get_heigth() const {return heigth_;}
    //int& operator[](int i,int j){return table_[i[j]];}
   // int operator[](int i,int j)const {return table_[i[j]];}
    void printBitmap();
    
    int get_p(const int i,const int j) const {return table_[i][j];}
    void set_p(const int i, const int j, const int l=1){table_[i][j]=l;}
};

Bitmap::Bitmap(const int width,const int heigth){
    if (width<=0 || heigth <=0){
        throw "Bad size of the Bitmap";
    }
    width_=width;
    heigth_=heigth;
    table_=new int*[width];
    for (int i=0;i<width;i++){
        table_[i]=new int[heigth];
        for (int j=0;j<heigth;j++){
            table_[i][j]=0;
        }
    }
}
Bitmap::~Bitmap(){
    delete[] table_;
}

void Bitmap::printBitmap(){
    for (int i=0;i<get_width();i++){
        std::cout<<"[";
        for (int j=0;j<get_heigth();j++){
            std::cout<<table_[i][j]<<" ";
        }
        std::cout<<"]"<<std::endl;
    }
}

#endif /* Bitmap_h */
