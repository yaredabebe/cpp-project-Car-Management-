//car information system in bus station 
//using linked list

#include<iostream>
#include<iomanip>
//#include<stdlib.h>
using namespace std;
void first();
int add();
void add_first();
void add_end();
void add_after_specific();
void add_before_specific();
void update(string lisenceUpdate);
void delete_data();
void delete_first();
void delete_end();
void delete_search();
void sort();
void sortlicensePlate();
void sort_start();
void sort_end();
void search();
void display();
void display_all();
void display_search();

struct car {
  string license_plate;
  string car_name_model_year;
  string car_capacity;
  string start;
  string end;
  string experience;
  string contact;
  string working_time;
  string safety;

  car * next;
};

car * head = NULL;
car * create_data();
void swap(car * temp, car * temp2);
int main() {
  cout << "\n\n==========Welcome to Bus station car information system=========" << endl;
  cout << "\t\tThis project is done by:\n";
  cout << "\t   Name\t\t          ID\n";
  cout << "\t1.Melaku Zegeye\t\t1202348\n\t2.Nuru Ahmed\t\t1202705\n\t3.Gzachew Tsega\t\t1201850\n\t4.Addisu Berihun\t1200800\n\t5.Wondwossen Abye\t1203250";
  cout << "\n\n\t\tSUBMITTED TO: ASAMINEW G.";
  cout << "\n\t\tSUBMISSION DATE : 29/5/2014 E.C";
  cout << "\n  Press any key to get started : ";
  cin.get();

  system("cls");
  first();
  return 0;
}

void first() {
  char choice[3];
  cout << "\n\t1.Add data\n\t2.Update\n\t3.Delete\n\t4.Sort\n\t5.Display\n\t6.Exit\n";
  cout << "\n   Enter your choice : ";
  cin >> choice;
  switch (atoi(choice)) {
  case 1:
    add();
    break;
  case 2: {
    string lisencePlate;
    cout << "\n   Enter the lisence plate of the car to be updated : ";
    cin >> lisencePlate;
    update(lisencePlate);
    break;
  }
  case 3:
    delete_data();
    break;
  case 4:
    sort();
    break;
  case 5: {
    display();
    break;
  }
  case 6:
    exit(0);
  default: {
    cout << "\n   Please enter a valid choice!\n";
    first();
  }
  }
}

int add() {
  char choice[3];
  cout << "\n\t1.Add at the begnning\n\t2.Add at the end\n\t3.Add after specific data\n\t4.Add before specific data\n\t5.Display\n\t6.Back\n\t7.Exit";
  cout << "\n   Enter your choice :";
  cin >> choice;
  switch (atoi(choice)) {
  case 1:
    add_first();
    break;
  case 2:
    add_end();
    break;
  case 3:
    add_after_specific();
    break;
  case 4:
    add_before_specific();
    break;
  case 5:
    display();
    break;
  case 6:
    first();
    break;
  case 7:
    exit(0);
    break;
  default: {
    cout << "\n   Please enter a valid choice!\n";
    add();
  }
  }
  do {
    cout << "\n Do you want to add another data ?\n 1.Yes\n 2.No";
    cout << "\n  Enter your choice :";
    cin >> choice;
    if (atoi(choice) == 1)
      add();
    else
      first();
  } while (atoi(choice) == 1);
  return 0;
}

car * create_data() {
  char choice[3];
  car * temp = new car;
  car * temp2 = head;
  int found;
  do {
    W: found = 0;
    cout << "\n\n   Enter the license plate of the car : ";
    cin.ignore();
    getline(cin, temp -> license_plate);
    if (temp -> license_plate.size() < 5) {
      cout << "\n   The license plate of the car must be at least 5 characters.\n   Do you want to enter again ?\n   1.Yes\n   2.No \n   Enter your choice :";
      cin >> choice;
      if (atoi(choice) == 1)
        create_data();
      else
        first();
    }
    while (temp2 != NULL) {
      if (temp2 -> license_plate == temp -> license_plate) {
        found = 1;
        cout << "\n   There is car information on that license plate. Please check your license plate !\n   Do you want to enter again ?\n   1.Yes\n   2.No \n   Enter your choice :\n";
        cin >> choice;
        if (atoi(choice) == 1)
          goto W;
        else

          add();
      }
      temp2 = temp2 -> next;
    }
  } while (temp -> license_plate.size() < 5 && atoi(choice) == 1 && found == 0);
  if (temp -> license_plate.size() >= 5 && found == 0) {
    cout << "\n   Enter the car name its model and manufactured year :";
    getline(cin, temp -> car_name_model_year);
    cout << "\n   Enter the capacity of the car :";
    getline(cin, temp -> car_capacity);
    cout << "\n   Enter the starting place :";
    getline(cin, temp -> start);
    cout << "\n   Enter the place where the car stops :";
    getline(cin, temp -> end);
    cout << "\n   Enter the working day and time of the car :";
    getline(cin, temp -> working_time);
    cout << "\n   write something about the safety of the car (recorde of any accident before) :";
    getline(cin, temp -> safety);
    temp -> next = NULL;
    cout << endl;
    system("cls");
    cout << "\n   You have successfuly added data\n";
    return temp;
  }
}

