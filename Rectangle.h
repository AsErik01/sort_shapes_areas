#pragma once
#include "Shapes.h"
#include "Point.h"

class Rectangle : public Shapes
{
private:
	Point a, c;
public:
	Rectangle(const coord& x1, const coord& y1, const coord& x2, const coord& y2) : a(x1, y1), c(x2, y2) {};
	Rectangle(const Rectangle& orig) : a(orig.a), c(orig.c) {};
	Rectangle(Rectangle&& orig) noexcept : a(std::move(orig.a)), c(std::move(orig.c)) {};
	Rectangle& operator=(const Rectangle&);
	Rectangle& operator=(Rectangle&&) noexcept;
	~Rectangle() = default;

	double area() const override;

	friend std::ostream& operator<<(std::ostream& os, const Rectangle&);
	std::string to_string() const override;

};


