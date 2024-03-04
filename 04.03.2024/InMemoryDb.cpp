#include "InMemoryDb.h"

void InMemoryDb::clear()
{
    users.clear();
}

void InMemoryDb::addUser(User user)
{
    users.push_back(user);
}

void InMemoryDb::removeUser(int id)
{
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getUniqId() == id) {
            users.erase(users.begin() + i);
            break;
        }
    }
}

User InMemoryDb::findUserById(int id)
{
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getUniqId() == id) {
           return users[i];
        }
    }
}

int InMemoryDb::getCountUsers()
{
    return users.size();
}

void InMemoryDb::showAll()
{
    for (auto el : users) {
        el.show();
        cout << endl;
    }
}

vector<User> InMemoryDb::getUsers()
{
    return users;
}
