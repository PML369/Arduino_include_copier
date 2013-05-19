/*
 Copyright (C) 2013  Peter Lotts

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <Utils\utils\utils.h>

//#define VERBOSE // Uncomment to turn on logging

// Arguments are: [build_dir] [src_dir] [file_to_scan_1] [file_to_scan_2]...[file_to_scan_n]
int main(int argc, char **argv)
{
	if (argc < 3) { return 1; }

	std::string build_dir(argv[1]), src_dir(argv[2]), fin, src, dest, incl_f, l;
	std::ifstream input;

	for (int n=3; n < argc; n++) // For each file to parse
	{
		input.open(src_dir + "\\" + (std::string)argv[n]);
		#ifdef VERBOSE
			std::cout << src_dir + "\\" + (std::string)argv[n] << std::endl;
		#endif
		while (std::getline(input,l))
		{
			if (l.substr(0,10) == "#include \"")
			{
				incl_f=l.substr(10,l.find_last_of('"')-10);
				if (incl_f.find("\\") != std::string::npos)
				{
					src=src_dir + "\\" + incl_f;
					dest=build_dir + "\\" + incl_f;

					utils::ifnoexistmake(dest.substr(0, dest.find_last_of("\\") +1), true);

					if (! CopyFile(src.c_str(),dest.c_str(),false))
					{
						std::cerr << "Failed to copy " << src << " with error " << GetLastError() << std::endl;
					}
					else
					{
						#ifdef VERBOSE
							std::cout << "Copied" << src << std::endl;
						#endif
					}
				}
			}
		}
		input.close();
	}
	return 0;
}