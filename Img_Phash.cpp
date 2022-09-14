#include <dirent.h>
#include <fstream>
#include <iostream>
using namespace std;

std::ofstream Img_File;
string Img_ID, Img_Phash;

void List_Img (char* ImgPath)
{
  struct dirent *Entry;
  DIR *ImgDir = opendir (ImgPath);

  if (ImgDir != NULL)
    {
      while (Entry = readdir (ImgDir))
        {
          Img_File.open ("..//Test//Img_Phash_DB.csv", std::ios_base::app);
          Img_File << Entry->d_name << "\n";
          Img_File.close ();
        }
      closedir (ImgDir);
    }
  else
    cout << "\nDirectory Error !!!";
  cout << endl;
  cout << "\nCSV Successfully Created...";
}

int main ()
{
  List_Img ( (char*) "..//img//" );

  return 0;
}