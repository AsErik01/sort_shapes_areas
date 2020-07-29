#include "Circle.h"

std::ostream& operator<<(std::ostream& os, const Circle& c)
{
	os << c.area() << " Circle " << c.center.getX() << ' ' << c.center.getY() << ' ' << c.radius << std::endl;

	return os;
}

Circle& Circle::operator=(const Circle& orig)
{
	center = orig.center;
	radius = orig.radius;

	return *this;
}

Circle& Circle::operator=(Circle&& orig) noexcept
{
	center = std::move(orig.center);
	radius = std::move(orig.radius);

	return *this;
}

std::string Circle::to_string() const
{
	std::string ans;
	ans += std::to_string(area()) + " Circle " + std::to_string(center.getX()) + " " + std::to_string(center.getY()) + " " + std::to_string(radius) + "\n";

	return ans;
}

