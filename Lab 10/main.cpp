#include <cstring>
#include "Graph.h"
using namespace std;

int main() {
  ifstream ifs("input3.dms");
  if(!ifs) {
    cerr << "Input file not found." << endl;
    exit(1);
  }
  
  Graph g(ifs);
  ifs.close();
  g.bfs();
  string filename = "input1.dot";
  g.output_graph(filename);
  cout << "The End." << endl;
  
  return 0;
}
