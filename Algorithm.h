#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <memory>

#include "Token.h"
#include "Shapes.h"
#include "Point.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"


std::string sort_shape_areas(const std::string&, int = 1);
std::string sort_shape_areas_dynamic(const std::string& in_shapes_str);
std::string sort_shape_areas_static(const std::string& in_shapes_str);
Token check_point(const std::string&);
Token check_circle(const std::string&);
Token check_rectangle(const std::string&);
Token check_triangle(const std::string&);
bool check_triangle_sides(Shapes::coord*);
std::string read_from_file(std::istream&);
bool compare_areas(const Token&, const Token&);
bool is_legal(std::string s, const double& d);