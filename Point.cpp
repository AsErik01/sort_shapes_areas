#include "Point.h"

Point operator+(const Point& first, const Point& second)
{
	Point res = first;
	res += second;

	return res;
}

Point operator-(const Point& first, const Point& second)
{
	Point res = first;
	res -= second;

	return res;
}

bool operator==(const Point& first, const Point& second)
{
	return first.x == second.x && first.y == second.y;
}

std::ostream& operator<<(std::ostream& os, const Point& p)
{
	os << p.area() << " Point " << p.x << ' ' << p.y << std::endl;

	return os;
}

Point& Point::operator=(const Point& orig)
{
	x = orig.x;
	y = orig.y;

	return *this;
}

Point& Point::operator=(Point&& orig) noexcept
{
	x = std::move(orig.x);
	y = std::move(orig.y);

	return *this;
}

Point& Point::operator+=(const Point& other)
{
	x += other.x;
	y += other.y;

	return *this;
}

Point& Point::operator-=(const Point& other)
{
	x -= other.x;
	y -= other.y;

	return *this;
}

std::string Point::to_string() const
{
	std::string ans;
	ans += std::to_string(area()) + " Point " + std::to_string(x) + " " + std::to_string(y) + "\n";

	return ans;
}
