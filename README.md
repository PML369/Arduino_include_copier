#Arduino_include_copier
##A helper program to sort out include files for compiling Arduino projects with Visual Micro
This is a small c++ program to copy include files from your project into the build directory created by Visual Micro.
Visual Micro is an add-in for Microsoft Visual Studio to allow you to build Arduino code directly.
At the moment, it has trouble handling include files from directories relative to your code.
This program sorts them out!  

It takes 3 or more arguments. These are:  
```[build_dir] [src_dir] [ino_file_1]...[ino_file_n]```  
Each source file should be separated by a space.
The program will scan these files for relative includes, and copy them into the build directory so that the Arduino build system can find them.  
NB: It does not recurse down the includes, so it only copies top-level includes.  
  
A sample batch file is included to demonstrate the program's usage.
Put it in the build directory (Visual Micro will tell you this) and run it each time you want to build the project.  

A pre-compiled binary and the batch file can be found in the bin/ directory.

##Compiling
You can compile the code yourself, but you will need my "utils" functions fisrt.
They can be found [here](https://github.com/PML369/Utils/).

##Contact

If you have any requests for future releases, feel free to email plpub2@gmail.com 



##Copyright

This code is Copyright (C) 2013  Peter Lotts. 

It is released under the GNU General Public Licence version 3. 



This program is distributed in the hope that it will be useful,  
but WITHOUT ANY WARRANTY; without even the implied warranty of  
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  
GNU General Public License for more details.  