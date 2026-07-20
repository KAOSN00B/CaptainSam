Shooter Sam
Shooter Sam is a third-person Unreal Engine shooter prototype built with a mix of C++ and Blueprints. The project focuses on core shooter mechanics: player movement, camera control, weapon attachment, line-trace shooting, hit detection, damage handling, basic enemy AI, and HUD integration.

The goal of this project was to get hands-on experience with Unreal Engine's C++ gameplay framework while still using Blueprints for iteration, asset setup, UI, and editor-facing configuration.

## Project Overview

The player controls a third-person character in a sci-fi shooter environment. A rifle is spawned at runtime, attached to the character mesh, and used to fire line traces from the player's viewpoint. When a shot hits an actor, the gun spawns impact effects and applies damage through Unreal's gameplay damage system.

Enemy behavior is set up using Unreal AI systems, including an AI controller and Behavior Tree assets. The project also includes HUD/UI assets and a sci-fi environment asset pack for prototyping.

## Features

- Third-person player character built in C++
- Enhanced Input support for movement, looking, jumping, and shooting
- Runtime weapon spawning and attachment to a character socket
- Line-trace weapon firing from the player camera/viewpoint
- Niagara muzzle flash and impact visual effects
- Damage application using `UGameplayStatics::ApplyDamage`
- Player health tracking and death state handling
- Enemy AI controller with Behavior Tree support
- HUD widget integration through UMG
- Blueprint subclasses for player, rifle, game mode, controller, HUD, and AI setup
- Sci-fi prototype environment and character animation assets

## Tech Stack

- Unreal Engine 5.6
- C++
- Blueprints
- Enhanced Input
- UMG
- Niagara
- Unreal AI / Behavior Trees
- Visual Studio

## Main Systems

### Player Character

The main player character is implemented in `ASpaceShooterCharacter`. It handles movement, looking, jumping, health, damage, death state, and shooting input.

The character uses:

- A capsule collision component
- Character movement configuration
- A spring arm camera boom
- A follow camera
- Enhanced Input bindings
- A spawned weapon actor attached to `WeaponSocket`

### Weapon System

The gun is implemented as an `AGun` actor. When the player fires, the gun:

- Activates a muzzle flash effect
- Gets the player camera/viewpoint
- Performs a line trace forward to a maximum range
- Ignores the gun and owning player during the trace
- Spawns an impact effect when a valid hit occurs
- Applies bullet damage to the hit actor

This gave me practice with actor ownership, collision queries, trace channels, visual effects, and Unreal's damage pipeline.

### Damage and Health

The player character listens for `OnTakeAnyDamage` and reduces current health when hit. If health reaches zero, the character enters a dead state and disables capsule collision.

This system is intentionally simple, but it creates a foundation for future work such as respawning, enemy damage feedback, death animations, and UI updates.

### AI

The enemy controller uses an assigned Behavior Tree asset and starts it on `BeginPlay`. The project includes enemy AI Blueprint assets and Blackboard/Behavior Tree files for AI behavior setup.

## Project Structure

```text
SpaceShooter/
├── Config/                 # Unreal project settings and input configuration
├── Content/
│   ├── BluePrints/          # Gameplay Blueprints, HUD, rifle, controller, AI
│   ├── Characters/          # Character meshes, animations, and materials
│   ├── Input/               # Enhanced Input assets
│   └── Assets/              # Environment, particles, and shooter assets
├── Source/
│   └── SpaceShooter/
│       ├── SpaceShooterCharacter.*
│       ├── Gun.*
│       ├── ShooterAI.*
│       ├── HUDWidget.*
│       ├── SpaceShooterGameMode.*
│       └── SpaceShooterPlayerController.*
├── SpaceShooter.uproject
└── SpaceShooter.sln
```

## How to Run

1. Install Unreal Engine 5.6.
2. Open `SpaceShooter.uproject`.
3. If prompted, rebuild project files.
4. Open the project in Unreal Editor.
5. Press Play in the editor.

If opening from Visual Studio:

1. Open `SpaceShooter.sln`.
2. Select the `Development Editor` configuration.
3. Build the solution.
4. Launch the project through Unreal Editor.

## Controls

The exact bindings are configured through Unreal Enhanced Input assets, but the project supports:

- Move
- Look / mouse look
- Jump
- Shoot

## What I Learned

- How to combine Unreal C++ classes with Blueprint subclasses
- How to bind gameplay actions using Enhanced Input
- How to spawn and attach actors at runtime
- How to perform camera-based line traces
- How Unreal's damage system works at a basic level
- How to connect Niagara effects to gameplay events
- How AI controllers and Behavior Trees fit into an Unreal project

## Known Limitations

- The project is a prototype, not a complete game.
- Enemy behavior is still early and would need more tuning.
- The health/death flow is basic and does not yet include a full respawn or game-over loop.
- UI feedback could be expanded for ammo, hit markers, health, and objectives.

## Future Improvements

- Add enemy attacks and more complete combat behavior
- Add ammo, reloads, and weapon variations
- Improve HUD feedback for health and damage
- Add player death/respawn flow
- Add sound effects for shooting, impacts, and enemy reactions
- Create a small objective-based level
- Add more testing around damage, hit detection, and enemy behavior