void add_first() {
  car * temp = create_data();
  if (head == NULL)
    head = temp;
  else {
    temp -> next = head;
    head = temp;
  }
}

void add_end() {
  car * temp = create_data();
  if (head == NULL)
    head = temp;
  else {
    car * temp2 = head;
    while (temp2 -> next != NULL) {
      temp2 = temp2 -> next;
    }
    temp2 -> next = temp;
  }
}

void add_after_specific() {
  string licenseSpecific;
  car * temp3 = head;
  cout << "\n   Enter the license plate of the car after which the data is inserted :";
  cin >> licenseSpecific;
  while (temp3 != NULL) {
    if (temp3 -> license_plate == licenseSpecific)
      break;
    temp3 = temp3 -> next;
  }
  if (temp3 != NULL) {
    car * temp = create_data();
    if (head == NULL)
      head = temp;
    else {   
      temp -> next = temp3 -> next;
      temp3 -> next = temp;
    }
  } else {
    char choice[3];
    cout << "\n   The license plate is not found.\n  Do you want to try agin ?\n  1.Yes\n  2.No\n";
    cout << "  Enter your choice :";
    cin >> choice;
    if (atoi(choice) == 1)
      add();
  }
}
void add_before_specific() {
  string licenseSpecific;
  car * temp3 = head;
  cout << "\n   Enter the license_plate of the car before which data is inserted :";
  cin >> licenseSpecific;
  while (temp3 != NULL) {
    if (temp3 -> license_plate == licenseSpecific)
      break;
    temp3 = temp3 -> next;
  }
  if (temp3 != NULL) {
    car * temp = create_data();
    if (head == NULL)
      head = temp;
    else if (head -> next == NULL) {
      temp -> next = head;
      head = temp;
    } 
    else {
      car * temp2 = head;
      car * temp3;
      while (temp2 -> license_plate != licenseSpecific) {
        temp3 = temp2;
        temp2 = temp2 -> next;
      }
      temp -> next = temp3 -> next;
      temp3 -> next = temp;
    }
  }
   else {
    char choice[3];
    cout << "\n   The license plate is not found.\n  Do you want to try agin ?\n  1.Yes\n  2.No\n";
    cout << "  Enter your choice :";
    cin >> choice;
    if (atoi(choice) == 1)
      add();
  }
}

