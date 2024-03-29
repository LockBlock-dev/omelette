# Omelette

An open-source internal (DLL) cheat for the [Chicken Invaders](https://www.interactionstudios.com/chickeninvaders.php) game.

## Features

- Autoshot - shoot automatically
- In Game cheats - you can now use in game cheats:
    - F6: skip wave
    - F7: +1 laser lvl, +1 rocket
    - F8: +1 life
- Game debug mode - hitboxes highlighting
- Firepower - set any level of lasers (from 0 = 1 laser to 7 = 7 lasers)
- Shield - you can't die
- Lives - add a life
- Rockets - add a rocket

## How to use

- Download the cheat from the [`Releases`](../../releases) or [build it](#compiling-from-source) yourself.
- Start the game: use [DxWnd](https://github.com/DxWnd/DxWnd.reloaded) to make the game windowed to avoid crashes and performance issues.
- Open your favorite DLL injector.
- Inject `Omelette.dll` into the `ChickenInvaders.exe` process.
- Open the menu by pressing the <kbd>INSERT</kbd> key.
- Release the menu by pressing the <kbd>END</kbd> key.

## Compiling from source

- Download the project or clone it
- Open [`Omelette.sln`](./Omelette.sln) in Microsoft Visual Studio.
- Change the build configuration to `Release | x86` and build the solution.
- You can find `Omelette.dll` inside `./Release`.

## Credits

[Dear imgui](https://github.com/ocornut/imgui) library  
[Interaction Studios](https://www.interactionstudios.com/chickeninvaders.php) for this great game

## Copyright

See the [license](/LICENSE).