#pragma once
#include <iostream>

#include "Shapes.h"

class Point : public Shapes
{
private:
	coord x = 0, y = 0;
public:
	Point(coord x_, coord y_) : x(x_), y(y_) {};
	Point(const Point& orig) : x(orig.x), y(orig.y) {};
	Point(Point&& orig) noexcept : x(std::move(orig.x)), y(orig.y) {};
	Point& operator=(const Point&);
	Point& operator=(Point&&) noexcept;
	~Point() = default;

	coord getX() const { return x; }
	coord getY() const { return y; }
	double area() const override { return 0; }
	Point& operator+=(const Point&);
	Point& operator-=(const Point&);

	friend Point operator+(const Point&, const Point&);
	friend Point operator-(const Point&, const Point&);
	friend bool operator==(const Point&, const Point&);
	friend std::ostream& operator<<(std::ostream& os, const Point&);
	std::string to_string() const override;

};

