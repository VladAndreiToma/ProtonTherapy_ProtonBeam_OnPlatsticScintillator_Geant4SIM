#include "DetectorConstruction.hh"
#include "G4Box.hh"  // we build the cubical shape as a box
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"

DetectorConstruction::DetectorConstruction() : G4VUserDetectorConstruction() {}
// Constructor inherits from G4VUserDetectorConstruction

DetectorConstruction::~DetectorConstruction() {}
// Destructor (can be used for cleanup, but currently does nothing)

// We have to construct the world in which we put our setup
// For this example, the world is air at atmospheric pressure
G4VPhysicalVolume* DetectorConstruction::Construct() {
    // Create a pointer to a material list object
    G4NistManager* nist = G4NistManager::Instance();
    
    // Define world size and material
    G4double worldSize = 10 * m; // World size is 10 meters
    G4Material* worldMaterial = nist->FindOrBuildMaterial("G4_AIR"); // World material is air

    // Define the world volume
    G4Box* worldBox = new G4Box("World", worldSize / 2, worldSize / 2, worldSize / 2);
    G4LogicalVolume* logical_worldBox = new G4LogicalVolume(worldBox, worldMaterial, "World");
    
    // Place the world volume with no rotation, at the origin (0,0,0)
    G4VPhysicalVolume* physical_worldBox = new G4PVPlacement(
        0, // no rotation
        G4ThreeVector(0., 0., 0.), // position at origin
        logical_worldBox, // logical volume
        "World", // name
        nullptr, // no mother volume (this is the world)
        false, // no boolean operations
        0, // copy number
        true // check for overlaps
    );

    // Define the scintillator box material and shape
    G4Material* plastic_scintillator = nist->FindOrBuildMaterial("G4_POLYETHYLENE"); // Scintillator material
    G4double targetSize = 1 * m; // Target size is 1 meter for each dimension

    // Define the target box (remember G4Box takes half-lengths)
    G4Box* targetBox = new G4Box("Target", targetSize / 2, targetSize / 2, targetSize / 2);
    G4LogicalVolume* targetLog = new G4LogicalVolume(targetBox, plastic_scintillator, "Target");

    // Place the target box 2 meters along the x-axis, inside the world volume
    new G4PVPlacement(
        0, // no rotation
        G4ThreeVector(2. * m, 0., 0.), // position at (2 meters, 0, 0)
        targetLog, // logical volume
        "Target", // name
        logical_worldBox, // mother volume (world)
        false, // no boolean operations
        0, // copy number
        true // check for overlaps
    );

    // Return the world volume (as required by Geant4)
    return physical_worldBox;
}
