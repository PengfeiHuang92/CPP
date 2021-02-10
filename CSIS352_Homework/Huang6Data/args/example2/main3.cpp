// This program shows the use of argc and argv for getting file names
// from the command line.  The command line must consist of the name
// to execute the program followed by the name of the input
// file and the name of the output file.  If the command line is not
// in the proper form, or if an error occurred in opening a file, the
// appropriate error message is displayed.

// If everything works correctly, the program will simply read two
// ints from the input file and write the sum to the output file.

// This example passes file names to functions

#include <iostream>
#include <fstream>
using namespace std;

// function prototypes
bool write(char* filename, int& x, int& y);
bool read(char* filename, int& x, int& y);

int main(int argc,char *argv[])
{
   ifstream ifs;
   ofstream ofs;
   int x,y;
   bool success=true;
   if (argc != 3)
   {
      cerr << "usage: " << argv[0] << " <inputfile> <outputfile>\n";
      success=false;
   }
   else
   {
      success = read(argv[1],x,y);
      if (success)
      {
         success = write(argv[2],x,y);
      }
   }
   return 0;
}

bool read(char* filename, int& x, int& y)
{
   bool success=true;
   ifstream ifs;
   ifs.open(filename);
   if (ifs.fail())
   {
      cerr << "error opening inputfile: '" 
           << filename << "' doesn't exist?\n";
      success=false;
   }
   else
   {
      ifs >> x >> y;
      ifs.close();
   }
   return success;
}

bool write(char* filename, int& x, int& y)
{
   bool success=true;
   ofstream ofs;
   ofs.open(filename);
   if (ofs.fail())
   {
      cerr << "error opening outputfile " << filename << endl;
      success=false;
   }
   else
   {
      ofs << "the sum of " << x << " and " << y
          << " is " << x+y << endl;
      ofs.close();
   }
   return success;
}
