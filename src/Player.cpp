#include "Player.hpp"

using std::cin;
using std::cout;
using std::endl;

Player::Player()
  : x(0), y(0), lives(10), items(0), dist_covered(0),
  items_consumed(0), visited_qty(0), dangers(0),
  took_item(false), teleport(false) {}

void Player::action(char &item) {
  if(item == '*') {
    --this->lives; 
    ++this->dangers;
  } else if(item != '0') {
    ++this->items;
    ++this->items_consumed;
    --item;
    this->took_item = true;
  }
  
  if(this->items == 4) {
    this->items = 0;
    if(this->lives < 10) ++this->lives;
  }
}

void Player::print() {
  cout << "Vidas: " << (lives < 10 ? "0" : "") << lives
       << "\tItens: " << items << '\n';
}

std::string Player::status() {
  return lives < 4 ? "\x1b[31;1m"
       : lives < 7 ? "\x1b[33;1m"
       : "\x1b[32;1m";
}

bool Player::is_alive() { return this->lives != 0; }
