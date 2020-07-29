#include "Algorithm.h"

std::string sort_shape_areas(const std::string& in_shapes_str, int polymorphic_mechanism)
{
	if (polymorphic_mechanism == 0)
		return sort_shape_areas_static(in_shapes_str);
	if (polymorphic_mechanism == 1)
		return sort_shape_areas_dynamic(in_shapes_str);

	return "Unsupported polymorphic_mechanism value " + std::to_string(polymorphic_mechanism);
}

std::string sort_shape_areas_dynamic(const std::string& in_shapes_str)
{
	std::stringstream ss(in_shapes_str);
	std::string s, res;
	std::vector<std::unique_ptr<Shapes>> shapes;

	while (std::getline(ss, s))
	{
		switch (s[0])
		{
		case 'P':
		{
			Token info = check_point(s);
			if (info.tok == Token::STRING)
				return info.str;

			shapes.emplace_back(std::make_unique<Point>(info.point));

			break;
		}
		case 'C':
		{
			Token info = check_circle(s);
			if (info.tok == Token::STRING)
				return info.str;

			shapes.emplace_back(std::make_unique<Circle>(info.circle));

			break;
		}
		case 'R':
		{
			Token info = check_rectangle(s);
			if (info.tok == Token::STRING)
				return info.str;

			shapes.emplace_back(std::make_unique<Rectangle>(info.rectangle));

			break;
		}
		case 'T':
		{
			Token info = check_triangle(s);
			if (info.tok == Token::STRING)
				return info.str;

			shapes.emplace_back(std::make_unique<Triangle>(info.triangle));

			break;
		}
		default: return "Unrecognized shape name\n"; break;
		}
	}

	std::sort(shapes.begin(), shapes.end(), [](const std::unique_ptr<Shapes>& first, const std::unique_ptr<Shapes>& second) { return first->area() < second->area(); });
	std::string ans;
	for (const auto& i : shapes)
		ans += i->to_string();

	return ans;        /// answer
}

std::string sort_shape_areas_static(const std::string& in_shapes_str)
{
	std::stringstream ss(in_shapes_str);
	std::string s, res;
	std::vector<Token> shapes;

	while (std::getline(ss, s))
	{
		switch (s[0])
		{
		case 'P':
		{
			Token info = check_point(s);
			if (info.tok == Token::STRING)
				return info.str;

			shapes.emplace_back(info);

			break;
		}
		case 'C':
		{
			Token info = check_circle(s);
			if (info.tok == Token::STRING)
				return info.str;

			shapes.emplace_back(info);

			break;
		}
		case 'R':
		{
			Token info = check_rectangle(s);
			if (info.tok == Token::STRING)
				return info.str;

			shapes.emplace_back(info);

			break;
		}
		case 'T':
		{
			Token info = check_triangle(s);
			if (info.tok == Token::STRING)
				return info.str;

			shapes.emplace_back(info);

			break;
		}
		default: return "Unrecognized shape name\n"; break;
		}
	}

	std::sort(shapes.begin(), shapes.end(), compare_areas);
	std::string ans;
	for (const auto& i : shapes)
		ans += i.to_string();

	return ans;        /// answer
}

Token check_point(const std::string& s)
{
	using coord = Shapes::coord;
	constexpr size_t args_size = 2;
	coord args[args_size];
	std::istringstream ss(s);
	std::string temp;

	ss >> temp;

	if (temp != "P")
		return std::string("Unrecognized shape identifier\n");

	try
	{
		for (int i = 0; i != args_size; ++i)
		{
			if (ss >> temp)
			{
				args[i] = std::stod(temp);
				if (!is_legal(temp, args[i]))
					return std::string("Non-numeric parameter value " + temp);
			}
			else
				return std::string("Wrong number of parameters for shape identifier P\n");
		}

		if (ss >> temp)
			return std::string("Wrong number of parameters for shape identifier P\n");

		return Point(args[0], args[1]);
	}
	catch (...)
	{
		return "Non-numeric parameter value " + temp;
	}
}

Token check_circle(const std::string& s)
{
	using coord = Shapes::coord;
	constexpr std::size_t args_size = 2;
	coord args[args_size];    //center coordinates
	double radius;
	std::istringstream ss(s);
	std::string temp;

	ss >> temp;
	if (temp != "C")
		return std::string("Unrecognized shape identifier\n");

	try
	{
		for (int i = 0; i < args_size; ++i)
		{
			if (ss >> temp)
			{
				args[i] = std::stod(temp);
				if (!is_legal(temp, args[i]))
					return std::string("Non-numeric parameter value " + temp);
			}
			else
				return std::string("Wrong number of parameters for shape identifier C\n");
		}

		if (ss >> temp)
		{
			radius = std::stod(temp);
			if (!is_legal(temp, radius))
				return std::string("Non-numeric parameter value " + temp);
		}
		else
			return std::string("Wrong number of parameters for shape identifier C\n");


		if (radius <= 0)
			return std::string("Unrecognized shape identifier\n");


		if (ss >> temp)
			return std::string("Wrong number of parameters for shape identifier C\n");

		return Circle(args[0], args[1], radius);
	}
	catch (...)
	{
		return "Non-numeric parameter value " + temp;
	}
}

