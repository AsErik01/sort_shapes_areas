#include "Rectangle.h"

Rectangle& Rectangle::operator=(const Rectangle& orig)
{
	a = orig.a;
	c = orig.c;

	return *this;
}

Rectangle& Rectangle::operator=(Rectangle&& orig) noexcept
{
	a = std::move(orig.a);
	c = std::move(orig.c);

	return *this;
}

double Rectangle::area() const
{
	Point length_width = c - a;
	double s = length_width.getX() * length_width.getY();

	return s > 0 ? s : -s;
}

std::string Rectangle::to_string() const
{
	std::string ans;
	ans += std::to_string(area()) + " Rectangle " + std::to_string(a.getX()) + " " + std::to_string(a.getY()) + " " +
		std::to_string(c.getX()) + " " + std::to_string(c.getY()) + "\n";

	return ans;
}

std::ostream& operator<<(std::ostream& os, const Rectangle& r)
{
	os << r.area() << " Rectangle " << r.a.getX() << ' ' << r.a.getY() << ' ' << r.c.getX() << ' ' << r.c.getY() << std::endl;

	return os;
}
