/**                                                                                                  
 * @Description: This is the main file for project 8                                           
 * @Name: Rylan Loukusa                                                                               
 * @StarID: sq3572nq                                                                                  
 * @Due Date: Monday April 24st                                                                       
 * @Instructor: Dr. Jie Hu Meichsner                                                                  
 */
#include <iostream>
#include <fstream>
#include "peopleDB.h"

string outputFile = "SCSU_DB2.txt";
ofstream fsOut("SCSU_DB2.txt", ios_base::app);

void toScreen(people& p)
{
  cout << p << endl;
}

void toFile(people& p)
{
  fsOut << p << endl;
}

void displayDatabase(peopleDB* database, void onVisit(people& p)) 
{
  database->displayPreorder(onVisit);
}

void displayDatabaseSorted(peopleDB* database, void onVisit(people& p))
{
  database->displaySorted(onVisit);
}

void saveData(peopleDB* database)
 {
  displayDatabase(database, toFile);

  cout << "The updated database has been saved to " << outputFile << ". Thanks for using our program!" << endl;
}

void add(peopleDB* database)
{
  char input = 'y';
  people temp;
  while(input == 'y' || input == 'Y')
    {
      cout << "To add, enter name and birthday (month day year) :" << endl;
      cin >> temp;
      database->addPerson(temp);
      cout << "Add another one? (y/n)";
      cin >> input;
    }
}

void remove(peopleDB* database)
{
  char input = 'y';
  string name;
  bool result;

  while(input == 'y' || input == 'Y')
    {
      cout <<"To remove, enter a name: " << endl;
      cin >> name;
      result = database->removePerson(name);
      if(result)
	{
	  cout << name << " has been removed." << endl;
	}
      else
	{
	  cout << name << " was not found." << endl;
	}

      cout << "Remove another one? (y/n)";
      cin >> input;
    }
}

void modify(peopleDB* database)
{
  char input = 'y';
  bool result;
  string name;
  people temp;
  while(input == 'y' || input == 'Y')  
    {
      cout << "To modify, enter a name: " << endl;
      cin >> name;
      result = database->removePerson(name);
      if(result)
	{
	  cout << "Found this person in the database. This person's data has been removed." << endl;
	  cout << "Enter this person's new information: name and birthday (month day year) :" << endl;
	  cin >> temp;
	  result = database->addPerson(temp);
	  if(result)
	    {
	      cout << "The database has been modified. \n";
	    }
	  else
	    {
	      cout << "Sorry, the person  could not be added \n";
	    }
	}
      else
	{
	  cout << name << " was not found." << endl;
	}
      cout << "Continue to modify? (y/n)" << endl;
      cin >> input;
    }
}

void search(peopleDB* database)
{
  char input = 'y';
  string name;
  people temp;

  while(input == 'y' || input == 'Y')
    {
      cout << "To search, enter a name: " << endl;
      cin >> name;
      try
	{
	  temp = database->search(name);
	  cout << "Found the person in the database: " << temp << endl;
	}
      catch (NotFoundException e)
	{
	  cout << "Could not find " << name << endl;
	}

      cout << "Continue another search? (y/n)";
      cin >> input;
    }
}

void displayMenu()
{
  cout << "Please enter one of the following options: \n" << endl;
  cout << "1 to add a person to the database" << endl;
  cout << "2 to remove a person from the database" << endl;
  cout << "3 to modify the database" << endl;
  cout << "4 to search for a person in the database" << endl;
  cout << "5 to display the database to the screen" << endl;
  cout << "6 to display the database in sorted order by names to the screen" << endl;
  cout << "7 to display the menu" << endl;
  cout << "0 to save the database to a file and exit" << endl;
}

int main()
{
  int input;
  string filename;
  cout << "Please enter input data file: ";
  cin >> filename;

  peopleDB* database = new peopleDB(filename);
  displayMenu();
  cout << "Please enter your choice of operation: ";
  cin >> input;

  while(input != 0)
    {
      switch(input)
	{
	case 1: add(database); break;
	case 2: remove(database); break;
	case 3: modify(database); break;
	case 4: search(database); break;
	case 5: displayDatabase(database,toScreen); break;
	case 6: displayDatabaseSorted(database,toScreen); break;
	case 7: displayMenu(); break;
	default: cout << "Not a valid choice" << endl;
	}
      cout << "Please enter your choice of operation (7 for menu): ";
      cin >> input;
    }
  saveData(database);
  cout << "Thank you for using our program!\n";
}
