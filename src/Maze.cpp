#include "Maze.hpp"

Maze::Maze() {
  open_files("./dataset/input.data", "./dataset/tmp.data");

  input_file >> this->mat_width
             >> this->mat_height
             >> this->mat_qty;

  write_sizes();
  this->mat_elements = this->mat_width * this->mat_height;
  mat.resize(this->mat_elements);
  read();
}

Maze::~Maze() {
  this->input_file.close();
  this->output_file.close();
}

void Maze::set_start() {
  std::cout << "Digite a posição inicial (x y): ";
  while (!(std::cin >> this->player.x >> this->player.y)
      || this->player.x < 0 || this->player.x >= mat_width
      || this->player.y < 0 || this->player.y >= mat_height
      || mat[this->player.x + this->player.y * mat_width] == '#') {
    std::cout << "Posição inválida. Tente novamente: ";
  }
}

void Maze::read() {
  for(short i = 0; i < mat_elements; i++) {
    input_file >> this->mat[i];
  }
}

void Maze::write_file() {
  write_matrix();

  while(++current_mat < mat_qty) {
    read();
    write_matrix();
  }

  rename("./dataset/tmp.data", "./dataset/output.data");
}

void Maze::write_sizes() {
  output_file << this->mat_width  << ' '
              << this->mat_height << ' '
              << this->mat_qty    << '\n';
}

void Maze::write_matrix() {
  for(short i = 0; i < mat_height; i++) {
    for(short j = 0; j < mat_width; j++) {
      output_file << this->mat[mat_width * i + j] << ' ';
    }
    output_file << '\n';
  }
  output_file << '\n';
}

void Maze::run() {
  bool victory = false;

  current_mat = 0;
  dynamic_print();
  usleep(SLEEP_TIME);

  while(this->player.is_alive() && !victory) {
    move(victory);
    player.action(mat[player.x +
                      player.y * mat_width]);
    dynamic_print();
    usleep(SLEEP_TIME);
  }

  std::cout << "\x1b[" << mat_height + 2 << 'E'
            << (victory ? "Vitória!\n" : "Derrota\n")
            << "N° de casas percorridas: "
            << player.dist_covered
            << std::endl;

  write_file();
}

void Maze::move(bool &victory) {
  short move_x, move_y;
  bool teleport = false;
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<short> dist(-1, 1);

  do {
    move_x = player.x + dist(mt);
    move_y = player.y + dist(mt);
  } while(!(teleport = out_of_bounds(move_x, move_y)) &&
          mat[move_x + move_y * mat_width] == '#');

  if(teleport) {
    write_matrix();
    if(current_mat == mat_qty) {
      if(!player.took_item) victory = true;
      else rewind();
    } else {
      read();
      ++current_mat;
    }
    random_start();
  } else {
    this->player.x = move_x;
    this->player.y = move_y;
  }

  ++player.dist_covered;
}

void Maze::rewind() {
  //std::cout << "Rewinding..." << std::endl; // scribble
  input_file.close();
  output_file.close();

  rename("./dataset/tmp.data", "./dataset/output.data");
  open_files("./dataset/output.data", "./dataset/tmp.data");
  input_file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  read();
  write_sizes();
  current_mat = 0;
  player.took_item = false;
}

void Maze::print_matrix() {
  for(short i = 0; i < mat_height; i++) {
    for(short j = 0; j < mat_width; j++) {
      std::cout << mat[mat_width * i + j] << ' ';
    }
    std::cout << '\n';
  }
  std::cout << std::endl;
}

void Maze::random_start() {
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<short> dist1(0, this->mat_width - 1), dist2(0, this->mat_height - 1);

  do {
    this->player.x = dist1(mt);
    this->player.y = dist2(mt);
  } while(mat[this->player.x + this->player.y * mat_width] == '#');
}

bool Maze::out_of_bounds(const short &move_x, const short &move_y) {
  return move_x < 0
      || move_x == mat_width
      || move_y < 0
      || move_y == mat_height;
}

void Maze::dynamic_print() {
  player.print();
  for(short i = 0; i < mat_height; i++) {
    for(short j = 0; j < mat_width; j++) {
      if(player.x == j && player.y == i) {
        std::cout << player.status()
                  << mat[mat_width * i + j]
                  << "\x1b[0;0m ";
      } else {
        std::cout << mat[mat_width * i + j] << ' ';
      }
    }
    std::cout << '\n';
  }
  std::cout << std::endl
            << "\x7\x1b[" << mat_height + 2 << 'F';
}

void Maze::open_files(const std::string &in, const std::string &out) {
  input_file.open(in);
  output_file.open(out);

  if(!input_file.is_open()) {
    std::cerr << RED_COLOR
                 "Erro ao tentar abrir o arquivo "
              << in 
              << NO_COLOR
              << std::endl;
    exit(EXIT_FAILURE);
  }
  if(!output_file.is_open()) {
    std::cerr << RED_COLOR
                 "Erro ao tentar abrir o arquivo "
              << out
              << NO_COLOR
              << std::endl;
    exit(EXIT_FAILURE);
  }
}
