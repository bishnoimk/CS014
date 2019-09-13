#include <cstring>
#include "Graph.h"
using namespace std;

int main() {
  string fileName;
  cout << "Enter a file name: ";
  cin >> fileName;
  
  ifstream ifs(fileName);
  if(!ifs) {
    cerr << "Input file not found." << endl;
    exit(1);
  }
  
  Graph g(ifs);
  ifs.close();
  g.bfs();
  string filename = "input.dot";
  g.output_graph(filename);
  cout << "The End." << endl;
  
  return 0;
}
