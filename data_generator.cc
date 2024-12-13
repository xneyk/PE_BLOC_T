#include <iostream>
#include <vector>
#include <algorithm>

#define _MAX_LENGTH_ 65536;

void usage() {
   std::cerr << "./data_generator <set_length>" << std::endl;
   std::cerr << "Generates <set_length> rows. Each row follows [x n array]" << std::endl;
   std::cerr << "where \"x\" is a value in the array and \"array\" is n length" << std::endl;
   exit(1);
}

/**
 * Each value of v is set to a random value.
*/
void generate_random_vector(std::vector<int> &v) {
   int n = v.size();
   
   for (int i = 0; i < n; ++i) {
      v[i] = std::rand();
   }
}

/**
 * Prints a row at stdout.
 * Row Example:   7  4  1  4  7  8
 *                x  n  v0 v1 v2 v3
*/
void print_row(int x, int n, std::vector<int> v) {
   std::cout << x << ' ' << n << ' ';
   for (int i = 0; i < n; ++i) {
      std::cout << v[i];
      if (i+1 != n) std::cout << ' '; // if is not the last iteration add separator.
   }
   std::cout << std::endl;
}

int main(int argc, char **argv) {
   if (argc != 2) usage();
   std::srand(std::time(0)); // change the seed of rand() depending on TIMESTAMP.
   unsigned int set_length = atoi(argv[1]);

   for (unsigned int i = 0; i < set_length; ++i) { // each row we need to generate;
      int n = rand()%_MAX_LENGTH_; // random vector length.
      std::vector<int> v(n);
      
      generate_random_vector(v);
      
      int x_index = rand()%n; // index of the value choosen for this row
      int x = v[x_index];

      print_row(x, n, v);
   }
}