# TrickyUserInterface

A collection of user widgets which can help to create basic UI menus and screens.

## Dependencies

This plugin required this plugins to work:

1. [**TrickyGameMode**](https://github.com/TrickyFatCat/TrickyGameMode/releases) v2.1 and higher;

Install them before installing this plugin.

## Installation

The plugin can be used in both C++ and Blueprint projects.

### Blueprint projects

1. Download the latest [**package file**](https://github.com/TrickyFatCat/TrickyPickups/releases);
2. Install the plugin either in your project or for all projects in engine:
    * Unzip the package into Plugins folder of your project, e.g. `D:\UnrealProjects\MyProject\Plugins`;
    * Unzip the package to the Plugins folder in engine folder, e.g. `C:\Program Files\Epic Games\UE_5.0\Engine\Plugins`;
3. Restart the project;

In this case the plugin can be used for any blueprint project.

### C++ projects

1. Create the Plugins folder in the project directory;
2. Create the TrickyAnimationComponents folder in the Plugins folder;
3. Download the plugin source code into that folder;
4. Rebuild the project;

## Widgets

The plugin contains these widget classes:

1. BaseUserWidget;
2. ButtonWidget;
3. TransitionScreenWidget;
4. MainMenuWidget;
5. SplashScreenWidget;
6. PreparationScreenWidget;
7. PauseMenuWidget;
8. WinMenuWidget;
9. LoseMenuWidget;
10. SettingsMenu;
11. SliderWidget;
12. SoundSliderWidget;

All widgets are inherited from BaseUserWidget.

### Base Functions

All widgets have functions:

1. `Show` - shows a widget with an animation;
2. `Hide` - hides a widget with an animation;

### Base Delegates

All widgets have delegates:

1. `OnShowed` - called when a widget was showed;
2. `OnHidden` - called when a widget was hidden;

#### ButtonWidget Delegates

ButtonWidget has delegates:

1. `OnClicked` - called when a button was clicked;

### TrickyUserInterfaceLibrary

A small library which contains some useful helper functions.

1. `SetQualitySettings` - sets visual quality from low (0) to epic (3);
2. `SetScreenMode` - sets screen mode;
3. `SetResolutionScale` - sets screen resolution scale;
4. `SetResolution` - sets screen resolution;
5. `ConvertTimeSeconds` - converts given time in seconds to a chosen format;

### Setup 

All new blueprint widgets inherited from BaseUserWidget and others of this plugin have to have two animations in them:

1. ShowAnimation;
2. HideAnimation;

This animations are required for `Show` and `Hide` functions. If you don't want to use these animations, just set their length to 0.

Some widgets can require to add specific elements or other widgets. Without them they won't compile properly.

More about it you can read [**here**](https://benui.ca/unreal/ui-bindwidget/).

## HUD

The plugin contains a custom HUD class `TrickyHUDGame` created for GameModeSession from [**TrickyGameMode**](https://github.com/TrickyFatCat/TrickyGameMode) plugin.

**It want work with game modes which aren't inherited from GameModeSession.**

It automatically show and hide widgets depending on a state of GameModeSession.

You can get widgets and subscribe on their events using variables:

1. `UserWidgets` - a map of created widgets;
2. `ActiveWidget` - current active widget

### Variables

1. `InactiveStateWidget` - a widget which will be shown in the Inactive game state;
2. `PraparationScreenWidget` - a widget which will be shown in the Preparation game state.
3. `GameplayScreenWidget` - a widget which will be shown in the InProgress game state;
4. `PauseScreenWidget` - a widget which will be shown in the Pause game state;
5. `WinScreenWidget`- a widget which will be shown in the Win game state;
6. `LoseScreenWidget` - a widget which will be shown in the Lose game state;
7. `TransitionScreenWidget` - a widget which will be shown in the Transition game state;

You can create and set only those widgets you need. HUD will automatically handle added widgets.