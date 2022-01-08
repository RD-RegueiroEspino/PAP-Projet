/*!
 *\file Bitmap.h
 *\author{REGUEIRO ESPIÑO, Ramón Daniel et TRIDON, Bastien}
 */
#include "Bitmap.h"
#include <stdio.h>
void Bitmap::printBitmap(){
    for (int i=0;i<get_width();i++){
        std::cout<<"[";
        for (int j=0;j<get_heigth();j++){
            std::cout<<table_[i][j]<<" ";
        }
        std::cout<<"]"<<std::endl;
    }
}
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
Bitmap::Bitmap(const Bitmap & v){
    width_=v.get_width();
    heigth_=v.get_heigth();
    table_=new int*[width_];
    for (int i=0;i<width_;i++){
        table_[i]=new int[heigth_];
        for (int j=0;j<heigth_;j++){
            table_[i][j]=v.table_[i][j];
        }
    }
}
Bitmap & Bitmap::remplissage_point(const int auxx, const int auxy){
    for (int j=0;j<(int)get_width()/14;j++){
        for (int k=0;k<(int)get_heigth()/14;k++){
            (*this).set_p(auxx-j,auxy);
            (*this).set_p(auxx+j,auxy);
            (*this).set_p(auxx,auxy-k);
            (*this).set_p(auxx,auxy+k);
            (*this).set_p(auxx+j,auxy+k);
            (*this).set_p(auxx-j,auxy+k);
            (*this).set_p(auxx+j,auxy-k);
            (*this).set_p(auxx-j,auxy-k);
        }
    }
    return *this;
}
//Ce contour n'est pas bon
Bitmap & Bitmap::contour_noir(const int auxx, const int auxy){
    int j=(int)(get_width()/14)-1;
    int k=(int)(get_heigth()/14)-1;
    (*this).set_p(auxx,auxy);
    (*this).set_p(auxx,auxy-k);
    (*this).set_p(auxx+j,auxy);
    (*this).set_p(auxx-j,auxy);
    (*this).set_p(auxx-j,auxy+k);
    (*this).set_p(auxx-j,auxy-k);
    (*this).set_p(auxx+j,auxy+k);
    (*this).set_p(auxx+j,auxy-k);
    return *this;
}

/*!
 *On sait que les lettres ne van utiliser les coins du Bitmap. Donc, pour favoriser l'optimisation, on ne considerara ces points.
 *Sinon, il suffira de changer le code en vérifiant aussy l'hypothèse de que le point considérée est dans le Bitmap.
 */
Bitmap & Bitmap::contour_rouge(){
    for (int i=2;i<get_width()-2;i++){
        for (int j=2;j<get_heigth()-2;j++){
            if ((*this).get_p(i,j)==1){
                for (int k=1;k<3;k++){
                    if ((*this).get_p(i+k,j)==0){
                        (*this).set_p(i+k,j,2);
                    }
                    if ((*this).get_p(i,j+k)==0){
                        (*this).set_p(i,j+k,2);
                    }
                }
                for (int k=1;k<3;k++){
                    if ((*this).get_p(i-k,j)==0){
                        (*this).set_p(i-k,j,2);
                    }
                    if ((*this).get_p(i,j-k)==0){
                        (*this).set_p(i,j-k,2);
                    }
                }
            }
        }
    }
    return *this;
}

