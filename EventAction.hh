// define the class
#ifndef EventAction_h
#define EventAction_h 1

#include "G4UserEventAction.hh"
#include "globals.hh"

class EventAction : public G4UserEventAction {
public:
    EventAction();
    virtual ~EventAction();

    // Override G4UserEventAction methods
    virtual void BeginOfEventAction(const G4Event*);
    virtual void EndOfEventAction(const G4Event*);  // Fixed typo here

    // Custom method to add energy deposition
    void AddEnergyDeposition(G4double energy);  // Make sure this matches your .cc file

private:
    G4double fTotalEnergyDeposit;  // Member to store total energy deposited
};

#endif
