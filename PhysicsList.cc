#include "PhysicsList.hh"
#include "G4VModularPhysicsList.hh"
#include "G4ParticleDefinition.hh"
#include "G4Proton.hh"
#include "G4ProcessManager.hh"
#include "G4Decay.hh"
//#include "G4Ionisation.hh"
#include "G4HadronInelasticProcess.hh"
#include "G4PhysicsListHelper.hh"

PhysicsList::PhysicsList() : G4VModularPhysicsList() {
    SetVerboseLevel(1);

    // Register the particles you want to use
    ConstructParticle();
    // Register the processes you want to apply to the particles
    ConstructProcess();
}

PhysicsList::~PhysicsList() {
    // Destructor: Clean up resources if necessary
}

void PhysicsList::ConstructParticle() {
    // Define particles; in this case, we include protons
    G4Proton::ProtonDefinition();
}

void PhysicsList::ConstructProcess() {
    // Get the particle manager
    G4ProcessManager* pManager = G4Proton::Proton()->GetProcessManager();

    // Register the processes for protons
    // Ionization process
    G4Ionisation* ionisation = new G4Ionisation();
    pManager->AddProcess(ionisation); // Add ionization process for protons

    // Hadronic processes can also be added
    G4HadronInelasticProcess* hadronicProcess = new G4HadronInelasticProcess();
    hadronicProcess->RegisterMe(new G4HadronInelasticProcess());
    pManager->AddProcess(hadronicProcess); // Add hadronic inelastic process

    // Decay process (if applicable)
    G4Decay* decay = new G4Decay();
    pManager->AddProcess(decay);
    
    // Set the ordering for the processes
    pManager->SetProcessOrdering(ionisation, idxPostStep);
    pManager->SetProcessOrdering(decay, idxPostStep);
    pManager->SetProcessOrdering(hadronicProcess, idxPostStep);
}
