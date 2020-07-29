#include "Triangle.h"

Triangle& Triangle::operator=(const Triangle& orig)
{
	a = orig.a;
	b = orig.b;
	c = orig.c;

	return *this;
}

Triangle& Triangle::operator=(Triangle&& orig) noexcept
{
	a = std::move(orig.a);
	b = std::move(orig.b);
	c = std::move(orig.c);

	return *this;
}

double Triangle::area() const
{
	Point vec1 = a - b, vec2 = a - c, vec3 = b - c;
	double side1 = std::sqrt(std::pow(vec1.getX(), 2) + std::pow(vec1.getY(), 2));
	double side2 = std::sqrt(std::pow(vec2.getX(), 2) + std::pow(vec2.getY(), 2));
	double side3 = std::sqrt(std::pow(vec3.getX(), 2) + std::pow(vec3.getY(), 2));
	double p = (side1 + side2 + side3) / 2;

	return std::sqrt(p * (p - side1) * (p - side2) * (p - side3));
}

std::string Triangle::to_string() const
{
	std::string ans;
	ans += std::to_string(area()) + " Triangle " + std::to_string(a.getX()) + " " + std::to_string(a.getY()) + " " +
		std::to_string(b.getX()) + " " + std::to_string(b.getY()) + " " +
		std::to_string(c.getX()) + " " + std::to_string(c.getY()) + "\n";

	return ans;
}

std::ostream& operator<<(std::ostream& os, const Triangle& t)
{
	os << t.area() << " Triangle " << t.a.getX() << ' ' << t.a.getY() << ' ' << t.b.getX() << ' ' << t.b.getY() << ' ' << t.c.getX() << ' ' << t.c.getY() << std::endl;

	return os;
}
