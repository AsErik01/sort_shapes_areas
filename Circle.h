#pragma once
#include "Shapes.h"
#include "Point.h"

class Circle : public Shapes
{
private:
	const double PI = 3.14;
	Point center;
	double radius = 0;

public:
	Circle(const coord& x, const coord& y, const double& radius_) : center(x, y), radius(radius_) {};
	//Circle(const Point& c, const double& radius_) : center(c), radius(radius_) {};
	Circle(const Circle& orig) : center(orig.center), radius(orig.radius) {};
	Circle(Circle&& orig) noexcept : center(std::move(orig.center)), radius(std::move(orig.radius)) {};
	Circle& operator=(const Circle&);
	Circle& operator=(Circle&&) noexcept;
	~Circle() = default;

	double area() const override { return PI * radius * radius; }
	friend std::ostream& operator<<(std::ostream& os, const Circle&);
	std::string to_string() const override;
};

