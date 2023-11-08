# Logic Driver Pro Dialogue Plugin

## About
[Dialogue Concepts Overview](https://logicdriver.com/docs/guides/dialogue/)

Example plugin which can be used to create dialogue systems using custom classes:
- Dialogue Node
- Dialogue Choice Node
- Dialogue Transition

This plugin mostly serves as a base to help get started with using dialogue in Logic Driver, or as an example on overloading classes in C++. Most of the dialogue implementation still needs to be done at the project level. Please reference the [Example Project's](https://github.com/Recursoft/LogicDriver-Example) `4.27-cpp` branch for an example implementation.

The classes are all marked `Abstract` as the final implementation is meant to be done in blueprints. If you desire C++ classes to be available in the editor do not use the `Abstract` tag.

## Requirements

- This requires [Logic Driver Pro](https://www.unrealengine.com/marketplace/product/logic-driver-state-machine-blueprint-editor) installed at the engine level (such as by downloading from the Unreal Marketplace) or at the project level.

## Installation

- Clone or download a zip (and extract) to your PROJECT / Plugins folder
    - In the case of the Example Project it is: `LogicDriver-Example/Plugins/LogicDriver-Dialogue`
- If you are adding to a Blueprint only project just opening your project file should prompt to build the plugin.
    - For a C++ project you should right click on your project file and choose Generate Visual Studio project files before opening in Visual Studio and compiling.
