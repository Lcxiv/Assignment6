/*
Condevaux Louis
2305172
Assignment 6
Rene German
Session 1
 */
#include "Sorting.h"
#include <iostream>
#include "time.h"
#include <fstream>
#include "unistd.h"
#include <ctime>

using namespace std;


int main(int argc, char const *argv[]) {
  Sorting s;

  bool keepGoing = true;
  int choice = 0;
  string answer;

  while (keepGoing)
  {
    cout << "Welcome, Please select between the following options: " << endl;
    cout << "1: Write the name of the file you want to try." << endl;
    cout << "2: Get a random List with a number you will pick." << endl;
    cout << "3: If you want to try with a specific number and export the list." << endl;
    cout << "0: Exits the program." << endl;
    cin >> choice;
    if (choice == 1)
    {
      cout << "Please enter the name of your file." << endl;
      cin >> answer;
      s.readFile(answer);
    }
    else if (choice == 2)
    {
      cout << "Please pick the number you want to choose." << endl;
      cin >> choice;
      s.randomSort(choice);
    }
    else if (choice == 3)
    {
      cout << "Please enter the name of the file you want to create." << endl;
      cin >> answer;
      cout << "Please enter the number you want to choose." << endl;
      cin >> choice;
      s.generateRandomList(answer,choice);
    }
    else if (choice == 0)
    {
      cout << "Exiting the program. Goodbye..." << endl;
      keepGoing = false;
    }
    else
    {
      cout << "Please enter a correct output." << endl;
      cin >> choice;
    }

  }
  //s.~Sorting();
  return 0;
}
