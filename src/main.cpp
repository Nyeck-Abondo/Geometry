#include <iostream>
#include "geometry/vector.h"
#include "geometry/point.h"
#include "geometry/utils.h"

int main() {
    std::cout<< "\t=========================MENU DU PROGRAMME======================="<< std::endl;

    std::cout<<"\t==================TRANSFORMATIONS APPLIQUEES AUX POINTS=================="<<std::endl<<std::endl
            << "1-Translation d\'un point par un vecteur (ou par insertion de composantes dx et dy)"<<std::endl
            <<"2-Scale d'un point par un vecteur"<<std::endl
            <<"3-Image de la rotation d'un point de centre l'origine et d'angle quelconque"<<std::endl<<std::endl;

    std::cout<<"\t==================TRANSFORMATIONS APPLIQUEES AUX VECTEURS===================="<<std::endl
            <<"4-Addition de deux vecteurs (fournis par l'utilisateur)"<<std::endl
            <<"5-Soustraction de deux vecteurs (fournis par l'utilisateur)"<<std::endl
            <<"6-Scale d'un vecteur"<<std::endl
            <<"7-Produit scalair de deux vecteurs (founis par l'utilisateur)"<<std::endl
            <<"8-Norme d'un vecteur"<<std::endl
            <<"9-Normalisation d'un vecteur"<<std::endl
            <<"10-Interpolation lineaire"<<std::endl
            <<"11-Determinant de deux vecteurs"<<std::endl<<std::endl;
            
    std::cout<<"\t==================TRANSFORMATIONS APPLIQUEES AUX POINTS=================="<<std::endl<<std::endl;
    Point2f p = MakeP2f(2.0f, 3.0f);
    Print("Point:", ToString(p));

    Vector2f v = MakeV2f(1.0f, -1.0f);
    Point2f p2 = Translate(p, v);
    Print("Translated:", ToString(p2));
    std::cout << std::endl;

    //TEST DE LA SECONDE FONCTION Tanslate

    float dx = 5.0f;
    float dy = 2.0f;

    p2 = Translate(p, dx, dy);
    Print("point:", ToString(p));
    Print("Translate 02:", ToString(p2));
    std::cout << std::endl;

    //TEST DE LA FONCTION SCALE

    float kx = 2;
    float ky = 1.2;

    p2 = Scale(p, kx, ky);
    Print("point:", ToString(p));
    Print("Test de la fonction Scale:", ToString(p2));
    std::cout << std::endl;

    std::cout<< "second test de scale"<< std::endl;

    p2 = Scale(p, v);
    Print("point:", ToString(p));
    Print("vecteur:", ToString(v));
    Print("Test de la fonction scale", ToString(p2));
    std::cout << std::endl;

    //TEST DE LA FONCTION ROTATE

    float angle = 60;
    p2 = Rotate(p, angle);
    Print("point :", ToString(p));
    Print("Test de la fonction Rotate:", ToString(p2));
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout<<"\t==================TRANSFORMATIONS APPLIQUEES AUX VECTEURS===================="<<std::endl<<std::endl;

    Vector2f U = MakeV2f(5.0f, 2.0f);
    Vector2f K = MakeV2f(1.0f,6.0f);
    Point2f X = MakeP2f(3.0f, 4.0f);

    Vector2f U2 = Add(U, K);
    Print("vecteur 1:", ToString(U));
    Print("vecteur 2:", ToString(K));
    Print("Test de la fonction Add", ToString(U2));
    std::cout << std::endl;

    //TEST DE LA FONCTION SUB
    U2 = Sub(U, K);
    Print("vecteur 1:", ToString(U));
    Print("vecteur 2:", ToString(K));
    Print("Test de la fonction sub", ToString(U2));
    std::cout << std::endl;

    //TES DE LA FONCTION SCALE
    float coef = 4.0f;
    U2 = Scale(U, coef);
    Print("vecteur 1:", ToString(U));
    Print("Test de la fonction Scale", ToString(U2));
    std::cout << std::endl;

    //TEST DE LA FONCTION DOT
    float scalaire = 0;
    scalaire = Dot(U, K);
    Print("vecteur 1:", ToString(U));
    Print("vecteur 2:", ToString(K));
    std::cout << "Test de la fonction Dot :"<<std::endl <<" le produit sclaire est: "<< scalaire <<std::endl;
    std::cout << std::endl;

    //TEST DE LA FONCTION LENGHT
    float l = Length(U);
    Print("vecteur 1:", ToString(U));
    std::cout << "Test de la fonction Length :"<<std::endl <<" la norme  est: "<< l <<std::endl;

    //TEST DE NORMALIZE
    U2 = Normalize(U);
    Print("vecteur 1:", ToString(U));
    Print("Test de la fonction Normalize", ToString(U2));
    std::cout << std::endl;
    
    //TEST DE LA FONCTION Lerp
    float t = 3.0f;
    U2 = Lerp(U, K, t);
    Print("vecteur 1:", ToString(U));
    Print("vecteur 2:", ToString(K));
    Print("Test de la fonction Lerp", ToString(U2));
    std::cout << std::endl;

    //TEST DE LA FONCTION DETERMIINANT
    float det = Determinant(U, K);
    Print("vecteur 1:", ToString(U));
    Print("vecteur 2:", ToString(K));
    std::cout << "Test de la fonction Determinant :"<<std::endl <<" le Determinant  est: "<< det <<std::endl;

    return 0;
}