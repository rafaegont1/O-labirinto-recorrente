#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "Player.hpp"
#include <fstream>
#include <vector>
#include <random>
#include <limits>
#include <unistd.h>

#define RED_COLOR "\x1b[31;1m"
#define NO_COLOR "\x1b[0;0m"
#define SLEEP_TIME 100000

class Maze {
public:
  Player player;
  std::vector<char> mat;
  std::ifstream input_file;
  std::ofstream output_file;
  short mat_width, mat_height, mat_qty, mat_elements, current_mat;
  bool took_item;

  Maze();
  virtual ~Maze();
  void check_eof();
  void set_start();
  void read();
  void write_file();
  void write_sizes();
  void write_matrix();
  void print_matrix();
  void rewind();
  void run();
  void random_start();
  void move(bool &victory);
  bool out_of_bounds(const short &move_x, const short &move_y);
  void dynamic_print();
  void open_files(const std::string &in, const std::string &out);
};

#endif
