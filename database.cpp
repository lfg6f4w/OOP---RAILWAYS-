#include <bits/stdc++.h>
#include "train.h"
#include "user.h"
#include "train.cpp"
#include "user.cpp"
// #include "food.h"
// #include "food.cpp"
#pragma once
using namespace std;
vector<string> stations = {"Aswan", "Luxor", "Qena", "Sohag", "Asyut", "Bani Sweif", "Minya", "Cairo", "Alexandria"};
vector<string> meals = {"Macaroni", "Meat", "Chicken", "Rice", "Sandwich", "Coca_Cola", "Pepsi", "ًWaters"};
int Price[] = {55, 70, 70, 30, 25, 10, 10, 10};
vector<string> destinations = stations;
vector<Train *> trains;
vector<food> foods;
User userAdmin("admin","admin", "admin@gmail.com", "admin", 0, 0, 0);
vector<User *> users = {&userAdmin};
void createTrains()
{
  for (int i = 0; i < 9; i++)
  {
    stringstream name;
    name << "Egy-";
    for (int j = i + 1; j < 9; j++)
    {
        Train tr;
        tr.setName(name.str());
        name << (i + 100 + j);
        tr.setStation(stations[i]);
        tr.setDestination(destinations[j]);
        stringstream date, tim, dur;
        srand((unsigned)time(0) + j + i + 3);
        date << (rand() % 30 + j) << '-' << rand() % 12 << "-2023";
        tim << ((rand() % 12) + j + i)<< ':' << rand() % 59;
        dur << (j - i + 5) * 2;
        tr.setDate(date.str());
        tr.setTime(tim.str());
        tr.setDuration(dur.str());
        tr.setPriceA((i + 1) * 5 + (j + 1) * 50);
        tr.setPriceB((i + 1) * 5 + (j + 1) * 100);
        tr.setPriceC((i + 1) * 5 + (j + 1) * 200);
        trains.push_back(&tr);
        // tr.PaintAll();
    }
  }
}
void CreateFood(){
  for (int i = 0; i < 8;i++)
  {
    food f;
    f.setName(meals[i]);
    f.setAmount(floor(rand() % 20) + 1);
    f.setPrice(Price[i]);
    foods.push_back(f);
  }
}
Train *findTrain(int num)
{
  for (int i = 0; i < trains.size(); i++)
  {
    if (trains[i]->getNum() == num)
    {
      return trains[i];
    }
  }
  return nullptr;
}
User *findUser(string username, string password)
{
  for (User *i : users)
  {
    if (i->getUserName() == username && i->getPassword() == password)
    {
      return i;
    }
  }
  return nullptr;
}
bool IsUser(string name,string password){
  for (int i = 0; i < users.size();i++){
    if(users[i]->getUserName() == name && users[i]->getPassword() == password)
      return true;
  }
  return false;
}
void Print(Train *t){
  for (int i = 0; i < t->getNumOfPassengers();i++){
    t->getPassenger(i)->passenger->PrintAll();
  }
}

void PrintFood(){
  for (int i = 0; i < foods.size();i++)
      cout << foods[i].getName() << ' ' << foods[i].getAmount() << ' ' << foods[i].getPrice() << '\n';
}