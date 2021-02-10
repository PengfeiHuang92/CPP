// This program shows the use of argc and argv for getting file names
// from the command line.  The command line must consist of the name
// to execute the program followed by the name of the input
// file and the name of the output file.  If the command line is not
// in the proper form, or if an error occurred in opening a file, the
// appropriate error message is displayed.

// If everything works correctly, the program will simply read two
// ints from the input file and write the sum to the output file.

// This example passes opened file streams to functions

#include <iostream>
#include <fstream>
using namespace std;

// function prototypes
void write(ostream& f, int& x, int& y);
void read(istream& f, int& x, int& y);

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
      ifs.open(argv[1]);
      if (ifs.fail())
      {
         cerr << "error opening inputfile: '" 
            << argv[1] << "' doesn't exist?\n";
         success=false;
      }
      else
      {
         ofs.open(argv[2]);
         if (ofs.fail())
         {
            cerr << "error opening outputfile\n";
            success=false;
         }
      }
   }
   if (success)
   {
      read(ifs,x,y);
      write(ofs,x,y);
      ifs.close();
      ofs.close();
   }
   return 0;
}

void read(istream& f, int& x, int& y)
{
   f >> x >> y;
}

void write(ostream& f, int& x, int& y)
{
   f << "the sum of " << x << " and " << y;
   f << " is " << x+y << endl;
}