void update(string lisenceUpdate) {
  system("cls");
  string value;
  char choice[3];
  car * temp = head;
  car * temp2 = head;
  while (temp != NULL) {

    if (temp -> license_plate == lisenceUpdate)
      break;
    temp = temp -> next;

  }
  if (temp == NULL) {
    cout << "\n   There is no data on this lisence plate.\n  You can add informations about this lisence plate\n  1.Add data\n  2.Back\n";
    cout << "   Enter your choice :";
    cin >> choice;
    if (atoi(choice) == 1)
      add();
    else
      first();
  } 
  else {
    cout << "\n   1.Update all information on this license plate\n   2.Update license plate\n   3.Update the car name its model and manufactured year\n   4.Update the capacity of the car\n   5.Update the starting place \n   6.Update the place where the car stops\n   7.Update the working day and time of the car \n   8.Update the information about the safty of the car\n   9.Back";
    cout << "\n   Enter Your choice :";
    cin >> choice;
    int found = 0;
    switch (atoi(choice)) {
    case 1: {

      A: int found = 0;
      cout << "\n\n   Enter the new license plate of the car : ";
      cin.ignore();
      getline(cin, value);

      if (value.size() < 5) {
        cout << "\n   The license plate of the car must be at least 5 characters.\n   Do you want to update again ?\n   1.Yes\n   2.No \n   Enter your choice :";
        cin >> choice;
        if (atoi(choice) == 1)
          goto A;
        else
          update(temp -> license_plate);
      }

      while (temp2 != NULL) {
        if (temp2 -> license_plate == value) {
          found = 1;
          cout << "\n   There is car information on that license plate. Please check your license plate and try again !\n   \n   Do you want to update again ?\n   1.Yes\n   2.No \n   Enter your choice :";
          cin >> choice;
          if (atoi(choice) == 1)
            goto A;
          else
            update(temp -> license_plate);
        }

        temp2 = temp2 -> next;
      }
      if (value.size() >= 5 && found == 0)

        temp -> license_plate.assign(value);

      if (temp -> license_plate.size() >= 5 && found == 0) {
        cout << "\n   Enter the car name its model and manufactured year :";
        getline(cin, temp -> car_name_model_year);
        cout << "\n   Enter the capacity of the car :";
        getline(cin, temp -> car_capacity);
        cout << "\n   Enter the starting place :";
        getline(cin, temp -> start);
        cout << "\n   Enter the place where the car stops :";
        getline(cin, temp -> end);
        cout << "\n   Enter the working day and time of the car :";
        getline(cin, temp -> working_time);
        cout << "\n   write something about the safety of the car (recorde of any accident before) :";
        getline(cin, temp -> safety);
      }

      break;
    }
    case 2: {
      D: int found = 0;
      cout << "\n\n   Enter the new license plate of the car : ";
      cin.ignore();
      getline(cin, value);

      if (value.size() < 5) {
        cout << "\n   The license plate of the car must be at least 5 characters.\n   Do you want to update again ?\n   1.Yes\n   2.No \n   Enter your choice :";
        cin >> choice;
        if (atoi(choice) == 1)
          goto D;
        else
          update(temp -> license_plate);
      }

      while (temp2 != NULL) {
        if (temp2 -> license_plate == value) {
          found = 1;
          cout << "\n   There is car information on that license plate. Please check your license plate and try again !\n   \n   Do you want to update again ?\n   1.Yes\n   2.No \n   Enter your choice :";
          cin >> choice;
          if (atoi(choice) == 1)
            goto D;
          else
            update(temp -> license_plate);
        }

        temp2 = temp2 -> next;
      }
      if (value.size() >= 5 && found == 0)

        temp -> license_plate.assign(value);
      break;
    }
    case 3: {
      cout << "\n   Enter the car name its model and manufactured year:";
      cin.ignore();
      getline(cin, temp -> car_name_model_year);
      break;
    }
    case 4: {
      cout << "\n   Enter the capacity of the car:";
      cin.ignore();
      getline(cin, temp -> car_capacity);
      break;
    }
    case 5: {
      cout << "\n   Enter the starting place :";
      cin.ignore();
      getline(cin, temp -> start);
      break;
    }
    case 6: {
      cout << "\n   Enter the place where the car stops:";
      cin.ignore();
      getline(cin, temp -> end);
      break;
    }
    case 7: {
      cout << "\n   Enter the working day and time of the car:";
      cin.ignore();
      getline(cin, temp -> working_time);
      break;
    }
    case 8: {

      cout << "\n   write something about the safety of the car (recorde of any accident before,any insurance):\n";
      cin.ignore();
      getline(cin, temp -> safety);
      break;
    }
    case 9:
      first();
      break;
    default: {
      cout << "\n  Please enter a valid choice!\n";
      update(lisenceUpdate);
    }
    }
  }
  system("cls");
  cout << "\n   Data successfully updated.";
  cout << "\n   Do you want to update other informations ?\n   1.Yes\n   2.No";
  cout << "\n   Enter your choice :";
  cin >> choice;
  if (atoi(choice) == 1)
    update(temp -> license_plate);
  else
    first();
}

void delete_data() {
  system("cls");
  char choice[3];
  cout << "\n\t1.Delete data at the begning\n\t2.Delete data at the end\n\t3.Delete data by searching\n\t4.Back\n\t5.Exit\n";
  cout << "   Enter your choice :";
  cin >>choice;
  switch (atoi(choice)) {
  case 1:
    delete_first();
    break;
  case 2:
    delete_end();
    break;
  case 3:
    delete_search();
    break;
  case 4:
    first();
    break;
  case 5:
    exit(0);
    break;
  default:
    cout << "\n   Please enter the valid choice!";
    delete_data();
  }
  first();
}

