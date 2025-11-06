#include "Graph.hpp"

using namespace std;

int main() {
  Graph G(10);
  G.addEdge(0,9);
  G.addEdge(4, 2);
  G.addEdge(0, 2);
  G.addEdge(2, 4);
  G.addEdge(9, 1);
  G.addEdge(9, 9);

  cout << G.numEdges() << endl << endl;

  cout << G.inDegree(9) << endl;
  cout << G.inDegree(2) << endl;
  cout << G.inDegree(4) << endl;
  cout << G.inDegree(1) << endl;
  cout << G.inDegree(0) << endl << endl;

  cout << G.isInfluencer(9) << endl;
  cout << G.isInfluencer(2) << endl;
  cout << G.isInfluencer(4) << endl;
  cout << G.isInfluencer(1) << endl << endl;

  G.print();
}
