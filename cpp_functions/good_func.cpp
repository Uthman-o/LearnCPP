#include <iostream>
#include <vector>

using namespace std;

vector<int> CreateVectorOfZeros(int size) {
  vector<int> null_vector(size);
  for (int i = 0; i < size; ++i) {
    null_vector[i] = i;
  }
  return null_vector;
}

void PrintVector(vector<int> vec) {
  for (int value : vec) {
    cout << "Element " << value << endl;
  }
}

int main() {
  std::vector<int> zeros = CreateVectorOfZeros(10);
  PrintVector(zeros);

  return 0;
}
