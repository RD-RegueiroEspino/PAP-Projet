//
//  Bitmap.h
//  Bezier
//
//  Created by Ramón Daniel Regueiro Espiño on 20/12/21.
//

#ifndef Bitmap_h
#define Bitmap_h

class Bitmap{
protected:
    int width_;
    int heigth_;
    int *table_;
public:
    Bitmap(const int width,const int heigth);
    ~Bitmap();
    void set_width(const int width);
    void set_heigth(const int heigth);
    int get_width(){return width;}
    int get_heigth(){return heigth;}
};

Bitmap::Bitmap(const int width,const int heigth){
    if (width<=0 || height <=0){
        throw "Bad size of the Bitmap";
    }
    width_=width;
    heigth_=heigth;
    table_= new int[width*height];
}
Bitmap::~Bitmap(){
    delete table_;
}
void Bitmap::set_width(const int width){
    width_=width;
}
void Bitmap::set_heigth(const int heigth){
    heigth_=heigth;
}

#endif /* Bitmap_h */
