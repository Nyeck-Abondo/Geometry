## **TRANSFORMATIONS DU LE PLAN**

### **Description du projet de Game Programming**

Ce projet simule differentes transformations du plan appliquées d'une part aux points du plan, et d'autre part aux vecteurs du plan au travers de 11 fonctions differentes, tout en recourant à la programation modulaire pour leur implémentation. Il utilise pour se faire deux fichiers **entête** : point.h et vector.h utilisant la notion de **structure** et de surdefinition de fonction pour simuler chaques transformations appliquées aux entités précédement citée.

## **🧰DESCRIPTION DE L'ARBORESSENCE DU PROJET**

```fichier
📁src/
│──📄main.cpp
│──📄geometry.exe
│──📁geometry/
│   |──────📄point.h
│   |──────📄vector.h
│   |──────📄vector.cpp
│   |──────📄point.cpp 
```
## **📝Présentation des fichiers du programme et leurs loclisation**

### **fichier entête de manipulation des points : point.h**

### **localisation**

#### **📁src/geomtry/point.h**

```cpp
#ifndef POINT_H
#define POINT_H

#include <string>

struct Vector2f;
//definition de la strure point, permettant de regrouper les composantes en abscisse et en ordonnée et en abscisse des points utilisés
struct Point2f {
    float x;
    float y;
};

Point2f MakeP2f(float x, float y);
//crée des points dans le plan.assigne des valeurs aux différents champs des variables de type Point2f
Point2f MakeNullPoint();
//fonction renvoyqnt à lùorigine du repère. elle qssigne la valeur 0 aux composantes du point qui la reçoit
Point2f Translate(const Point2f& p, float dx, float dy);
//fonction effectuant la translation du point selon les composantes fournies.
Point2f Translate(const Point2f& p, const Vector2f& v);
//effectue la même tache que la fonction precedente en utilisant un vecteur.
Point2f Scale(const Point2f& p, float sx, float sy);
//effectue un redimentionnement par le produit des composants d'un point par les variables passées en paramètre
Point2f Scale(const Point2f& p, const Vector2f& s);
//presente le même fonctionne,ent aue la fonction précedente tout en utilisant un vecteur
Point2f Rotate(const Point2f& p, float angleDegree);
//effectue la rotation d'un point par rapport à l'origine
bool Egal(const Point2f& a, const Point2f& b, float tolerance = 0.0001f);
//vérifie l'égalité entre deux point qvec un précision de 0.0001
bool Different(const Point2f& a, const Point2f& b, float tolerance = 0.0001f);



std::string ToString(const Point2f& p);
//fonction d'affichage des resultats

#endif
```

### **Implementation dans point.cpp**

#### **📁src/geomtry/point.cpp**

```cpp
#include "point.h"
#include "vector.h"
#include <cmath>
#include <sstream>
#include <string>
#include <vector>
#include <map>


Point2f MakeP2f(float x, float y){
    Point2f point = {x , y};
    return point;
}

Point2f Translate(const Point2f& p, float dx, float dy){
    Point2f point;
    point.x = p.x + dx;
    point.y = p.y + dy;
    return point;
}

Point2f Translate(const Point2f& p, const Vector2f& v){
    Point2f point;
    point.x = p.x + v.x;
    point.y = p.y + v.y;
    return point;
}

Point2f Scale(const Point2f& p, float sx, float sy){
    Point2f Point = { p.x, p.y};
    Point.x *= sx;
    Point.y *= sy;
    return Point;
}

Point2f Scale(const Point2f& p, const Vector2f& s){
    Point2f point = {p.x, p.y};
    point.x *= s.x;
    point.y *= s.y;
    return point;
}

Point2f Rotate(const Point2f& p, float angledegree){
    Point2f image = {p.x , p.y};
    image.x = p.x * std::cos((angledegree * M_PI) / 180) - p.y * std::sin((angledegree * M_PI) / 180);
    image.y = p.x * std::sin((angledegree * M_PI) / 180) + p.y * std::cos((angledegree * M_PI) / 180);
    return image;
}

bool Egal(const Point2f& a, const Point2f& b, float tolerance){
    if ((std::fabs(a.x - b.x) < tolerance) && (std::fabs(a.y - b.y) < tolerance))
    {
        return true;
    }
    return false;
}
bool Different(const Point2f& a, const Point2f& b, float tolerance){
    if (a.x == b.x || a.y == b.y)
    {
        return false;
    }
    return true;
}

Point2f MakeNullPoint(){
    Point2f p ={0, 0};
    return p;
}


std::string ToString(const Point2f& p) {
    return "(" + std::to_string(p.x) + " ; "+ std::to_string(p.y) + ")";
}
```

