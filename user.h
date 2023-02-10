#include <bits/stdc++.h>
// #include "food.h"
#include "food.cpp"
#pragma once
using namespace std;

class User{
private:
  string name;
  string username;
  string email;
  string password;
  int age;
  char gender;
  int id;
  int creditCard;
  vector<food *> FoodReserve;

public:
  static int counter;
  User();
  User(string,string, string, string, int,int, char);
  int getID()const;
  int getCredit() const;
  void setCredit(int);
  string getUserName() const;
  string getPassword() const;
  bool bayFood(food*);
  void PrintAll() const;
  friend istream &operator>>(istream &, User &);
  friend ostream &operator<<(ostream &, User);
};