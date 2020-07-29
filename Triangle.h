#pragma once
#include <cmath>
#include "Shapes.h"
#include "Point.h"

class Triangle : public Shapes
{
private:
	Point a, b, c;
public:
	Triangle(const coord& x1, const coord& y1, const coord& x2, const coord& y2, const coord& x3, const coord& y3) : a(x1, y1), b(x2, y2), c(x3, y3) {};
	//Triangle(const Point& a_, const Point& b_, const Point& c_) : a(a_), b(b_), c(c_) {};
	Triangle(const Triangle& orig) : a(orig.a), b(orig.b), c(orig.c) {};
	Triangle(Triangle&& orig) noexcept : a(std::move(orig.a)), b(std::move(orig.b)), c(std::move(orig.c)) {};
	Triangle& operator=(const Triangle&);
	Triangle& operator=(Triangle&&) noexcept;
	~Triangle() = default;

	double area() const override;
	std::string to_string() const override;

	friend std::ostream& operator<<(std::ostream& os, const Triangle&);
};