### **📝fichier entête de manipulation des vecteurs : vector.h**

### **📁src/geometry/vector.h**

```cpp
#ifndef VECTOR_H
#define VECTOR_H

#include "point.h"
#include <string>
#include <cmath>

struct Vector2f {
    float x;
    float y;
};

//crée des vecteurs
Vector2f MakeV2f(float x, float y);
Vector2f MakeV2f(const Point2f& a, const Point2f& b);
//crée un vecteur null
Vector2f MakeNullVector();
//additionne deux vecteurs
Vector2f Add(const Vector2f& a, const Vector2f& b);
//effectue la soustrqction de deux vecteurs
Vector2f Sub(const Vector2f& a, const Vector2f& b);
//procède q une mise à l'échelle
Vector2f Scale(const Vector2f& v, float scalar);
//Effectue le produit scamaire de deux vecteurs
float Dot(const Vector2f& a, const Vector2f& b);
//Déter,ine lq nor,e de deux vecteurs
float Length(const Vector2f& v);
//normalise un vecteur
Vector2f Normalize(const Vector2f& v);
// effectue l'interpolqtion linéaire de deux vecteurs
Vector2f Lerp(const Vector2f& a, const Vector2f& b, float t);
//calcule le déterminant de deux vecteurs
float Determinant(const Vector2f& a, const Vector2f& b);
//vérifie l'égalité entre dux vecteur à 0.0001 prèt
bool Egal(const Vector2f& a, const Vector2f& b, float tolerance = 0.0001f);
bool Different(const Vector2f& a, const Vector2f& b, float tolerance = 0.0001f);

//fonction d'affichage des resultats finaux
std::string ToString(const Vector2f& v);

#endif
```

### **✏️Implement ation des donftions**

### **📁src/geometry/vector.cpp**

```cpp
#include "vector.h"
#include <cmath>
#include "point.h"

Vector2f MakeV2f(float x, float y){
    Vector2f vecteur = {x, y};
    return vecteur;
}

Vector2f MakeV2f(const Point2f& a, const Point2f& b){
    Vector2f vecteur;
    vecteur.x = b.x - a.x;
    vecteur.y = b.y - a.y;
    return vecteur;
}

Vector2f MakeNullVector(){
    Vector2f v = {0, 0};
    return v;
}

Vector2f Add(const Vector2f& a, const Vector2f& b){
    Vector2f vecteur;
    vecteur.x = a.x + b.x;
    vecteur.y = a.y + b.y;
    return vecteur;
}

Vector2f Sub(const Vector2f& a, const Vector2f& b){
    Vector2f vecteur;
    vecteur.x = a.x - b.x;
    vecteur.y = a.y - b.y;
    return vecteur;
}

Vector2f Scale(const Vector2f& a, float scalar){
    Vector2f vecteur = {a.x, a.y};
    vecteur.x *= scalar;
    vecteur.y *= scalar;
    return vecteur;
}

float Dot(const Vector2f& a, const Vector2f& b){
    float scalair = 0;
    scalair = a.x * b.x + a.y * b.y;
    return scalair;
}

float Length(const Vector2f& v){
    return sqrt(pow(v.x, 2) + pow(v.y, 2));
}

Vector2f Normalize(const Vector2f& a){
    Vector2f u = {a.x, a.y};
    float length = Length(u);
    if (u.x == 0 && u.y == 0)
    {
        u = {0, 0};
    }
    else{
        u.x /= length;
        u.y /= length;
    }
    return u;
}

Vector2f Lerp(const Vector2f& a, const Vector2f& b, float t){
    Vector2f v;
    v.x = (1 - t) * a.x + t * b.x;
    v.y = (1 - t) * a.y + t * b.y;
    return v;
}

float Determinant(const Vector2f& a, const Vector2f& b){
    return a.x * b.y - a.y * b.x;
}

std::string ToString(const Vector2f& v){
    return "(" + std::to_string(v.x) + ";"+ std::to_string(v.y) + ")";
}

bool Egal(const Vector2f& a, const Vector2f& b, float tolerance){
    if (Length(a) == Length(b))
    {
        return true;
    }
    return false;
}

bool Different(const Vector2f& a, const Vector2f& b, float tolerance){
    if (Length(a)==Length(b))
    {
        return false;
    }
    return true;
}
```

