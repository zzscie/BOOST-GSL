#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/graph/graph_traits.hpp>
#include <iostream>
#include <string>
#include <utility> // for std::pair
#include <vector>
using namespace std;
using namespace boost;
int main(int argc, char **argv) {
  typedef adjacency_list<vecS, vecS, bidirectionalS> Graph;
  enum { A, B, C, D, E, N }; // node in the graph
  const int num_vertices = 5;
  const vector<char> name = {'A', 'B', 'C', 'd', 'E'};
  typedef pair<int, int> Edge;
  vector<Edge> edge_arrary = {{A, B}, {A, D}, {C, A}, {D, C},
                              {C, E}, {B, D}, {D, E}};
  const int num_edges = sizeof(edge_arrary) / sizeof(edge_arrary[0]);
  Graph g{num_vertices};
  for (int i = 0; i < num_edges; i++) {
    add_edge(edge_arrary[i].first, edge_arrary[i].second, g);
  }
  return 0;
}
