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
    image.x *= cos(angledegree);
    image.y *= sin(angledegree);
    return image;
}

std::string ToString(const Point2f& p) {
    return "(" + std::to_string(p.x) + " ; "+ std::to_string(p.y) + ")";
}