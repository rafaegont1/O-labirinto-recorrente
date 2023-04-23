#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>

typedef struct move Move;

class Player {
public:
  short x, y, lives, items, dist_covered,
        items_consumed, visited_qty, dangers;
  bool took_item, teleport;

  Player();

  void action(char &item);
  void print();
  std::string status();
  bool is_alive();
};

#endif
