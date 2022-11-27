# Omelette

An open-source internal (DLL) cheat for the [Chicken Invaders](https://www.interactionstudios.com/chickeninvaders.php) game.

## Features

- Autoshot - shoot automatically
- In Game cheats - you can now use in game cheats:
    - F6: skip wave
    - F7: +1 laser lvl, +1 rocket
    - F8: +1 life
- Lasers level - set any level of lasers (from 0 = 1 laser to 7 = 7 lasers)
- Shield - you can't die
- Lives - add a life
- Rockets - add a rocket

## How to use

- Start the game.
- Open your favorite DLL injector.
- Download the cheat from the [`Releases`](../../releases) or [build it](#compiling-from-source) yourself.
- Inject `Omelette.dll` into the `ChickenInvaders.exe` process.
- Open the menu by pressing the <kbd>INSERT</kbd> key.

## Compiling from source

- Download the project or clone it
- Open [`Omelette.sln`](./Omelette.sln) in Microsoft Visual Studio.
- Change the build configuration to `Release | x86` and build the solution.
- You can find `Omelette.dll` inside `./Release`.

## Credits

[Dear imgui](https://github.com/ocornut/imgui) library

## Copyright

See the [license](/LICENSE).