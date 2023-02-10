#include <bits/stdc++.h>
#pragma once
using namespace std;

class food{
private:
  string name;
  int price;
  int amount;

public:
  food();
  food(string, int, int);
  string getName() const;
  int getPrice() const;
  int getAmount() const;
  void setName(string);
  void setAmount(int);
  void setPrice(int);
};
