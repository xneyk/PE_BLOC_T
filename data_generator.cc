#include <iostream>
#include <vector>
#include <algorithm>

void usage() {
   std::cout << "./data_generator <set_length> <length>" << std::endl;
   std::cout << "Generates <set_length> rows. Each row follows [x array]" << std::endl;
   std::cout << "where \"x\" is a value in the array and \"array\" is an array sorted in increasing order of integers with lenght <lenght>" << std::endl;
   exit(1);
}

/**
 * Each value of v is set to a random value.
*/
void generate_random_vector(std::vector<int> &v) {
   int n = v.size();
   
   for (int i = 0; i < n; ++i) {
      v[i] = std::rand()%256;
   }
}

/**
 * Prints a row at stdout.
 * Row Example:   4  1  4  7  8
 *                x  v0 v1 v2 v3
*/
void print_row(int x, std::vector<int> v) {
   int n = v.size();

   std::cout << x << ' ';
   for (int i = 0; i < n; ++i) {
      std::cout << v[i];
      if (i+1 != n) std::cout << ' '; // if is not the last iteration add separator.
   }
   std::cout << std::endl;
}

int main(int argc, char **argv) {
   if (argc != 3) usage();
   std::srand(std::time(0)); // change the seed of rand() depending on TIMESTAMP.

   unsigned int set_length = atoi(argv[1]);
   unsigned int vector_lenght = atoi(argv[2]);

   for (unsigned int i = 0; i < set_length; ++i) { // each row we need to generate;
      std::vector<int> v(vector_lenght);
      
      generate_random_vector(v);
      
      int x_index = rand()%vector_lenght; // index of the value choosen for this row
      int x = v[x_index];

      // array sorted in increasing order.
      std::sort(v.begin(), v.end());

      print_row(x, v);
   }
}