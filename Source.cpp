#include <iostream>
#include <string>
#include <fstream>
#include "Algorithm.h"

int main(int argc, char** argv)
{
	if (argc != 4) {
		std::cerr << "usage: " << argv[0] << " <source-file> <target-file>\n";
		return 4;
	}

	std::ifstream input_file(argv[1]);
	if (!input_file)
	{
		std::cerr << "failed to open " << argv[1] << " for reading\n";
		return 3;
	}

	std::ofstream output_file(argv[2]); 
	if (!output_file)
	{
		std::cerr << "failed to open " << argv[2] << " for writing\n";
		input_file.close();
		return 3;
	}

	std::string in_shapes_str = read_from_file(input_file);

	try
	{
		std::string ans = sort_shape_areas(in_shapes_str, std::stoi(argv[3]));

		if (std::isdigit(ans[0]))
			output_file << ans;
		else
		{
			std::cerr << ans;
			input_file.close();
			output_file.close();
			
			return 2;
		}
	}
	catch (...)
	{
		std::cerr << "Unsupported polymorphic_mechanism value " << argv[3];
		input_file.close();
		output_file.close();

		return 1;
	}

	std::clog << "Program succesfully executed" << std::endl;
	input_file.close();
	output_file.close();

	return 0;
}