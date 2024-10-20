#ifndef PhysicsList_h
#define PhysicsList_h 1

#include "G4VModularPhysicsList.hh"

class PhysicsList : public G4VModularPhysicsList {
public:
    PhysicsList();  // Constructor
    virtual ~PhysicsList();  // Destructor

protected:
    virtual void ConstructParticle();  // Method to construct particles
    virtual void ConstructProcess();  // Method to construct processes
};

#endif // PhysicsList_h
