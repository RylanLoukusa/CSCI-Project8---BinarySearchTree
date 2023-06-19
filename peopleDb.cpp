/**                                                                                                  
 * @Description: This is the implementation file for the peopleDB class                                           
 * @Name: Rylan Loukusa                                                                               
 * @StarID: sq3572nq                                                                                  
 * @Due Date: Monday April 24st                                                                       
 * @Instructor: Dr. Jie Hu Meichsner                                                                  
 */

#include "peopleDB.h"

peopleDB::peopleDB(string filename) throw(NotFoundException)
{
  ifstream infile;
  people temp;
  infile.open(filename.c_str());

  cout << "the initial database built from the input file is displayed by its original order:" << endl;
  while(infile >> temp)
    {
      db.add(temp);
      cout << temp << endl;
    }
}

bool peopleDB::addPerson(const people& p)
{
 return db.add(p);
}

bool peopleDB::removePerson(string name)
{
  return db.remove(people(name));
}

people peopleDB::search(string name)
{
  return db.getEntry(people(name));
}

void peopleDB::displayPreorder(void onVisit(people& p))
{
  db.preorderTraverse(onVisit);
}

void peopleDB::displaySorted(void onVisit(people& p))
{
  db.inorderTraverse(onVisit);
}
