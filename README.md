![This is the logo](Sandbox/assets/prune/logo-64.png)

## What?

Prune2D may one day become a simple 2D game engine, for now it is a fun project.

I'm playing with C++ and figured a great way learn the language would be building a 2d game engine ;). As well as learning and using C++ in anger, I'm primarily going to use Prune2D to teach my kids how to code and build lots of fun little games.

My eldest isn't quite ready to get started so I have a little time to get things working, you know, display sprites, have them respond, you know, the ability to make a game.

This project is purely a hobby, I've absolutely no intention in it ever being anything other than a fun little project for me and my kids, however, if you see I'm doing something stupid, please advise, or if you want to use it, go ahead. Any help and advise is appreciated, I've been coding for over 20 years but I'm very new to C++.

I've included a [premake](https://github.com/premake) script to setup the solution for Visual Studio, I'll work on updating the [premake](https://github.com/premake) script for OSX when I feel like moving the project over to my Mac.

## Project Dependencies

I am and will be using the following to create Prune2D, this list is subject to change as I get more knowledgable with the C++ ecosystem.

- SDL
- entt
- glm
- lua
- imgui
- sol
- spdlog

..and whatever else makes my life simpler.

## Current Features

To date, the features are limited, I'll try to keep this list updated, excuse the obvious features (Create a window :)), they were all a challenge to add so I'm going to leave the dumb ones here until the list is bigger and I can remove them.

- Create a Window via SDL
- Enitity component system via entt
- Display sprites and animated sprites
- Movement, well, a velocity component and movement system
- AABB collision system.
- Logging via spdlog
- Sprite library
