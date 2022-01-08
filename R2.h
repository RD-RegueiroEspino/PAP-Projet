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
    double y1_; /*!< Premier élément*/
    double y2_;/*!< Deuxiéme élément*/
public:
    /*!
     *\fn R2(double y1=0, double y2=0);
     * \brief {Constructeur}
     * \param[in] y1 Premier élément
     * \param[in] y2 Deuxiéme élément
     */
    R2(double y1=0, double y2=0);
    /*!
     *\fn ~R2()
     * \brief {Destructeur}
     */
    ~R2(){}
    /*!
     *\fn R2(const R2& v);
     * \brief {Constructeur de copie}
     * \param[in] v Élément R2 à copier
     */
    R2(const R2& v);
    /*!
     *\fn double get_y1() const
     * \brief {Obtenir le valeur du premier élément}
     */
    double get_y1() const {return y1_;}
    /*!
     *\fn double get_y2() const
     * \brief {Obtenir le valeur du deuxiéme élément}
     */
    double get_y2() const {return y2_;}
    /*!
     *\fn void set_y1(const double y1)
     * \brief {Changer le valeur du premier élément}
     * \param[in] y1 Nouveau double pour le premier élément
     */
    void set_y1(const double y1){y1_=y1;}
    /*!
     *\fn void set_y2(const double y2)
     * \brief {Changer le valeur du premier élément}
     * \param[in] y2 Nouveau double pour le deuxiéme élément
     */
    void set_y2(const double y2){y2_=y2;}
    /*!
     *\fn R2 & roundR()
     * \brief {Arrondir aux nombres entiers pour connaître la possition avec des pixels.}
     */
    R2 & roundR();
    /*!
     *\fn friend std::ostream & operator<<(std::ostream & st, const R2& v)
     * \brief {Montrer le élément de R2 (non nécéssaire pour le Projet, mais util pour coder)}
     * \param[in] v Objet R2 qu'on veut montrer dans l'écran
     */
    friend std::ostream & operator<<(std::ostream & st, const R2& v);
};
/*!
 *\fn R2 operator*(const double l,const R2& v)
 * \brief {Opérateur de multiplication par double}
 * \param[in] l Double pour lequelle on veut multipliquer l'objet R2
 * \param[in] v Objet R2 qu'on veut multipliquer
 */
R2 operator*(const double l,const R2& v);
/*!
 *\fn R2 operator+(const R2& l,const R2& v)
 * \brief {Opérateur de somme d'éléments de R2}
 * \param[in] l Premier terme R2 à sommer
 * \param[in] v Deuxiéme terme R2 à sommer
 */
R2 operator+(const R2& l,const R2& v);
/*!
 *\fn R2 operator-(const R2& l,const R2& v)
 * \brief {Opérateur de soustraction d'éléments de R2 }
 * \param[in] l Terme R2 initial
 * \param[in] v Terme R2 à soustraire
 */
R2 operator-(const R2& l,const R2& v);
#endif /* R2_h */
