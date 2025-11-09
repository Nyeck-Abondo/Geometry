#ifndef POINT_H
#define POINT_H

#include <string>

struct Vector2f;
struct Point2f {
    float x;
    float y;
};

Point2f MakeP2f(float x, float y);
Point2f MakeNullPoint();
Point2f Translate(const Point2f& p, float dx, float dy);
Point2f Translate(const Point2f& p, const Vector2f& v);
Point2f Scale(const Point2f& p, float sx, float sy);
Point2f Scale(const Point2f& p, const Vector2f& s);
Point2f Rotate(const Point2f& p, float angleDegree);
bool Egal(const Point2f& a, const Point2f& b, float tolerance = 0.0001f);
bool Different(const Point2f& a, const Point2f& b, float tolerance = 0.0001f);


std::string ToString(const Point2f& p);

#endif