## **FICHIER PRINCPAL DE TEST**

### **📁src/main.cpp**

 Il contient l'ensemble des tests et renvoie le nombre de réussite et d'echec

```cpp
#include "geometry/point.h"
#include "geometry/vector.h"
#include "geometry/utils.h"
#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

// ============================================================================
// 🧪 TESTS UNITAIRES FROM SCRATCH
// ============================================================================

void RunTests() {
    cout << "🧪 LANCEMENT DES TESTS UNITAIRES\n" << endl;
    int testsReussis = 0;
    int testsTotal = 0;

    // Macro de test maison
    #define TEST(nom, condition) \
        do { \
            testsTotal++; \
            if (condition) { \
                testsReussis++; \
                cout << "✅ " << nom << endl; \
            } else { \
                cout << "❌ " << nom << " - ÉCHEC" << endl; \
            } \
        } while(0)

    // ==================== TESTS POINTS ====================
    cout << "📍 TESTS DES POINTS" << endl;
    
    // Test création
    Point2f p1 = MakeP2f(2.0f, 3.0f);
    TEST("Création point", p1.x == 2.0f && p1.y == 3.0f);
    
    Point2f zero = MakeNullPoint();
    TEST("Point nul", zero.x == 0.0f && zero.y == 0.0f);
    
    // Test égalité
    Point2f p2 = MakeP2f(2.0f, 3.0f);
    TEST("Égalité points identiques", Egal(p1, p2));
    
    Point2f p3 = MakeP2f(2.00001f, 3.00001f);
    TEST("Égalité avec tolérance", Egal(p1, p3, 0.001f));
    TEST("Différence avec précision", Different(p1, p3, 0.000001f));
    
    // Test translation
    Point2f p4 = Translate(p1, 1.0f, -1.0f);
    Point2f expected1 = MakeP2f(3.0f, 2.0f);
    TEST("Translation point", Egal(p4, expected1));
    
    // Test translation avec vecteur
    Vector2f v = MakeV2f(2.0f, 0.0f);
    Point2f p5 = Translate(p1, v);
    Point2f expected2 = MakeP2f(4.0f, 3.0f);
    TEST("Translation avec vecteur", Egal(p5, expected2));
    
    // Test mise à l'échelle
    Point2f p6 = Scale(p1, 2.0f, 3.0f);
    Point2f expected3 = MakeP2f(4.0f, 9.0f);
    TEST("Mise à l'échelle point", Egal(p6, expected3));
    
    // Test rotation
    Point2f p7 = Rotate(MakeP2f(1.0f, 0.0f), 90.0f);
    Point2f expected4 = MakeP2f(0.0f, 1.0f);
    TEST("Rotation 90°", Egal(p7, expected4, 0.001f));

    // ==================== TESTS VECTEURS ====================
    cout << "\n📐 TESTS DES VECTEURS" << endl;
    
    // Test création
    Vector2f v1 = MakeV2f(3.0f, 4.0f);
    TEST("Création vecteur", v1.x == 3.0f && v1.y == 4.0f);
    
    Vector2f vZero = MakeNullVector();
    TEST("Vecteur nul", vZero.x == 0.0f && vZero.y == 0.0f);
    
    // Test création depuis points
    Vector2f v2 = MakeV2f(MakeP2f(1.0f, 1.0f), MakeP2f(4.0f, 5.0f));
    Vector2f expected5 = MakeV2f(3.0f, 4.0f);
    TEST("Vecteur entre points", Egal(v2, expected5));
    
    // Test addition
    Vector2f v3 = Add(v1, v2);
    Vector2f expected6 = MakeV2f(6.0f, 8.0f);
    TEST("Addition vecteurs", Egal(v3, expected6));
    
    // Test soustraction
    Vector2f v4 = Sub(v1, v2);
    Vector2f expected7 = MakeV2f(0.0f, 0.0f);
    TEST("Soustraction vecteurs", Egal(v4, expected7));
    
    // Test multiplication scalaire
    Vector2f v5 = Scale(v1, 2.0f);
    Vector2f expected8 = MakeV2f(6.0f, 8.0f);
    TEST("Multiplication scalaire", Egal(v5, expected8));
    
    // Test produit scalaire
    Vector2f v6 = MakeV2f(1.0f, 0.0f);
    Vector2f v7 = MakeV2f(0.0f, 1.0f);
    float dot = Dot(v6, v7);
    TEST("Produit scalaire perpendiculaires", dot == 0.0f);
    
    float dot2 = Dot(v6, v6);
    TEST("Produit scalaire même vecteur", dot2 == 1.0f);
    
    // Test longueur
    float len = Length(v1);
    TEST("Longueur vecteur", abs(len - 5.0f) < 0.0001f);
    
    float lenZero = Length(vZero);
    TEST("Longueur vecteur nul", lenZero == 0.0f);
    
    // Test normalisation
    Vector2f v8 = Normalize(v1);
    float lenNorm = Length(v8);
    TEST("Normalisation vecteur", abs(lenNorm - 1.0f) < 0.0001f);
    
    Vector2f v9 = Normalize(vZero);
    TEST("Normalisation vecteur nul", Egal(v9, vZero));
    
    // Test interpolation
    Vector2f v10 = MakeV2f(0.0f, 0.0f);
    Vector2f v11 = MakeV2f(10.0f, 10.0f);
    Vector2f v12 = Lerp(v10, v11, 0.5f);
    Vector2f expected9 = MakeV2f(5.0f, 5.0f);
    TEST("Interpolation linéaire", Egal(v12, expected9));
    
    // Test déterminant
    float det = Determinant(v6, v7);
    TEST("Déterminant vecteurs perpendiculaires", det == 1.0f);

    // ==================== TESTS INTÉGRATION ====================
    cout << "\n🔗 TESTS D'INTÉGRATION" << endl;
    
    // Test transformation complète
    Point2f p = MakeP2f(2.0f, 0.0f);
    Point2f result = Translate(Scale(Rotate(p, 90.0f), 2.0f, 2.0f), 1.0f, 1.0f);
    TEST("Transformation complexe", !Egal(p, result));
    
    // Test cohérence vecteur-point
    Point2f a = MakeP2f(0.0f, 0.0f);
    Point2f b = MakeP2f(3.0f, 4.0f);
    Vector2f ab = MakeV2f(a, b);
    Point2f b_calc = Translate(a, ab.x, ab.y);
    TEST("Cohérence point-vecteur", Egal(b, b_calc));
    
    // Test propriété vecteur nul
    Vector2f nullVec = MakeNullVector();
    Point2f p_unchanged = Translate(p, nullVec);
    TEST("Translation par vecteur nul", Egal(p, p_unchanged));

    // ==================== RAPPORT FINAL ====================
    cout << "\n📊 RAPPORT DES TESTS" << endl;
    cout << "Tests réussis: " << testsReussis << "/" << testsTotal << endl;
    
    if (testsReussis == testsTotal) {
        cout << "🎉 TOUS LES TESTS SONT RÉUSSIS !" << endl;
    } else {
        cout << "⚠️  Certains tests ont échoué" << endl;
    }

    #undef TEST
}

// ============================================================================
// 🎯 FONCTION PRINCIPALE
// ============================================================================

int main() {
    cout << "=========================================" << endl;
    cout << "       📐 MATH - TESTS UNITAIRES" << endl;
    cout << "=========================================" << endl;
    
    RunTests();
    
    cout << "\n=========================================" << endl;
    cout << "           🏁 TESTS TERMINÉS" << endl;
    cout << "=========================================" << endl;
    
    return 0;
}
```

### **resultat attendu** :

**ECHEC : 0**

**REUSSITE : 26**