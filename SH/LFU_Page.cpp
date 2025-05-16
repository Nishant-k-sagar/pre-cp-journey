#include <iostream>
#include <vector>
using namespace std;

class Page {
public:
  int id;
  int frequency;

  Page(int id, int frequency) {
    this->id = id;
    this->frequency = frequency;
  }
};

class LFU {
public:
  vector<Page> pages;
  int capacity;

  LFU(int capacity) {
    this->capacity = capacity;
  }

  void addPage(int id) {
    if (pages.size() < capacity) {
      pages.push_back(Page(id, 1));
    } else {
      // Find the page with the least frequency
      int leastFrequency = pages[0].frequency;
      int leastFrequencyIndex = 0;
      for (int i = 1; i < pages.size(); i++) {
        if (pages[i].frequency < leastFrequency) {
          leastFrequency = pages[i].frequency;
          leastFrequencyIndex = i;
        }
      }

      // Replace the page with the least frequency
      pages[leastFrequencyIndex] = Page(id, 1);
    }
  }

  void printPages() {
    for (int i = 0; i < pages.size(); i++) {
      cout << pages[i].id << " ";
    }
    cout << endl;
  }
};

int main() {
  LFU lfu(3);

  lfu.addPage(1);
  lfu.addPage(2);
  lfu.addPage(3);

  lfu.printPages(); // 1 2 3

  lfu.addPage(4);

  lfu.printPages(); // 1 3 4

  lfu.addPage(5);

  lfu.printPages(); // 3 4 5

  return 0;
}