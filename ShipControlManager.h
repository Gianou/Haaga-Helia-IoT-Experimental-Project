/*
    The goal of this class are :
        -Know if the game is ongoing or control tuto
        -Know what is the current control
        -Know in what order controls change
*/

#ifndef SHIP_CONTROL_MANAGER_H
#define SHIP_CONTROL_MANAGER_H

class ShipControlManager
{
public:
    static ShipControlManager &getInstance();

private:
    ShipControlManager();
    ShipControlManager(const ShipControlManager &) = delete; // Disallow copy constructor
    void operator=(const ShipControlManager &) = delete;
    bool isInControlTuto;
};

#endif
