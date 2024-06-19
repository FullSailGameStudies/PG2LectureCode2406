#include "FlyingCar.h"

std::string FlyingCar::vehicleInformation()
{
    //do I FULLY-override or EXTEND?
    //FULL OVERRIDE - do NOT call the base version
    //EXTEND - call the base then do extra work
    //how to call the base?
    //BaseClassName::method(...)
    std::string baseInfo = Car::vehicleInformation();
    return baseInfo + " (max altitude: " + std::to_string(maxAltitude_) + ")";
}
