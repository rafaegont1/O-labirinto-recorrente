#include "Maze.hpp"

using std::cin;
using std::cout;
using std::endl;

Maze::Maze() : current_mat(0), victory(false), have_items(false) {
  open_files("./dataset/input.data", "./dataset/tmp.data");

  input_file >> mat_width
             >> mat_height
             >> mat_qty;

  write_sizes();
  mat_elements = mat_width * mat_height;
  mat.resize(mat_elements);
  mat_visited.resize(mat_elements);
  read(false);
  write_file(false);
  current_mat = 0;
  input_file.close();
  output_file.close();
  open_files("./dataset/output.data", "./dataset/tmp.data");
  write_sizes();
  input_file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  read();
}

Maze::~Maze() {
  input_file.close();
  output_file.close();
}

void Maze::set_start() {
  cout << "Digite a posição inicial (x y): ";
  while (!(cin >> player.x >> player.y)
      || player.x < 0 || player.x >= mat_width
      || player.y < 0 || player.y >= mat_height
      || mat[player.x + player.y * mat_width] == '#') {
    cout << "Posição inválida. Tente novamente: ";
  }
}

void Maze::open_files(const std::string &in,
                      const std::string &out) {
  input_file.open(in);
  output_file.open(out);

  if(!input_file.is_open()) {
    std::cerr << RED_COLOR
              << "Erro ao tentar abrir o arquivo "
              << in << NO_COLOR << endl;
    exit(EXIT_FAILURE);
  }
  if(!output_file.is_open()) {
    std::cerr << RED_COLOR
              << "Erro ao tentar abrir o arquivo "
              << out << NO_COLOR << endl;
    exit(EXIT_FAILURE);
  }
}

void Maze::write_sizes() {
  output_file << mat_width  << ' '
              << mat_height << ' '
              << mat_qty    << '\n';
}

void Maze::read(const bool &read_mat_visited) {
  if(!read_mat_visited) {
    for(short i = 0; i < mat_height; i++) {
      for(short j = 0; j < mat_width; j++) {
        input_file >> mat[mat_width * i + j];
      }
    }
    return;
  }

  char c;

  for(short i = 0; i < mat_height; i++) {
    for(short j = 0; j < mat_width; j++) {
      input_file >> mat[mat_width * i + j];
    }
    for(short j = 0; j < mat_width; j++) {
      input_file >> c;
      mat_visited[mat_width * i + j] = (c == '1');
    }
  }
}

void Maze::run() {
  action();

  while(player.is_alive() && !victory && !only_zeros()) {
    joystick();
    if(player.teleport) teleport();
    action();
  }

  write_file();
  print();
}

void Maze::action() {
  player.action(mat[player.x
                  + player.y * mat_width]);
  if(!mat_visited[mat_width * player.y + player.x]) {
    ++player.visited_qty;
    mat_visited[mat_width * player.y + player.x] = true;
  }
}

void Maze::joystick() {
  short move_x, move_y;
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<short> dist(-1, 1);

  do {
    move_x = player.x + dist(mt);
    move_y = player.y + dist(mt);
  } while(!(player.teleport = out_of_bounds(move_x, move_y))
       && mat[move_x + move_y * mat_width] == '#');

  if(player.x != move_x || player.y != move_y) ++player.dist_covered;

  player.x = move_x;
  player.y = move_y;
}

bool Maze::out_of_bounds(const short &move_x, const short &move_y) {
  return move_x < 0
      || move_x == mat_width
      || move_y < 0
      || move_y == mat_height;
}

void Maze::teleport() {
    if(current_mat + 1 == mat_qty) {
      if(player.took_item) rewind();
      else victory = true;
    } else {
      write_matrix();
      mat_have_item();
      read();
    }
    random_start();
    player.teleport = false;
}

void Maze::write_matrix() {
  for(short i = 0; i < mat_height; i++) {
    for(short j = 0; j < mat_width; j++) {
      output_file << mat[mat_width * i + j] << ' ';
    }
    for(short j = 0; j < mat_width; j++) {
      output_file << mat_visited[mat_width * i + j] << ' ';
    }
    output_file << '\n';
  }
  output_file << '\n';
  ++current_mat;
}

void Maze::write_file(const bool &read_mat_visited) {
  write_matrix();

  while(current_mat < mat_qty) {
    read(read_mat_visited);
    write_matrix();
  }

  rename("./dataset/tmp.data", "./dataset/output.data");
}

void Maze::rewind() {
  have_items = false;
  write_matrix();
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

void Maze::random_start() {
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<short> dist1(0, mat_width - 1), dist2(0, mat_height - 1);

  do {
    player.x = dist1(mt);
    player.y = dist2(mt);
  } while(mat[player.x + player.y * mat_width] == '#');
}

void Maze::mat_have_item() {
  for(short i = 0; i < mat_elements; i++) {
    if(mat[i] >= '1' && mat[i] <= '9') {
      have_items = true;
      return;
    }
  }
}

bool Maze::only_zeros() {
  if(have_items) return false;

  std::ifstream check_file("./dataset/output.data");
  char c;

  check_file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  for(short i = 0; i < (mat_height + 1) * current_mat; i++) {
    check_file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  for(short k = current_mat + 1; k < mat_qty; k++) {
    for(short i = 0; i < mat_height; i++) {
      for(short j = 0; j < mat_height; j++) {
        check_file >> c;
        if(c >= '1' && c <= '9') {
          return false;
        }
      }
      check_file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }
  victory = true;
  return true;
}

void Maze::print() {
  cout << (victory ? GREEN_COLOR "Vitória!\n" : RED_COLOR "Derrota\n")
       << NO_COLOR "Total de casas percorridas: "
       << player.dist_covered
       << "\nItens consumidos: "
       << player.items_consumed
       << "\nCasas inexploradas: "
       << mat_qty * mat_elements - player.visited_qty
       << "\nPerigos enfrentados: "
       << player.dangers
       << endl;
}