Token check_rectangle(const std::string& s)
{
	using coord = Shapes::coord;
	constexpr std::size_t args_size = 4;
	coord args[args_size];    //center coordinates

	std::istringstream ss(s);
	std::string temp;

	ss >> temp;
	if (temp != "R")
		return std::string("Unrecognized shape identifier\n");

	try
	{
		for (int i = 0; i < args_size; ++i)
		{
			if (ss >> temp)
			{
				args[i] = std::stod(temp);
				if(!is_legal(temp, args[i]))
					return std::string("Non-numeric parameter value " + temp);
			}
			else
				return std::string("Wrong number of parameters for shape identifier R\n");
		}

		if (args[0] >= args[2] || args[1] >= args[3])             //if <left-x-coord> <= <right-x-coord> or <top-y-coord> <= <bottom-y-coord>
			return std::string("Unrecognized shape identifier\n");

		if (ss >> temp)
			return std::string("Wrong number of parameters for shape identifier R\n");

		return Rectangle(args[0], args[1], args[2], args[3]);
	}
	catch (...)
	{
		return "Non-numeric parameter value " + temp;
	}
}

Token check_triangle(const std::string& s)
{
	using coord = Shapes::coord;
	constexpr std::size_t args_size = 6;
	coord args[args_size];    //center coordinates

	std::istringstream ss(s);
	std::string temp;

	ss >> temp;
	if (temp != "T")
		return std::string("Unrecognized shape identifier\n");

	try
	{
		for (int i = 0; i < args_size; ++i)
		{
			if (ss >> temp)
			{
				args[i] = std::stod(temp);
				if (!is_legal(temp, args[i]))
					return std::string("Non-numeric parameter value " + temp);
			}
			else
				return std::string("Wrong number of parameters for shape identifier T\n");
		}

		if (!check_triangle_sides(args))   //if all 3 points ar in same 
			return std::string("Unrecognized shape identifier\n");


		if (ss >> temp)
			return std::string("Wrong number of parameters for shape identifier T\n");

		return Triangle(args[0], args[1], args[2], args[3], args[4], args[5]);
	}
	catch (...)
	{
		return "Non-numeric parameter value " + temp;
	}
}

bool check_triangle_sides(Shapes::coord* il)
{
	std::size_t i = 0;
	Point a(il[i++], il[i++]), b(il[i++], il[i++]), c(il[i++], il[i++]);
	Point vec1 = a - b, vec2 = a - c, vec3 = b - c;
	double side1 = std::sqrt(std::pow(vec1.getX(), 2) + std::pow(vec1.getY(), 2));
	double side2 = std::sqrt(std::pow(vec2.getX(), 2) + std::pow(vec2.getY(), 2));
	double side3 = std::sqrt(std::pow(vec3.getX(), 2) + std::pow(vec3.getY(), 2));

	return side1 + side2 > side3 && side1 + side3 > side2 && side2 + side3 > side1;
}

std::string read_from_file(std::istream& is)
{
	std::string ans, s;

	while (std::getline(is, s))
		ans += s + "\n";

	return ans;
}

bool compare_areas(const Token& first, const Token& second)
{
	double area1 = 0, area2 = 0;
	switch (first.tok)
	{
	case Token::CIRCLE: area1 = first.circle.area(); break;
	case Token::RECTANGLE: area1 = first.rectangle.area(); break;
	case Token::TRIANGLE: area1 = first.triangle.area(); break;
	default: area1 = 0; break;
	}

	switch (second.tok)
	{
	case Token::CIRCLE: area2 = second.circle.area(); break;
	case Token::RECTANGLE: area2 = second.rectangle.area(); break;
	case Token::TRIANGLE: area2 = second.triangle.area(); break;
	default: area1 = 0; break;
	}

	return area1 < area2;
}

bool is_legal(std::string s, const double& d)
{
	std::string temp = std::to_string(d);

	temp.erase(temp.find_last_not_of('0') + 1);  //delete all unnecessary '0's
	if (temp.back() == '.')
		temp.erase(temp.end() - 1);

	s.erase(s.find_last_not_of('0') + 1);
	if (s.back() == '.')
		s.erase(s.end() - 1);

	return s == temp;
}
