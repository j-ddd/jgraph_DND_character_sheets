#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

int main(void)
{
   string line, name;
   int lineCount = 0;
   
   // read input file
   // 1st line is the name
   getline(cin, line);
   name = line;
   
   //while (getline(cin, line); && !line.empty());
   //{
      // increment line counter
   //   lineCount = lineCount+1;

      // line 1 is the character name, prefix is "Name: ", so the first 6 chars.
    //  if(str.compare(0, 6, "Name: ") == 0) 
   //   { 
    //     line.erase(0, 6);
   //      name = line; 
   //   }
   //}

   // -- GRAPH/Character Sheet GENERATION --
   int plot_start = -100;
   int head_space = 0;

   // make the graph
   int xmax, ymax, xmin, ymin;
   xmin = 0;
   ymin = 0;
   ymax = 100;
   xmax = 100;
   cout << "newgraph" << endl;
   cout << "xaxis min " << xmin << " max " << xmax << " nodraw" << endl;
   cout << "yaxis min " << ymin << " max " << ymax << " nodraw" << endl;

   // put name on sheet
   // name: on line after name box gets put up
   printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
           14,
           -100,
           100);
   printf("%s\n", name.c_str());

   // print out name, background, class, species, and subclass box.
   //cout << "./symbols/name_box" << endl;

   
   return 0;
}
