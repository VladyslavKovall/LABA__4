#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


struct Sportsman {
   int id;
   string surname;
   int birthYear;
   string sport;
   string rank;
   string country;
};

// Base class 
class SportsmenBase {
protected:
   Sportsman* arr;
   int size;

public:
   // Constructor 
   SportsmenBase(int n) : size(n) {
      arr = new Sportsman[size];
   }

   
   void input() {
      for (int i = 0; i < size; ++i) {
         arr[i].id = i + 1;
         cout << "\nAthlete #" << i + 1 << endl;
         cout << "Surname: ";
         getline(cin, arr[i].surname);
         cout << "Birth year: ";
         cin >> arr[i].birthYear;
         cin.ignore();
         cout << "Sport (skiing, chess, tennis): ";
         getline(cin, arr[i].sport);
         cout << "Rank (first, second, master): ";
         getline(cin, arr[i].rank);
         cout << "Country (Ukraine, Russia, Italy): ";
         getline(cin, arr[i].country);
      }
   }

   
   void print() const {
      cout << "\nList of athletes:" << endl;
      for (int i = 0; i < size; ++i) {
         print(i);
      }
   }

   void print(int index) const {
      if (index < 0 || index >= size) return;
      cout << arr[index].id << ". " << arr[index].surname
         << ", " << arr[index].birthYear
         << ", " << arr[index].sport
         << ", " << arr[index].rank
         << ", " << arr[index].country << endl;
   }
};

// Derived class 
class SportsmenHandler : public SportsmenBase {
public:
   // Constructor using base class constructor
   SportsmenHandler(int n) : SportsmenBase(n) {}

   // Copy constructor
   SportsmenHandler(const SportsmenHandler& other) : SportsmenBase(other.size) {
      for (int i = 0; i < size; ++i) {
         arr[i] = other.arr[i];
      }
   }

   
   void sortBySurname() {
      std::sort(arr, arr + size, [](const Sportsman& a, const Sportsman& b) {
         return a.surname < b.surname;
         });
   }

   void printFiltered() const {
      cout << "\nUkrainian tennis athletes older than 28 years:" << endl;
      int count = 0;
      for (int i = 0; i < size; ++i) {
         int age = 2025 - arr[i].birthYear;
         if (arr[i].country == "Ukraine" &&
            arr[i].sport == "tennis" &&
            age > 28) {
            cout << arr[i].surname << " (" << age << " years)" << endl;
            count++;
         }
      }
      if (count == 0) {
         cout << "No such athletes found." << endl;
      }
   }

  
   explicit operator int() const {
      return size;
   }
};

int main() {
   int n;
   cout << "Enter number of athletes: ";
   cin >> n;
   cin.ignore();

   SportsmenHandler handler(n);
   handler.input();
   handler.print();

   handler.sortBySurname();
   cout << "\nAfter sorting by surname:" << endl;
   handler.print();

   handler.printFiltered();

   int total = static_cast<int>(handler);
   cout << "\nTotal number of athletes: " << total << endl;

   return 0;
}
