# my_rpg

```text
binary name : my_rpg
language : C
```

This project is one of the freest project of your first year. Create your own RPG.
Your main challenge for this game will be to create a complete product using everything that you and your team know.

To give the users the feeling that you’re delivering a complete product you need to polish as much as possible your game.
Your game must follow the following rules :

- Having a pleasant user interface.
- Create a coherent universe (visual assets, audio assets, scenario, ...)
- Create a funny game where the player has at least one goal.
- Create a game with a beginning and an end.

```text
You should think and look for information about how to create a simple yet entertaining
RPG.
```

```text
The size of your repository (including the assets) must be as small as possible.
Think of the format and the encoding of your resource files (sounds, music, images,..).
An average maximal size might be 30MB, all included.
Any repository exceeding this limit might not be evaluated at all.
```

## REQUIREMENTS

### MANDATORY

- The player needs to have characteristics
- The player can fight enemies AND the characteristics impact the fights results
- The player have an inventory which can contain a limited set of items
- The player can earn experience by winning fights and/or accomplishing specific actions
- The player can level up thanks to experience AND upgrading its characteristics
- The game contains NPC
- The game contains at least one quest
- The game contains a how to play system at the very beginning

### TECHNICAL REQUIREMENTS

This project, being the last project of the module, the following requirement are the mathematical and
technical parts which has to be present in your final project :

- A collision system including moving and static elements with different shapes.
- Camera movements (zoom, translation, rotation).
- 3D effects (depth scaling, isometric projection...).
- Buttons must have at least 3 different state
- Saving system

```text
You can try to use sfView elements
```

### MUST

#### General

- The window may be closed using events,
- The windows may have different mode :
  - Window mode
  - Full-screen mode
- The windows may have different resolutions, at least two (1920x1080, and an other)
- The game manages inputs from the mouse click and keyboard,
- The game contains animated sprites rendered thanks to sprite sheets,
- Animations in your program are frame rate independent,
- Animations and movements in your program are timed by clocks.

#### Main menu

- Must contain at least these options
  - Start the game
  - Resume game (grayed out if not possible)
  - Settings
  - Quit the game
- The settings option must contain
  - Sound and music volume options
  - A window size and resolution options

#### In game menu

- Must be accessible by pressing the Escape key
- Must contain at least these options
  - Character options
    - equipment and inventory management
    - characteristics management
  - Saving
  - Loading
  - Settings
    - the same that main menu
    - commands list

```text
The starting and the game menu MUST be two different scenes.
```

### SHOULD

- Splash screen at the beginning
- Command edit into the in game menu
- As much information as possible about the game should be stored in a configuration file.
- The game should have an advanced collision system to manage complex fighting.
- The game should contains simple particle system :
  - with at least 2 types of particle,
  - particle effects (changing colors, scaling, bouncing, fading) to simulate realistic environment (wind, fire, rain, snow...).

### COULD

- Have a skill tree, unlocking different abilities (active and passive).
- Have a complete particle engine.
- Use scripting to describe entities.
- Have a map editor.

## AUTHORIZED FUNCTIONS

Here is the full list of authorized functions.

### from the CSFML library

All functions

### from the math library

All functions

### from the C library

```text
malloc
free
memset
(s)rand
getline
stat
(f)open
(f)read
(f)close
(f)write
opendir
readdir
closedir
```

```text
Any unspecified functions are de facto banned, except for bonus features.
```

## FINAL MARK

### Mark: 71 / 103 (68.9%)

- Preliminary (2 / 2)
- Error management (2 / 2)
- Window management (3 / 3)
- Events (1 / 1)
- Animations (2 / 2)
- sfClock and framerate (1 / 3)
- Basic button (2 / 2)
- Welcome menu (1 / 1)
- Settings option (2 / 2)
- Setting option : volume (2 / 2)
- Setting option : window (3 / 3)
- Saving system (part I) (2 / 2)
- In game menu access (1 / 1)
- Character's option : characteristics (3 / 3)
- Character's option : inventory (3 / 3)
- Character's option : equipment (2 / 3)
- Saving system (part II) (3 / 3)
- Setting's option : volume & window (1 / 1)
- Setting's option : commands (2 / 2)
- General information (2 / 2)
- Character information (1 / 3)
- NPC and enemies information (3 / 3)
- Visuals rendering (2 / 2)
- Colliding system (2 / 2)
- Fightings effects (1 / 3)
- Environnement effects (3 / 3)
- The universe (4 / 4)
- Quest and NPC (4 / 4)
- Fighting system (3 / 4)
- Gains (3 / 4)
- Global architecture (2 / 3)
- Game engine (0 / 10)
- Rigor code (0 / 0)
- Skills/abilities tree (1 / 4)
- Configuration files (1 / 3)
- Map editor (0 / 5)
- Procedural generation (0 / 5)
- Scripting language (0 / 2)
- Bonus (1 / 20)