void coloration(Bitmap & table,Remplisage T){
    R2 aux;
    int auxx;
    int auxy;
    for (int i=0;i<T.get_size();i++){
        aux=T[i];
        auxx=int(table.get_width()*(aux.get_y1()));
        auxy=int(table.get_heigth()*(aux.get_y2()));
        table.remplissage_point(auxx,auxy);
    }
}
void printLettreA(Bitmap & table){
    int size=std::max(table.get_width(),table.get_heigth());
    Remplisage T(size);
    Casteljau A1(2);
    Casteljau A2(2);
    Casteljau A3(2);
    A1[0]=R2(0.15,0.5);
    A1[1]=R2(0.8,0.8);
    A2[0]=A1[0];
    A2[1]=R2(0.8,0.2);
    A3[0]=R2(0.5,0.65);
    A3[1]=R2(0.5,0.35);
    Calcul(A1,T);
    coloration(table,T);
    Calcul(A2,T);
    coloration(table,T);
    Calcul(A3,T);
    coloration(table,T);
    table.contour_rouge();
    table.printBitmap();
}
void printLettreB(Bitmap & table){
    int size=std::max(table.get_width(),table.get_heigth());
    Remplisage T(size);
    Casteljau B1(2);
    Casteljau B2(3);
    Casteljau B3(3);
    B1[0]=R2(0.15,0.25);
    B1[1]=R2(0.85,0.25);
    B2[0]=B1[0];
    B2[1]=R2(0.33,0.9);
    B2[2]=R2(0.5,0.25);
    B3[0]=B2[2];
    B3[1]=R2(0.67,0.9);
    B3[2]=R2(0.85,0.25);
    Calcul(B1,T);
    coloration(table,T);
    Calcul(B2,T);
    coloration(table,T);
    Calcul(B3,T);
    coloration(table,T);
    table.contour_rouge();
    table.printBitmap();}
