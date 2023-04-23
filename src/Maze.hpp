#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "Player.hpp"
#include <fstream>
#include <vector>
#include <random>
#include <limits>
#include <unistd.h>

#define RED_COLOR "\x1b[31;1m"
#define GREEN_COLOR "\x1b[32;1m"
#define NO_COLOR "\x1b[0;0m"

class Maze {
public:
  Player player;
  std::vector<char> mat;
  std::vector<bool> mat_visited;
  std::ifstream input_file;
  std::ofstream output_file;
  short mat_width, mat_height, mat_qty,
        mat_elements, current_mat;
  bool victory, have_items;

  Maze();
  virtual ~Maze();
  void set_start();
  void open_files(const std::string &in, const std::string &out);
  void write_sizes();
  void read(const bool &read_visited = true);
  void run();
  void action();
  void joystick();
  bool out_of_bounds(const short &move_x, const short &move_y);
  bool traped();
  void teleport();
  void write_matrix();
  void write_file(const bool &read_visited = true);
  void rewind();
  void random_start();
  void mat_have_item();
  bool only_zeros();
  void print();
};

#endif