void delete_first() {
  char choice[3];
  if (head == NULL) {
    cout << "\n   There is no data to be deleted.\n";
  } 
  else {
    car * temp = head;
    head = head -> next;
    delete temp;
    cout << "\n   Data successfully deleted!\n";
  }
  do {
    if (head == NULL)
      break;
    cout << "\n Do you want to delete another data ?\n 1.Yes\n 2.No";
    cout << "\nEnter your choice :";
    cin >> choice;
    if (atoi(choice) == 1)
      delete_data();
    else
      first();
  } while (atoi(choice) == 1);
}
void delete_end() {
  char choice[3];
  if (head == NULL) {
    cout << "\n   There is no data to be deleted.\n";
  } else if (head -> next == NULL) {
    car * temp = head;
    delete temp;
    cout << "\n   Data successfully deleted!\n";
    head = NULL;
  } else {
    car * temp = head, * temp2;

    while (temp -> next != NULL) {
      temp2 = temp;
      temp = temp -> next;
    }
    temp2 -> next = NULL;
    delete temp;
    cout << "\n   Data successfully deleted!\n";
  }
  do {
    if (head == NULL)
      break;
    cout << "\n Do you want to delete another data ?\n 1.Yes\n 2.No";
    cout << "\nEnter your choice :";
    cin >> choice;
    if (atoi(choice) == 1)
      delete_data();
    else
      first();
  } while (atoi(choice) == 1);
}
void delete_search() {
  char choice[3];
  string licensePlate;
  cout << "\n   Enter the lisence plate of the car to be deleted : ";
  cin >> licensePlate;
  car * temp = head, * temp2;
  while (temp != NULL) {
    if (temp -> license_plate == licensePlate)
      break;
    temp2 = temp;
    temp = temp -> next;
  }
  if (temp == NULL)
    cout << "\n   There is no data on this lisence plate!\n";
  else if (head -> next == NULL) {
    car * temp = head;
    delete temp;
    cout << "\n   Data successfully deleted!\n";
    head = NULL;
  } else {
    temp2 -> next = temp -> next;
    delete temp;
    cout << "\n   Data successfully deleted!\n";
  }
  do {
    if (head == NULL)
      break;
    cout << "\n Do you want to delete another data ?\n 1.Yes\n 2.No";
    cout << "\n  Enter your choice :";
    cin >> choice;
    if (atoi(choice) == 1)
      delete_data();
    else
      first();
  } while (atoi(choice) == 1);
}

void sort() {
  system("cls");
  char choice[3];
  cout << "\n\t1.Sort by license plate\n\t2.sort by starting place\n\t3.sort by the last terminal\n\t4.Back\n\t5.Exit\n";
  cout << "\n   Enter your choice : ";
  cin >> choice;
  switch (atoi(choice)) {
  case 1:
    sortlicensePlate();
    break;
  case 2:
    sort_start();
    break;
  case 3:
    sort_end();
    break;
  case 4:
    first();
    break;
  case 5:
    exit(0);
    break;
  default:
    cout << "\n   Please enter a valid choice!\n";
    sort();
  }
  first();
}

void swap(car * temp, car * temp2) {
  car temp3;
  temp3.license_plate = temp -> license_plate;
  temp3.car_name_model_year = temp -> car_name_model_year;
  temp3.car_capacity = temp -> car_capacity;
  temp3.start = temp -> start;
  temp3.end = temp -> end;
  temp3.working_time = temp -> working_time;
  temp3.safety = temp -> safety;

  temp -> license_plate = temp2 -> license_plate;
  temp -> car_name_model_year = temp2 -> car_name_model_year;
  temp -> car_capacity = temp2 -> car_capacity;
  temp -> start = temp2 -> start;
  temp -> end = temp2 -> end;
  temp -> working_time = temp2 -> working_time;
  temp -> safety = temp2 -> safety;

  temp2 -> license_plate = temp3.license_plate;
  temp2 -> car_name_model_year = temp3.car_name_model_year;
  temp2 -> car_capacity = temp3.car_capacity;
  temp2 -> start = temp3.start;
  temp2 -> end = temp3.end;
  temp2 -> working_time = temp3.working_time;
  temp2 -> safety = temp3.safety;
}
void sortlicensePlate() {
  car * temp;
  car * temp2;
  if (head == NULL)
    cout << "\n   No data to sorted.\n";
  else if (head -> next == NULL)
    cout << "\n   No need for sorting.\n";
  else {
    for (temp = head; temp -> next != NULL; temp = temp -> next) {
      for (temp2 = temp -> next; temp2 != NULL; temp2 = temp2 -> next) {

        if (temp -> license_plate > temp2 -> license_plate)
          swap(temp, temp2);
      }
    }
    cout << "\n   Data is successfuly sorted.\n";
  }
}

