#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

// const char *LANGUAGES[3] = {"C++", "Python", "Java"};

void usage() {
   std::cerr << "./program_tester <set_name> <set_lenght> <length> " << std::endl;
   std::cerr << "<set_name> is the file name where the data is" << std::endl;
   std::cerr << "<set_length> is the number of rows the set has" << std::endl;
   std::cerr << "<length> is the vector length of the rows (rows are x v1 v2 ... vn)" << std::endl;
   exit(1);
}

void mix_vector(std::vector<std::string> &v) {
   int n = v.size();
   std::srand(std::time(0)); // change the seed of rand() depending on TIMESTAMP.
   for (int i = 0; i < n; ++i) {
      std::swap(v[i], v[rand()%n]);
   }
}

int main(int argc, char **argv) {
   if (argc != 4) usage();
   int set_lenght = atoi(argv[2]);
   int length = atoi(argv[3]);
   
   std::vector<std::string> languages = {"java", "python", "c++"};
   mix_vector(languages);
   char exec_cmd[256];
   for (std::string language : languages) {
      if (language == "java") {
         // java execution
         // std::cout << "[program_tester] getting JAVA program data from " << argv[1] << std::endl;
         
         // sprintf(exec_cmd, "java linear_search %d %d < %s > java_time_%s", set_lenght, length, argv[1], argv[1]);
         // system(exec_cmd);

         // std::cout << "[program_tester] JAVA program data from " << argv[1] << " obtained" << std::endl;
      } else if (language == "python") {
         // python execution
         std::cout << "[program_tester] getting PYTHON program data from " << argv[1] << std::endl;

         sprintf(exec_cmd, "python3 linear_search.py %d %d < %s > py_time_%s", set_lenght, length, argv[1], argv[1]);
         system(exec_cmd);
         
         std::cout << "[program_tester] PYTHON program data from " << argv[1] << " obtained" << std::endl;
      } else if (language == "c++") {
         // c++ execution
         std::cout << "[program_tester] getting C++ program data from " << argv[1] << std::endl;

         sprintf(exec_cmd, "./linear_search.x %d %d < %s > cc_time_%s", set_lenght, length, argv[1], argv[1]);
         system(exec_cmd);
         
         std::cout << "[program_tester] C++ program data from " << argv[1] << " obtained" << std::endl;
      }
   }
}