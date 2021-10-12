#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <cstdlib>

#define NUM_FIELDS 4
struct SplitLine {
  std::string fields[NUM_FIELDS];
};

/* DONT MAKE ANY CHANGES ABOVE THIS LINE */

/* If you wish you can include any more files here.
   (from standard libraries only) */

std::map<std::string, int> processData(std::vector<struct SplitLine> data) {
        /* 
         * Modify this function to process `data` as indicated
         * in the question. At the end, return a map containing
         * the appropriate values
         *
         * Please create appropriate classes, and use appropriate
         * data structures as necessary.
         *
         * Do not print anything in this function.
         *
         * Note: the existing program is not intended to be an example
         * of good programming practice. (For example, struct
         * SplitLine is not a very good way to hold the data for this
         * problem.)  However, the code that *you* write will be
         * evaluated on the basis of the quality of the code, use of
         * appropriate classes/data-structures, comments, and
         * efficiency of the algorithm used.
         *
         * Submit this entire program (not just this function)
         * as your answer
         */
  std::map<std::string, int> answer;
  std::map<std::string, int> best;
  const int N = data.size();
  for (int i = 0; i < N; i++) {
	  std::string ID = data[i].fields[0];
	  int id = stoi(ID);
	  std::string name = data[i].fields[1];
	  std::string city = data[i].fields[2];
	  std::string VOTES = data[i].fields[3];
	  int votes = stoi(VOTES);
	  best[city] = std::max(best[city], votes);
  }
  for (int i = 0; i < N; i++) {
	  std::string ID = data[i].fields[0];
	  int id = stoi(ID);
	  std::string name = data[i].fields[1];
	  std::string city = data[i].fields[2];
	  std::string VOTES = data[i].fields[3];
	  int votes = stoi(VOTES);
	  if (best[city] == votes) {
		  answer[city] = id;
	  }
  }
  return answer;
}

/* DONT MAKE ANY CHANGES BELOW THIS LINE */

int main(void) {
  std::ifstream in("input.txt");
  std::vector<struct SplitLine> input_data;
  while (in) {
    struct SplitLine line;
    for (int i=0; i<NUM_FIELDS; i++) {
      if (i==NUM_FIELDS-1)
        std::getline(in, line.fields[i]);
      else
        std::getline(in, line.fields[i], ',');
    }
    if (line.fields[0] != "")
      input_data.push_back(line);
  }
  std::ofstream out("output.txt");
  std::map<std::string, int> ret_val = processData(input_data);
  for (std::map<std::string, int>::iterator it = ret_val.begin();
       it != ret_val.end();
       it++) {
    out << it->first << ": " << it->second << std::endl;
  }
  return 0;
}