void printLettreC(Bitmap & table){
    int size=std::max(table.get_width(),table.get_heigth());
    Remplisage T(size);
    Casteljau C1(3);
    C1[0]=R2(0.2,0.6);
    C1[1]=R2(0.5,0.1);
    C1[2]=R2(0.8,0.6);
    Calcul(C1,T);
    coloration(table,T);
    table.contour_rouge();
    table.printBitmap();
}
void printLettreD(Bitmap & table){
    int size=std::max(table.get_width(),table.get_heigth());
    Remplisage T(size);
    Casteljau D1(2);
    Casteljau D2(3);
    D1[0]=R2(0.15,0.35);
    D1[1]=R2(0.85,0.35);
    D2[0]=D1[0];
    D2[1]=R2(0.5,0.95);
    D2[2]=D1[1];
    Calcul(D1,T);
    coloration(table,T);
    Calcul(D2,T);
    coloration(table,T);
    table.contour_rouge();
    table.printBitmap();
}
void printLettreE(Bitmap & table){
    int size=std::max(table.get_width(),table.get_heigth());
    Remplisage T(size);
    Casteljau E1(2);
    Casteljau E2(2);
    Casteljau E3(2);
    Casteljau E4(2);
    E1[0]=R2(0.15,0.3);
    E1[1]=R2(0.85,0.3);
    E2[0]=E1[0];
    E2[1]=R2(0.15,0.7);
    E3[0]=E1[1];
    E3[1]=R2(0.85,0.7);
    E4[0]=R2(0.5,0.3);
    E4[1]=R2(0.5,0.5);
    Calcul(E1,T);
    coloration(table,T);
    Calcul(E2,T);
    coloration(table,T);
    Calcul(E3,T);
    coloration(table,T);
    Calcul(E4,T);
    coloration(table,T);
    table.contour_rouge();
    table.printBitmap();
}
void printLettreF(Bitmap & table){
    int size=std::max(table.get_width(),table.get_heigth());
    Remplisage T(size);
    Casteljau F1(2);
    Casteljau F2(2);
    Casteljau F3(2);
    F1[0]=R2(0.15,0.35);
    F1[1]=R2(0.85,0.35);
    F2[0]=F1[0];
    F2[1]=R2(0.15,0.8);
    F3[0]=R2(0.5,0.35);
    F3[1]=R2(0.5,0.6);
    Calcul(F1,T);
    coloration(table,T);
    Calcul(F2,T);
    coloration(table,T);
    Calcul(F3,T);
    coloration(table,T);
    table.contour_rouge();
    table.printBitmap();
}
void printLettreG(Bitmap & table){
    int size=std::max(table.get_width(),table.get_heigth());
    Remplisage T(size);
    Casteljau G1(3);
    Casteljau G2(2);
    Casteljau G3(2);
    G1[0]=R2(0.15,0.7);
    G1[1]=R2(0.5,-0.3);
    G1[2]=R2(0.85,0.7);
    G2[0]=G1[2];
    G2[1]=R2(0.5,0.7);
    G3[0]=G2[1];
    G3[1]=R2(0.5,0.55);
    Calcul(G1,T);
    coloration(table,T);
    Calcul(G2,T);
    coloration(table,T);
    Calcul(G3,T);
    coloration(table,T);
    table.contour_rouge();
    table.printBitmap();
}
void printLettreH(Bitmap & table){
    int size=std::max(table.get_width(),table.get_heigth());
    Remplisage T(size);
    Casteljau H1(2);
    Casteljau H2(2);
    Casteljau H3(2);
    H1[0]=R2(0.15,0.3);
    H1[1]=R2(0.85,0.3);
    H2[0]=R2(0.15,0.7);
    H2[1]=R2(0.85,0.7);
    H3[0]=R2(0.5,0.3);
    H3[1]=R2(0.5,0.7);
    Calcul(H1,T);
    coloration(table,T);
    Calcul(H2,T);
    coloration(table,T);
    Calcul(H3,T);
    coloration(table,T);
    table.contour_rouge();
    table.printBitmap();
}
void printLettreI(Bitmap & table){
    int size=std::max(table.get_width(),table.get_heigth());
    Remplisage T(size);
    Casteljau I1(2);
    Casteljau I2(2);
    Casteljau I3(2);
    I1[0]=R2(0.15,0.3);
    I1[1]=R2(0.15,0.7);
    I2[0]=R2(0.15,0.5);
    I2[1]=R2(0.85,0.5);
    I3[0]=R2(0.85,0.3);
    I3[1]=R2(0.85,0.7);
    Calcul(I1,T);
    coloration(table,T);
    Calcul(I2,T);
    coloration(table,T);
    Calcul(I3,T);
    coloration(table,T);
    table.contour_rouge();
    table.printBitmap();
}
void printLettreJ(Bitmap & table){
    int size=std::max(table.get_width(),table.get_heigth());
    Remplisage T(size);
    Casteljau J1(2);
    Casteljau J2(2);
    Casteljau J3(3);
    J1[0]=R2(0.15,0.3);
    J1[1]=R2(0.15,0.7);
    J2[0]=J1[1];
    J2[1]=R2(0.7,0.7);
    J3[0]=J2[1];
    J3[1]=R2(1.05,0.5);
    J3[2]=R2(0.7,0.3);
    Calcul(J1,T);
    coloration(table,T);
    Calcul(J2,T);
    coloration(table,T);
    Calcul(J3,T);
    coloration(table,T);
    table.contour_rouge();
    table.printBitmap();
}
void printLettreK(Bitmap & table){
    int size=std::max(table.get_width(),table.get_heigth());
    Remplisage T(size);
    Casteljau K1(2);
    Casteljau K2(2);
    Casteljau K3(2);
    K1[0]=R2(0.15,0.35);
    K1[1]=R2(0.85,0.35);
    K2[0]=R2(0.15,0.65);
    K2[1]=R2(0.5,0.35);
    K3[0]=K2[1];
    K3[1]=R2(0.85,0.65);
    Calcul(K1,T);
    coloration(table,T);
    Calcul(K2,T);
    coloration(table,T);
    Calcul(K3,T);
    coloration(table,T);
    table.contour_rouge();
    table.printBitmap();
}
void printLettreL(Bitmap & table){
    int size=std::max(table.get_width(),table.get_heigth());
    Remplisage T(size);
    Casteljau L1(2);
    Casteljau L2(2);
    L1[0]=R2(0.15,0.35);
    L1[1]=R2(0.85,0.35);
    L2[0]=L1[1];
    L2[1]=R2(0.85,0.65);
    Calcul(L1,T);
    coloration(table,T);
    Calcul(L2,T);
    coloration(table,T);
    table.contour_rouge();
    table.printBitmap();
}
void printLettreM(Bitmap & table){
    int size=std::max(table.get_width(),table.get_heigth());
    Remplisage T(size);
    Casteljau M1(2);
    Casteljau M2(2);
    Casteljau M3(2);
    Casteljau M4(2);
    M1[0]=R2(0.85,0.3);
    M1[1]=R2(0.15,0.3);
    M2[0]=M1[1];
    M2[1]=R2(0.5,0.5);
    M3[0]=M2[1];
    M3[1]=R2(0.15,0.7);
    M4[0]=M3[1];
    M4[1]=R2(0.85,0.7);
    Calcul(M1,T);
    coloration(table,T);
    Calcul(M2,T);
    coloration(table,T);
    Calcul(M3,T);
    coloration(table,T);
    Calcul(M4,T);
    coloration(table,T);
    table.contour_rouge();
    table.printBitmap();
}
void printLettreN(Bitmap & table){
    int size=std::max(table.get_width(),table.get_heigth());
    Remplisage T(size);
    Casteljau N1(2);
    Casteljau N2(2);
    Casteljau N3(2);
    N1[0]=R2(0.85,0.3);
    N1[1]=R2(0.15,0.3);
    N2[0]=N1[1];
    N2[1]=R2(0.85,0.7);
    N3[0]=N2[1];
    N3[1]=R2(0.15,0.7);
    Calcul(N1,T);
    coloration(table,T);
    Calcul(N2,T);
    coloration(table,T);
    Calcul(N3,T);
    coloration(table,T);
    table.contour_rouge();
    table.printBitmap();
}
void printLettreO(Bitmap & table){
    int size=std::max(table.get_width(),table.get_heigth());
    Remplisage T(size);
    Casteljau O1(3);
    Casteljau O2(3);
    Casteljau O3(3);
    Casteljau O4(3);
    O1[0]=R2(0.2,0.3);
    O1[1]=R2(0.5,0);
    O1[2]=R2(0.8,0.3);
    O2[0]=O1[2];
    O2[1]=R2(0.95,0.5);
    O2[2]=R2(0.8,0.7);
    O3[0]=O2[2];
    O3[1]=R2(0.5,1.0);
    O3[2]=R2(0.2,0.7);
    O4[0]=O3[2];
    O4[1]=R2(0.05,0.5);
    O4[2]=O1[0];
    Calcul(O1,T);
    coloration(table,T);
    Calcul(O2,T);
    coloration(table,T);
    Calcul(O3,T);
    coloration(table,T);
    Calcul(O4,T);
    coloration(table,T);
    table.contour_rouge();
    table.printBitmap();
}
void printLettreP(Bitmap & table){
    int size=std::max(table.get_width(),table.get_heigth());
    Remplisage T(size);
    Casteljau P1(2);
    Casteljau P2(3);
    P1[0]=R2(0.15,0.3);
    P1[1]=R2(0.85,0.3);
    P2[0]=P1[0];
    P2[1]=R2(0.67,1.05);
    P2[2]=R2(0.5,0.3);
    Calcul(P1,T);
    coloration(table,T);
    Calcul(P2,T);
    coloration(table,T);
    table.contour_rouge();
    table.printBitmap();
}
void printLettreQ(Bitmap & table){
    int size=std::max(table.get_width(),table.get_heigth());
    Remplisage T(size);
    Casteljau Q1(3);
    Casteljau Q2(3);
    Casteljau Q3(3);
    Casteljau Q4(3);
    Casteljau Q5(2);
    Q1[0]=R2(0.2,0.3);
    Q1[1]=R2(0.5,0);
    Q1[2]=R2(0.8,0.3);
    Q2[0]=Q1[2];
    Q2[1]=R2(0.95,0.5);
    Q2[2]=R2(0.8,0.7);
    Q3[0]=Q2[2];
    Q3[1]=R2(0.5,1.0);
    Q3[2]=R2(0.2,0.7);
    Q4[0]=Q3[2];
    Q4[1]=R2(0.05,0.5);
    Q4[2]=Q1[0];
    Q5[0]=R2(0.85,0.85);
    Q5[1]=R2(0.65,0.65);
    Calcul(Q1,T);
    coloration(table,T);
    Calcul(Q2,T);
    coloration(table,T);
    Calcul(Q3,T);
    coloration(table,T);
    Calcul(Q4,T);
    coloration(table,T);
    Calcul(Q5,T);
    coloration(table,T);
    table.contour_rouge();
    table.printBitmap();

}
void printLettreR(Bitmap & table){
    int size=std::max(table.get_width(),table.get_heigth());
    Remplisage T(size);
    Casteljau R1(2);
    Casteljau R_2(2);
    Casteljau R3(3);
    R1[0]=R2(0.15,0.3);
    R1[1]=R2(0.85,0.3);
    R_2[0]=R2(0.5,0.3);
    R_2[1]=R2(0.85,0.6);
    R3[0]=R1[0];
    R3[1]=R2(0.33,0.9);
    R3[2]=R_2[0];
    Calcul(R1,T);
    coloration(table,T);
    Calcul(R_2,T);
    coloration(table,T);
    Calcul(R3,T);
    coloration(table,T);
    table.contour_rouge();
    table.printBitmap();
}
void printLettreS(Bitmap & table){
    int size=std::max(table.get_width(),table.get_heigth());
    Remplisage T(size);
    Casteljau S1(3);
    Casteljau S2(3);
    Casteljau S3(2);
    S1[0]=R2(0.15,0.7);
    S1[1]=R2(0.3,0.05);
    S1[2]=R2(0.45,0.4);
    S2[0]=R2(0.55,0.6);
    S2[1]=R2(0.7,0.95);
    S2[2]=R2(0.85,0.3);
    S3[0]=S1[2];
    S3[1]=S2[0];
    Calcul(S1,T);
    coloration(table,T);
    Calcul(S2,T);
    coloration(table,T);
    Calcul(S3,T);
    coloration(table,T);
    table.contour_rouge();
    table.printBitmap();
}
void printLettreT(Bitmap & table){
    int size=std::max(table.get_width(),table.get_heigth());
    Remplisage T(size);
    Casteljau T1(2);
    Casteljau T2(2);
    T1[0]=R2(0.15,0.3);
    T1[1]=R2(0.15,0.7);
    T2[0]=R2(0.15,0.5);
    T2[1]=R2(0.85,0.5);
    Calcul(T1,T);
    coloration(table,T);
    Calcul(T2,T);
    coloration(table,T);
    table.contour_rouge();
    table.printBitmap();
}
void printLettreU(Bitmap & table){
    int size=std::max(table.get_width(),table.get_heigth());
    Remplisage T(size);
    Casteljau U1(3);
    Casteljau U2(2);
    Casteljau U3(2);
    U1[0]=R2(0.7,0.15);
    U1[1]=R2(0.9,0.5);
    U1[2]=R2(0.7,0.85);
    U2[0]=R2(0.15,0.15);
    U2[1]=U1[0];
    U3[0]=U1[2];
    U3[1]=R2(0.15,0.85);
    Calcul(U1,T);
    coloration(table,T);
    Calcul(U2,T);
    coloration(table,T);
    Calcul(U3,T);
    coloration(table,T);
    table.contour_rouge();
    table.printBitmap();
}
void printLettreV(Bitmap & table){
    int size=std::max(table.get_width(),table.get_heigth());
    Remplisage T(size);
    Casteljau V1(2);
    Casteljau V2(2);
    V1[0]=R2(0.15,0.25);
    V1[1]=R2(0.85,0.5);
    V2[0]=R2(0.15,0.75);
    V2[1]=V1[1];
    Calcul(V1,T);
    coloration(table,T);
    Calcul(V2,T);
    coloration(table,T);
    table.contour_rouge();
    table.printBitmap();
}
void printLettreW(Bitmap & table){
    int size=std::max(table.get_width(),table.get_heigth());
    Remplisage T(size);
    Casteljau W1(2);
    Casteljau W2(2);
    Casteljau W3(2);
    Casteljau W4(2);
    W1[0]=R2(0.15,0.15);
    W1[1]=R2(0.85,0.35);
    W2[0]=W1[1];
    W2[1]=R2(0.5,0.5);
    W3[0]=W2[1];
    W3[1]=R2(0.85,0.65);
    W4[0]=W3[1];
    W4[1]=R2(0.15,0.85);
    Calcul(W1,T);
    coloration(table,T);
    Calcul(W2,T);
    coloration(table,T);
    Calcul(W3,T);
    coloration(table,T);
    Calcul(W4,T);
    coloration(table,T);
    table.contour_rouge();
    table.printBitmap();
}
void printLettreX(Bitmap & table){
    int size=std::max(table.get_width(),table.get_heigth());
    Remplisage T(size);
    Casteljau X1(2);
    Casteljau X2(2);
    X1[0]=R2(0.15,0.25);
    X1[1]=R2(0.85,0.75);
    X2[0]=R2(0.85,0.25);
    X2[1]=R2(0.15,0.75);
    Calcul(X1,T);
    coloration(table,T);
    Calcul(X2,T);
    coloration(table,T);
    table.contour_rouge();
    table.printBitmap();
}
void printLettreY(Bitmap & table){
    int size=std::max(table.get_width(),table.get_heigth());
    Remplisage T(size);
    Casteljau Y1(2);
    Casteljau Y2(2);
    Casteljau Y3(2);
    Y1[0]=R2(0.15,0.25);
    Y1[1]=R2(0.5,0.5);
    Y2[0]=R2(0.15,0.75);
    Y2[1]=Y1[1];
    Y3[0]=Y1[1];
    Y3[1]=R2(0.85,0.5);
    Calcul(Y1,T);
    coloration(table,T);
    Calcul(Y2,T);
    coloration(table,T);
    Calcul(Y3,T);
    coloration(table,T);
    table.contour_rouge();
    table.printBitmap();
}
void printLettreZ(Bitmap & table){
    int size=std::max(table.get_width(),table.get_heigth());
    Remplisage T(size);
    Casteljau Z1(2);
    Casteljau Z2(2);
    Casteljau Z3(2);
    Z1[0]=R2(0.15,0.15);
    Z1[1]=R2(0.15,0.85);
    Z2[0]=R2(0.85,0.15);
    Z2[1]=R2(0.85,0.85);
    Z3[0]=Z1[1];
    Z3[1]=Z2[0];
    Calcul(Z1,T);
    coloration(table,T);
    Calcul(Z2,T);
    coloration(table,T);
    Calcul(Z3,T);
    coloration(table,T);
    table.contour_rouge();
    table.printBitmap();
}
void selection(Bitmap & table,int x){
    if ((x<=64) | (x>=91)){
        throw "Erreur, lettre non considérée";
    }
    if (x==65) printLettreA(table);
    if (x==66) printLettreB(table);
    if (x==67) printLettreC(table);
    if (x==68) printLettreD(table);
    if (x==69) printLettreE(table);
    if (x==70) printLettreF(table);
    if (x==71) printLettreG(table);
    if (x==72) printLettreH(table);
    if (x==73) printLettreI(table);
    if (x==74) printLettreJ(table);
    if (x==75) printLettreK(table);
    if (x==76) printLettreL(table);
    if (x==77) printLettreM(table);
    if (x==78) printLettreN(table);
    if (x==79) printLettreO(table);
    if (x==80) printLettreP(table);
    if (x==81) printLettreQ(table);
    if (x==82) printLettreR(table);
    if (x==83) printLettreS(table);
    if (x==84) printLettreT(table);
    if (x==85) printLettreU(table);
    if (x==86) printLettreV(table);
    if (x==87) printLettreW(table);
    if (x==88) printLettreX(table);
    if (x==89) printLettreY(table);
    if (x==90) printLettreZ(table);
}
