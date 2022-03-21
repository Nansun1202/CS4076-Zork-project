#ifndef CHARACTER_H
#define CHARACTER_H

#include <QObject>
#include<string>
#include<vector>
#include "item.h"
#include "Room.h"
#include "objectcontainer.h"

using namespace std;


class Character:public QObject
{
    Q_OBJECT;

private:
    string description;
    int hunger;
    Room *currentRoom;
    vector <Item*> backpack;

    const int moveHungerLose;
    const int actionHungerLose;
    const int teleportHungerCost;


public:
    Character(string description);
    ~Character();

    string getDescription();
    int getHunger() const;
    Room *getCurrentRoom();

    void addItem(Item *item);
    void removeItem(int ID);
    void removeItem(string name);
    bool hasItem(int ID);


    void setDescription(string description);
    void setHunger(int hunger);
    void setCurrentRoom(Room *next);

    /*** Friends */
    friend class MainWindow;
    friend class ZorkUL;

signals:
    void gameWon();
    void gameLost();
};

#endif // CHARACTER_H