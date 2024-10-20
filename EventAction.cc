#include "EventAction.hh"
#include "G4Event.hh"
#include "G4SystemOfUnits.hh"
#include "G4EventManager.hh"
#include "G4RunManager.hh"
#include "G4HCofThisEvent.hh"

// Constructor: initializing fTotalEnergyDeposit to 0
EventAction::EventAction() : G4UserEventAction(), fTotalEnergyDeposit(0) {}

// Destructor: currently empty
EventAction::~EventAction() {}

// Begin of Event: Reset total energy deposited for each event
void EventAction::BeginOfEventAction(const G4Event*) {
    fTotalEnergyDeposit = 0.;
}

// End of Event: Output the total energy deposited at the end of the event
void EventAction::EndOfEventAction(const G4Event*) {
    G4cout << "Total Energy deposited: " << fTotalEnergyDeposit / MeV << " MeV" << G4endl;
}

// Method to add energy deposition during the event
void EventAction::AddEnergyDeposition(G4double energy) {
    fTotalEnergyDeposit += energy;
}
