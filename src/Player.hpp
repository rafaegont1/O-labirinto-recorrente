#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>

typedef struct move Move;

class Player {
public:
  short x, y, lives, items;
  bool victory;

  Player();
  Player(short &x, short &y);

  void action(char &item);
  void print();
  std::string status();
  bool is_alive();

  short getX();
  short getY();
  short getLives();
  short getItems();
};

#endif
