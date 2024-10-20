#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

#include "DetectorConstruction.hh"
#include "PrimaryGeneratorAction.hh"
#include "EventAction.hh"
#include "SteppingAction.hh"
#include "ActionInitialization.hh"
#include "PhysicsList.hh"

int main( int argc , char** argv ){
    // detect the interractive mode
    G4UIExecutive* ui  = nullptr;
    if( argc == 1 ){
        ui = new G4UIExecutive( argc , argv );
    }
    // run manager for the simulation running
    G4RunManager* runManager = new G4RunManager;
    runManager -> SetUserInitialization( new DetectorConstruction() );
    runManager -> SetUserInitialization( new PhysicsList() );
    runManager -> SetUserInitialization( new ActionInitialization() );
    // initializing the visualization manager
    G4VisManager* visManager = new G4VisExecutive();
    visManager -> Initialize();
    // get a pointer to the user interface
    G4UImanager* UImanager = G4UImanager::GetUIpointer();

    if (!ui) {
        // Batch mode
        G4String command = "/control/execute ";
        G4String fileName = argv[1];
        UImanager->ApplyCommand(command + fileName);
    } else {
        // Interactive mode
        UImanager->ApplyCommand("/control/execute init_vis.mac");
        ui->SessionStart();
        delete ui;
    }

    // Job termination
    delete visManager;
    delete runManager;

    return 0;
}