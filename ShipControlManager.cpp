#include "ShipControlManager.h"

ShipControlManager::ShipControlManager() : isInControlTuto(false)
{
    // Constructor implementation
}

ShipControlManager &ShipControlManager::getInstance()
{
    static ShipControlManager instance; // Guaranteed to be destroyed, instantiated on first use
    return instance;
}
