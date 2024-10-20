// header file to define the geometry and material
// define the classes
#ifndef DetectorConstruction_h
// one defitinition
#define DetectorConstruction_h 1 // index symbolize first definition
// i have to include what i ll refer to
#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"

class DetectorConstruction : public G4VUserDetectorConstruction{
    public:
        DetectorConstruction();
        virtual ~DetectorConstruction();
        virtual G4VPhysicalVolume* Construct();
        // method that return a pointer to a physical quantity the volume of the world       
};

#endif