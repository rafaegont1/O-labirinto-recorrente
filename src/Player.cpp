#include "Player.hpp"

Player::Player()
  : x(0), y(0), lives(10), items(0), dist_covered(0), took_item(false) {}

Player::Player(short &x, short &y)
  : x(x), y(y), lives(10), items(0), dist_covered(0), took_item(false) {}

void Player::action(char &item) {
  if(item == '*') {
    --this->lives; 
  } else if(item != '0') {
    ++this->items;
    --item;
    this->took_item = true;
  }
  
  if(this->items == 4) {
    this->items = 0;
    if(this->lives < 10) ++this->lives;
  }
}

void Player::print() {
  std::cout << "Vidas: " << (lives < 10 ? "0" : "") << lives
            << "\tItens: " << items << '\n';
}

std::string Player::status() {
  return lives < 4 ? "\x1b[31;1m"
       : lives < 7 ? "\x1b[33;1m"
       : "\x1b[32;1m";
}

bool Player::is_alive() { return this->lives != 0; }

short Player::getX() { return this->x; }
short Player::getY() { return this->y; }
short Player::getLives() { return this->lives; }
short Player::getItems() { return this->items; }

//inline bool Player::notInBoundaries(const short &mat_sz) {
//  return (x == 0 && move_x == -1) || (x == mat_sz - 1 && move_x == 1) || (p.y == 0 && m.y == -1) || (p.y == mat_sz - 1 && m.y == 1);
//}
