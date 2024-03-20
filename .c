#include <stdbool.h>

bool MoveElevator(bool callUp, bool callDown, bool insideCall, int currentFloor, int totalFloors, bool doorClosed, bool movingUp, bool movingDown) {
    if ((movingUp && currentFloor < totalFloors) || (movingDown && currentFloor > 1))
        return true;

    if (insideCall && doorClosed)
        return MoveElevator(false, false, true, currentFloor, totalFloors, false, false, false);

    if (callUp && currentFloor < totalFloors && !movingUp && doorClosed)
        return MoveElevator(false, false, false, currentFloor, totalFloors, true, true, false);

    if (callDown && currentFloor > 1 && !movingDown && doorClosed)
        return MoveElevator(false, false, false, currentFloor, totalFloors, true, false, true);

    return false;
}

int main() {
    bool callUp = true;
    bool callDown = false;
    bool insideCall = false;
    int currentFloor = 3; 
    int totalFloors = 10;
    bool doorClosed = true;
    bool movingUp = false;
    bool movingDown = false;

    MoveElevator(callUp, callDown, insideCall, currentFloor, totalFloors, doorClosed, movingUp, movingDown);

    return 0;
}
