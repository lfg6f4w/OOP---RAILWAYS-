#include "food.h"

food::food() : food("", 0, 0){}
food::food(string name, int price, int amount) : name(name), price(price), amount(amount){}

string food::getName()const{
  return this->name;
}
int food::getAmount()const{
  return this->amount;
}
int food::getPrice()const{
  return this->price;
}
void food::setName(string name){
  this->name = name;
}
void food::setAmount(int amount){
  this->amount = amount;
}
void food::setPrice(int price){
  this->price = price;
}