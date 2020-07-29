#pragma once

#include <iostream>
#include <string>

class Shapes
{
public:
	using coord = double;
	virtual double area() const = 0;
	Shapes() = default;

	virtual std::string to_string() const = 0;
	virtual ~Shapes() {};
};

