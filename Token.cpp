#include "Token.h"

void Token::copyUnion(const Token& orig)
{
	switch (orig.tok)
	{
	case STRING: new(&str) std::string(orig.str); break;
	case POINT: new(&point) Point(orig.point); break;
	case CIRCLE: new(&circle) Circle(orig.circle); break;
	case TRIANGLE: new(&triangle) Triangle(orig.triangle); break;
	case RECTANGLE: new(&rectangle) Rectangle(orig.rectangle); break;
	}
}

void Token::free()
{
	switch (tok)
	{
	case STRING: str.~basic_string(); break;
	case POINT: point.~Point(); break;
	case CIRCLE: circle.~Circle(); break;
	case TRIANGLE: triangle.~Triangle(); break;
	case RECTANGLE: rectangle.~Rectangle(); break;
	}
}

Token& Token::operator=(const Token& orig)
{
	switch (orig.tok)
	{
	case STRING: *this = orig.str; break;
	case POINT: *this = orig.point; break;
	case CIRCLE: *this = orig.circle; break;
	case TRIANGLE: *this = orig.triangle; break;
	case RECTANGLE: *this = orig.rectangle; break;
	}

	return *this;
}

Token& Token::operator=(const std::string& str_)
{
	if (tok == STRING)
		str = str_;
	else
	{
		free();
		tok = STRING;
		new(&str) std::string(str_);
	}

	return *this;
}

Token& Token::operator=(const Point& point_)
{
	if (tok == POINT)
		point = point_;
	else
	{
		free();
		tok = POINT;
		new(&point) Point(point_);
	}

	return *this;
}

Token& Token::operator=(const Circle& circle_)
{
	if (tok == CIRCLE)
		circle = circle_;
	else
	{
		free();
		tok = CIRCLE;
		new(&circle) Circle(circle_);
	}

	return *this;
}

Token& Token::operator=(const Triangle& triangle_)
{
	if (tok == TRIANGLE)
		triangle = triangle_;
	else
	{
		free();
		tok = TRIANGLE;
		new(&triangle) Triangle(triangle_);
	}

	return *this;
}

Token& Token::operator=(const Rectangle& rectangle_)
{
	if (tok == RECTANGLE)
		rectangle = rectangle_;
	else
	{
		free();
		tok = RECTANGLE;
		new(&rectangle) Rectangle(rectangle_);
	}

	return *this;
}

std::string Token::to_string() const
{
	if (tok == POINT)
		return point.to_string();
	if (tok == CIRCLE)
		return circle.to_string();
	if (tok == RECTANGLE)
		return rectangle.to_string();
	if (tok == TRIANGLE)
		return triangle.to_string();

	return "err";
}
