#pragma once
#include <iostream>
#include "Point.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"

class Token
{
private:
	enum { STRING, POINT, CIRCLE, TRIANGLE, RECTANGLE } tok;
	union
	{
		std::string str;
		Point point;
		Circle circle;
		Triangle triangle;
		Rectangle rectangle;
	};

	void copyUnion(const Token&);
	void free();
public:
	Token() : tok(STRING), str("") {};
	Token(const Token& orig) : tok(orig.tok) { copyUnion(orig); }
	Token(const std::string& str_) : tok(STRING), str(str_) {};
	Token(const Point& point_) : tok(POINT), point(point_) {};
	Token(const Circle& circle_) : tok(CIRCLE), circle(circle_) {};
	Token(const Triangle& triangle_) : tok(TRIANGLE), triangle(triangle_) {};
	Token(const Rectangle& rectangle_) : tok(RECTANGLE), rectangle(rectangle_) {};

	Token& operator=(const Token&);
	Token& operator=(const std::string& str_);
	Token& operator=(const Point& point_);
	Token& operator=(const Circle& circle_);
	Token& operator=(const Triangle& triangle_);
	Token& operator=(const Rectangle& rectangle_);
	std::string to_string() const;
	~Token()
	{
		free();
	}


	friend bool compare_areas(const Token&, const Token&);
	friend std::string sort_shape_areas(const std::string&, int);
	friend std::string sort_shape_areas_dynamic(const std::string&);
	friend std::string sort_shape_areas_static(const std::string&);
};

