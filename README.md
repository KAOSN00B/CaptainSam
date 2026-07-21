# Captain Sam

SpaceShooter is a third-person shooter project built in Unreal Engine 5. The game features AI enemies, shooting mechanics, health, HUD feedback, and behavior tree driven enemy logic.

## Overview

The player explores the level while fighting enemy guards. Enemies can detect the player, chase or investigate last known locations, shoot when they have a target, and return to their guard position when appropriate.
<img width="1147" height="625" alt="Screenshot 2026-07-21 132523" src="https://github.com/user-attachments/assets/08275bda-a040-4645-9c78-43480bbf2baf" />

## Features

- Third-person player character
- Player shooting system
- Enemy AI using Behavior Trees and Blackboards
- Enemy line-of-sight detection
- Guard behavior with investigation logic
- Enemy health and death handling
- HUD health bar
- HUD enemy counter
- Separate player and enemy weapon setup support

## Controls

- Move: `WASD`
- Look: Mouse
- Jump: Space
- Shoot: Left Mouse Button

## AI Behavior
<img width="1142" height="632" alt="Screenshot 2026-07-21 132537" src="https://github.com/user-attachments/assets/af037f8d-03c2-464a-8d78-9bdf6d449728" />

Enemies use a Behavior Tree to decide what to do:

- If the enemy can see the player, it updates the player location and attacks.
- If the enemy loses sight of the player, it can investigate the last known location.
- If no player is detected, the enemy can wait or return to its starting position.

The enemy state is managed through Blackboard keys such as:

- `PlayerLocation`
- `LastKnownPlayerLocation`
- `StartLocation`

## HUD

The HUD displays:

- Player health
- Number of enemies remaining

Enemy count is tracked by the GameMode and updated when enemies die.

## Project Structure

Important C++ classes:

- `ASpaceShooterCharacter`  
  Handles player/enemy character health, movement, shooting, and death.

- `AGun`  
  Handles weapon firing, muzzle effects, hit detection, and damage.

- `AShooterAI`  
  AI controller for enemy behavior tree setup.

- `UBTService_PlayerLocationIfSeen`  
  Updates the blackboard when the enemy detects the player.

- `UBTTaskNodeShootAtPlayer`  
  Behavior Tree task used by enemies to shoot at the player.

- `ASpaceShooterGameMode`  
  Tracks enemies in the level and updates the remaining enemy count.

- `UHUDWidget`  
  Handles HUD updates such as health and enemies remaining.

## Build Notes
<img width="1145" height="626" alt="Screenshot 2026-07-21 132557" src="https://github.com/user-attachments/assets/df38d7be-5a56-439a-a134-9582e70ea621" />

This project uses Unreal Engine 5.6.

If C++ header files are changed, a full rebuild is recommended. Live Coding may not always update reflected Unreal types such as `UCLASS`, `UPROPERTY`, or `UFUNCTION` changes correctly.

Recommended workflow:

1. Stop Play-In-Editor.
2. Compile or rebuild the project.
3. Reopen or refresh Unreal Editor if needed.
4. Compile and save related Blueprints.

## Status

This project is currently in development as a gameplay programming project.<img width="1147" height="625" alt="Screenshot 2026-07-21 132523" src="https://github.com/user-attachments/assets/2eef2130-30ad-4895-9375-578da5bb3fcd" />
