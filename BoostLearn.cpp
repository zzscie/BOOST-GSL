#include <boost/foreach.hpp>
#include <boost/range/algorithm.hpp>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main(int argc, char *argv[]) {
  vector<int> data;

  data.push_back(1);
  data.push_back(2);
  data.push_back(4);
  data.push_back(6);
  data.push_back(46);
  data.push_back(21);
  data.push_back(645);
  data.push_back(132);
  data.push_back(423);
  data.push_back(230);
  cout << "Before sort" << endl;
  BOOST_FOREACH (int x, data) { cout << x << " "; }
  cout << endl;
  boost::sort(data);
  cout << "After boost sort" << endl;
  BOOST_FOREACH (int x, data) { cout << x << " "; }
}
