#include <bits/stdc++.h>
#include "database.cpp"
using namespace std;
void UserModel();
void BookTrain();
void TicketCost();
void Cancel();
void Food();
void AdminModel();
void DataBase();
void Interface()
{
  cout << "____________________________________\n";
  cout << "______WELCOME TO QENA RAILWAYS______\n";
  cout << "    |\t   1. Admin Mode   \t|\n";
  cout << "    |\t   2. User Mode    \t|\n";
  cout << "    |\t   3. Exit Mode    \t|\n";
  cout << "------------------------------------\n";
  int select;
  cout << "Select: ";
  cin >> select;
  switch (select)
  {
  case 1:
  {
    string name;
    string password;
    cout << "Enter UserName: ";
    cin >> name;
    cout << "Enter Password: ";
    if (!IsUser(name, password))
    {
      cout << "UserName or password is wrong\n";
      return Interface();
    }
    AdminModel();
  }
  break;
  case 2:
  {
    string name;
    string password;
    cout << "Enter UserName: ";
    cin >> name;
    cout << "Enter Password: ";
    if (!IsUser(name, password))
    {
      cout << "UserName or password is wrong\n";
      return Interface();
    }
    UserModel();
  }
    break;
  default:
    exit(1);
  }
  return;
}
void UserModel()
{
  cout << "____________________________________\n";
  cout << "_____________USER  MENU_____________\n";
  cout << "    |      1. Book Train      |\n";
  cout << "    |      2. Ticket Cost     |\n";
  cout << "    |      3. Cancel Ticket   |\n";
  cout << "    |      4. Food            |\n";
  cout << "    |      5. Exit            |\n";
  cout << "------------------------------------\n";
  int select;
  cout << "Select: ";
  cin >> select;
  switch (select)
  {
  case 1:
    BookTrain();
    break;
  case 2:
    TicketCost();
    break;
  case 3:
    Cancel();
    break;
  case 4:
    Food();
    break;
  default:
    exit(1);
  }
  return Interface();
}
void BookTrain()
{
  cout << "\nPlease choose station: \n";
  for (int i = 1; i <= 9; i++)
    cout << i << ". " << stations[i - 1] << "  "
         << " \n"[i % 3 == 0];
  int select1, select2, select3;
  char select4;
  cin >> select1;
  for (int i = 1; i <= 9; i++)
    cout << i << ". " << destinations[i - 1] << "  "
         << " \n"[i % 3 == 0];
  cin >> select2;
  vector<Train *> ts;
  for (auto i : trains)
  {
    if (i->getStation() == stations[select1 - 1] && i->getDestination() == destinations[select2 - 1])
      ts.push_back(i);
  }
  for (int i = 0; i < ts.size(); i++)
  {
    int x = ts[i]->getNumOfPassengers();
    int z = ts[i]->getCapacity();
    if (x < z)
      cout << i + 1 << ". " << *ts[i] << '\n';
  }
  cout << "Choose Number of Train: ";
  cin >> select3;
  cout << "Choose Class of train: ";
  cin >> select4;
  Train *TrainChosen = ts[select3 - 1];
  cout << "Enter Number of Passengers: ";
  // do try and catch of errors
  int num, ok = 0;
  cin >> num;
  while (num--)
  {
    User user;
    cin >> user;
    if (!TrainChosen->AddPassenger(&user, tolower(select4)))
    {
      ok++;
      cout << "The Train completed the maximum number of Passengers.\n";
    }
  }
  if (ok)
  {
    cout << "The reservation is complete, and it remains only to pay the mony within an hour from now, otherwise the reservation will be canceled immediately.\n";
    cout << "Please save number of train in order to know the payment of money\n";
    cout << "Number of Train: " << TrainChosen->getNum() << '\n';
  }
  return UserModel();
}
void TicketCost()
{
  string username, password;
  int trainNum;
  cout << "Fill in the following data: \n";
  cout << "1. UserName: ";
  cin >> username;
  cout << "2. Password: ";
  cin >> password;
  cout << "3. Train no: ";
  cin >> trainNum;
  Train *TrainChosen = findTrain(trainNum);
  if (TrainChosen == nullptr)
  {
    cout << "Error no of train is wrong\n";
    return UserModel();
  }
  User *user = findUser(username, password);
  if (user == nullptr)
  {
    cout << "Error not found the user\n";
    return UserModel();
  }
  Passengers *passenger = TrainChosen->findPassenger(user);
  if (passenger == nullptr)
  {
    cout << "Unfortunately, This User has not been booked on this train.\nPlease try to register first\n";
    return UserModel();
  }
  if (TrainChosen->PayMoney(passenger))
  {
    cout << "Successful Process. (( Happy Trip )) \n";
    return UserModel();
  }
  else
  {
    cout << "NOT HAVE ENOUGH MONEY\n";
    return UserModel();
  }
}
void Cancel()
{
  string username, password;
  int trainNum;
  cout << "Fill in the following data: \n";
  cout << "1. UserName: ";
  cin >> username;
  cout << "2. Password: ";
  cin >> password;
  cout << "3. Train no: ";
  cin >> trainNum;
  Train *TrainChosen = findTrain(trainNum);
  if (TrainChosen == nullptr)
  {
    cout << "Error no of train is wrong\n";
    return UserModel();
  }
  User *user = findUser(username, password);
  if (user == nullptr)
  {
    cout << "Error not found the user\n";
    return UserModel();
  }
  Passengers *passenger = TrainChosen->findPassenger(user);
  if (passenger == nullptr)
  {
    cout << "Unfortunately, This User has not been booked on this train.\nPlease try to register first\n";
    return UserModel();
  }
  TrainChosen->CancelTicket(passenger);
  return UserModel();
}
void Food()
{
  string no = "37372252";
  cout << "____________________________________\n"
       << "_____________FOOD MENU______________\n"
       << "|S.no.    |Item Name(AM) |Price    |\n";
  for (int i = 0; i < foods.size(); i++)
  {
    cout << "|" << i + 1 << ".       |"
         << foods[i].getName() << " ("
         << foods[i].getAmount() << ")"
         << setw(no[i] - '0') << "|"
         << foods[i].getPrice()
         << "       |\n";
  }
  cout << "------------------------------------\n";
  cout << "Please Enter Your UserName: ";
  string name;
  cin >> name;
  cout << "Please Enter Your Password: ";
  string password;
  cin >> password;
  cout << "Enter no of Food: ";
  int select;
  cin >> select;
  User *user = findUser(name, password);
  if (!user)
  {
    cout << "Sorry, but not found the username\n";
  }
  else
  {
    if (user->bayFood(&foods[select - 1]))
    {
      cout << "Successful Process\n";
    }
    cout << "You Don't have enough money\n";
  }
  return UserModel();
}
void AdminModel()
{
  cout << "____________________________________\n";
  cout << "_____________ADMIN  MENU_____________\n";
  cout << "    |      1. Book Train      |\n";
  cout << "    |      2. Ticket Cost     |\n";
  cout << "    |      3. Cancel Ticket   |\n";
  cout << "    |      4. Food            |\n";
  cout << "    |      5. Data Base       |\n";
  cout << "    |      6. Exit            |\n";
  cout << "------------------------------------\n";
  int select;
  cout << "Select: ";
  cin >> select;
  switch (select)
  {
  case 1:
    BookTrain();
    break;
  case 2:
    TicketCost();
    break;
  case 3:
    Cancel();
    break;
  case 4:
    Food();
    break;
  case 5:
    DataBase();
    break;
  default:
    exit(1);
  }
  return;
}
void DataBase()
{
  cout << "_____________________________\n";
  cout << "__________DATA BASE__________\n";
  cout << "    |   1.   Trains     |\n";
  cout << "    |   2.   Users      |\n";
  cout << "    |   3.   Foods      |\n";
  cout << "    |   4.   Passengers |\n";
  cout << "-----------------------------\n";
  cout << "Choose Num: ";
  int select;
  cin >> select;
  switch (select)
  {
  case 1:
    for (int i = 0; i < trains.size(); i++)
      trains[i]->PaintAll();
    break;
  case 2:
    for (int i = 0; i < users.size(); i++)
      users[i]->PrintAll();
    break;
  case 3:
    for (int i = 0; i < foods.size(); i++)
      cout << foods[i].getName() << ' ' << foods[i].getAmount() << ' ' << foods[i].getPrice() << '\n';
    break;
  case 4:
  {
    cout << "Number of Train: ";
    int num;
    cin >> num;
    Train *t = findTrain(num);
    if (!t)
      AdminModel();
    else
      Print(t);
  }
  break;
  }
  AdminModel();
}
int main()
{
  createTrains();
  CreateFood();
  Interface();
  return 0;
}
