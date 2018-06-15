#include <iostream>
#include <list>
#include <string>
#include <time.h>
#include <vector>
using namespace std;
class Expire {
public:
  Expire() : sum(0), mean(0), thresold(100){};
  void record(int value);
  void clean(time_t t);
  int getMean();
  void Print() {
    int count = 0;
    for (auto it = cont.begin(); it != cont.end(); it++) {
      cout << it->first << " ";
      count++;
      if (count == 10) {
        count = 0;
        cout << "\n";
      }
    }
    cout << endl;
  }
  vector<int> getMedium();

private:
  list<pair<int, time_t>> cont;
  int partition(list<pair<int, time_t>> cont, int index) {
    int v = cont.back().first;
    int count = 0;
    list<pair<int, time_t>> left;
    list<pair<int, time_t>> right;
    for (auto it = cont.begin(); it != cont.end(); it++) {
      if (it->first < v) {
        left.push_back(*it);
        count++;
      } else {
        right.push_back(*it);
      }
    }
    if (index > count) {
      return partition(right, index - count - 1);
    } else if (index == count) {
      return v;
    } else {
      return partition(left, count);
    }
  };
  long long int sum;
  double mean;
  int thresold;
};
void Expire::record(int value) {
  time_t now = time(nullptr);
  clean(now);
  cont.push_back({value, now});
  sum += value;
  return;
}
void Expire::clean(time_t t) {
  for (auto it = cont.begin(); it != cont.end(); it++) {
    if (t - it->second > thresold) {
      int v = it->first;
      sum = sum - v;
      cont.pop_front();
    }
  }
  return;
}
int Expire::getMean() {
  int nsize = cont.size();
  mean = (double)sum / nsize;
  return mean;
}
vector<int> Expire::getMedium() {
  clean(time(nullptr));
  int nsize = cont.size();
  vector<int> res;
  if (nsize % 2 == 1) {
    res.push_back(partition(cont, nsize / 2));
    return res;
  } else {
    res.push_back(partition(cont, nsize / 2));
    res.push_back(partition(cont, nsize / 2 + 1));
    return res;
  }
}

int main(int argc, char **argv) {
  Expire k;
  for (int i = 0; i < 100; i++) {
    int v = rand();
    k.record(v);
  }
  vector<int> medi;
  medi = k.getMedium();
  for (auto it = medi.begin(); it != medi.end(); it++) {
    cout << "medium "
         << " O ( N )" << *it << " ";
  }
  cout << k.getMean() << endl;
  k.Print();
}
