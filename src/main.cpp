#include "Maze.hpp"

int main() {
  Maze maze;

  maze.run();

  return 0;
}

//int main() {
//  std::ifstream file("./dataset/input.data");
//
//  int x,y,z,xy;
//  char c;
//  std::vector<char> mat;
//
//  file >> x >> y >> z;
//  std::cout << x << ' ' << y << ' ' << z << '\n';
//  xy = x * y;
//  mat.resize(xy);
//
//  for(int k = 0; k < 3; k++) {
//    for(int i = 0; i < xy; i++) {
//      file >> mat[i];
//    }
//    for(int i = 0; i < y; i++) {
//      for(int j = 0; j < x; j++) {
//        std::cout << mat[x * i + j] << ' ';
//      }
//      std::cout << '\n';
//    }
//    std::cout << std::endl;
//  }
//  std::cout << "EOF=" << file.eof() << '\n';
//  file >> c;
//  std::cout << c << std::endl;
//  //    std::string str;
//  //    getline(file, str);
//  //    std::cout << str;
//  std::cout << "EOF=" << file.eof() << '\n';
//
//  return 0;
//}