void sort_start() {
  car * temp;
  car * temp2;

  if (head == NULL)
    cout << "\n   No data to sorted.\n";

  else if (head -> next == NULL)
    cout << "\n   No need for sorting.\n";
  else {
    string n;

    for (temp = head; temp -> next != NULL; temp = temp -> next) {
      for (temp2 = temp -> next; temp2 != NULL; temp2 = temp2 -> next) {

        if (temp -> start > temp2 -> start)
          swap(temp, temp2);
      }
    }
    cout << "\n   Data is successfuly sorted.\n";
  }

}

void sort_end() {
  car * temp;
  car * temp2;
  if (head == NULL)
    cout << "\n   No data to sorted.\n";
  else if (head -> next == NULL)
    cout << "\n   No need for sorting.\n";
  else {
    for (temp = head; temp -> next != NULL; temp = temp -> next) {
      for (temp2 = temp -> next; temp2 != NULL; temp2 = temp2 -> next) {

        if (temp -> end > temp2 -> end)
          swap(temp, temp2);
      }
    }
    cout << "\n   Data is successfuly sorted.\n";
  }

}

void display() {
  char choice[3];
  cout << "\n\t1.Display all data in the system\n\t2.Display by searching\n\t3.Back\n\t4.Exit";
  cout << "\n   Enter your choice : ";
  cin >> choice;
  switch (atoi(choice)) {
  case 1:
    display_all();
    break;
  case 2: 
    display_search();
    break;
  case 3:
    first();
  case 4:
    exit(0);
  default:
    cout << "\n   Please enter a vaild choice!";
    display();
  }
  first();
}

void display_all() {
  system("cls");
  if (head == NULL) {
    cout << "\n   There is no data to display.\n";
  } else {
    car * temp = head;
    while (temp != NULL) {
      cout << endl;
      cout << setw(50) << left << "license Plate :   " << temp -> license_plate << endl;
      cout << setw(50) << left << "The car name,model and manufactured year :" << temp -> car_name_model_year << endl;
      cout << setw(50) << left << "The maximum number of passengers it can hold :" << temp -> car_capacity << endl;
      cout << setw(50) << left << "the starting station:" << temp -> start << endl;
      cout << setw(50) << left << "Ending station :" << temp -> end << endl;
      cout << setw(50) << left << "The working day and time:" << temp -> working_time << endl;
      cout << setw(50) << left << "Safty about the car:" << temp -> safety << endl;
      temp = temp -> next;
    }
  }
}

void display_search() {
  if (head == NULL)
    cout << "\n   There is no data to display.\n";
  else {
    char choice[3];
    string find;
    cout << "\n   Enter the license plate or starting place or ending place of the car to be displayed :";
    cin.ignore();
    getline(cin, find);
    car * temp = head;
    while (temp != NULL) {
      if (temp -> license_plate == find)
        break;
      if (temp -> start == find)
        break;
      if (temp -> end == find)
        break;
      temp = temp -> next;
    }
    if (temp == NULL) {
      cout << "\n   No data on this license plate.\n";
      cout << "\n  Do you want to search again ? \n  1.Yes\n  2.No";
      cout << "\n  Enter your choice :";
      cin >> choice;
      if (atoi(choice) == 1)
        display_search();
    }
     else {
      cout << setw(50) << left << "\nlicense Plate :" << temp -> license_plate << endl;
      cout << setw(50) << left << "The car name,model and manufactured year :" << temp -> car_name_model_year << endl;
      cout << setw(50) << left << "The maximum number of passengers it can hold :" << temp -> car_capacity << endl;
      cout << setw(50) << left << "the starting station:" << temp -> start << endl;
      cout << setw(50) << left << "Ending station :" << temp -> end << endl;
      cout << setw(50) << left << "The working day and time:" << temp -> working_time << endl;
      cout << setw(50) << left << "Safty about the car:" << temp -> safety << endl;
    }
  }
}
