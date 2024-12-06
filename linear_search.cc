#include <iostream>
#include <vector>
#include <chrono>

void usage() {
   std::cerr << "usage: ./linear_search <set_length> <length>" << std::endl;
   std::cerr << "reads from stdin <set_lenght> rows formated as: x array[<length>]" << std::endl;
   std::cerr << "where \"x\" is a value in the array and \"array\" is an array with lenght <lenght>" << std::endl;
   exit(1);
}

void read_vector(std::vector<int> &v) {
   int n = v.size();
   for (int i = 0; i < n; ++i) std::cin >> v[i];
}

int linear_search(int x, const std::vector<int> &v) {
   int n = v.size();
   for (int i = 0; i < n; ++i) {
      if (v[i] == x) return i;
   }
   return -1; // never reached because precondition: x exists in v.
}

int main(int argc, char **argv) {
   if (argc != 3) usage();
   
   int set_length = atoi(argv[1]);
   int array_length = atoi(argv[2]);
   // mark start time
   for (int i = 0; i < set_length; ++i) {
      int x;
      std::cin >> x; // catch number to find.
      std::vector<int> v(array_length);
      read_vector(v);
      
      auto start = std::chrono::high_resolution_clock::now();
      linear_search(x, v);
      // mark end time
      auto end = std::chrono::high_resolution_clock::now();
      // calc delta.
      auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
      // print delta on stdout.
      std::cout << duration.count() << " ns elapsed" << std::endl;
   }
}