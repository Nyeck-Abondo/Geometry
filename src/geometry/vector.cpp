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

Vector2f Add(const Vector2f& a, const Vector2f& b){
    Vector2f vecteur;
    vecteur.x = a.x + b.x;
    vecteur.y = a.y + b.y;
    return vecteur;
}

Vector2f Sub(const Vector2f& a, const Vector2f& b){
    Vector2f vecteur;
    vecteur.x = a.x - b.x;
    vecteur.y = a.y + b.y;
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
    u.x /= length;
    u.y /= length;
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