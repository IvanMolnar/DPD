cmake_minimum_required(VERSION 3.12)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release;" CACHE STRING "" FORCE)

project(DPD
    LANGUAGES CXX
    VERSION 0.1
)

set(AllFiles ${CMAKE_CURRENT_SOURCE_DIR}/src/Display/Display.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/Display/Display.h 
${CMAKE_CURRENT_SOURCE_DIR}/src/Display/MyDisplayExample.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/Display/MyDisplayExample.h
${CMAKE_CURRENT_SOURCE_DIR}/src/Factories/GameObjectFactory.h ${CMAKE_CURRENT_SOURCE_DIR}/src/Factories/GenericFactory.h 
${CMAKE_CURRENT_SOURCE_DIR}/src/Factories/GUIElementFactory.h
${CMAKE_CURRENT_SOURCE_DIR}/src/FileSystem/FileSystem.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/FileSystem/FileSystem.h 
${CMAKE_CURRENT_SOURCE_DIR}/src/FileSystem/MyFileSystem.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/FileSystem/MyFileSystem.h
${CMAKE_CURRENT_SOURCE_DIR}/src/FSM/FSM.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/FSM/FSM.h ${CMAKE_CURRENT_SOURCE_DIR}/src/FSM/State.cpp
${CMAKE_CURRENT_SOURCE_DIR}/src/FSM/State.h ${CMAKE_CURRENT_SOURCE_DIR}/src/FSM/StateCrouching.cpp 
${CMAKE_CURRENT_SOURCE_DIR}/src/FSM/StateCrouching.h ${CMAKE_CURRENT_SOURCE_DIR}/src/FSM/StateDead.cpp
${CMAKE_CURRENT_SOURCE_DIR}/src/FSM/StateDead.h ${CMAKE_CURRENT_SOURCE_DIR}/src/FSM/StateUp.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/FSM/StateUp.h
${CMAKE_CURRENT_SOURCE_DIR}/src/GameLogic/GameLogic.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/GameLogic/GameLogic.h
${CMAKE_CURRENT_SOURCE_DIR}/src/GameLogic/MyGameLogicExample.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/GameLogic/MyGameLogicExample.h
${CMAKE_CURRENT_SOURCE_DIR}/src/GameObjects/Armor.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/GameObjects/Armor.h
${CMAKE_CURRENT_SOURCE_DIR}/src/GameObjects/Container.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/GameObjects/Container.h
${CMAKE_CURRENT_SOURCE_DIR}/src/GameObjects/Door.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/GameObjects/Door.h
${CMAKE_CURRENT_SOURCE_DIR}/src/GameObjects/Enemy.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/GameObjects/Enemy.h
${CMAKE_CURRENT_SOURCE_DIR}/src/GameObjects/GameObject.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/GameObjects/GameObject.h
${CMAKE_CURRENT_SOURCE_DIR}/src/GameObjects/GameObjectStats.h ${CMAKE_CURRENT_SOURCE_DIR}/src/GameObjects/Obstacle.cpp
${CMAKE_CURRENT_SOURCE_DIR}/src/GameObjects/Obstacle.h ${CMAKE_CURRENT_SOURCE_DIR}/src/GameObjects/Player.cpp
${CMAKE_CURRENT_SOURCE_DIR}/src/GameObjects/Player.h ${CMAKE_CURRENT_SOURCE_DIR}/src/GameObjects/Serializer.h
${CMAKE_CURRENT_SOURCE_DIR}/src/GameObjects/Tile.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/GameObjects/Tile.h
${CMAKE_CURRENT_SOURCE_DIR}/src/GUI/GUIButton.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/GUI/GUIButton.h
${CMAKE_CURRENT_SOURCE_DIR}/src/GUI/GUIElement.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/GUI/GUIElement.h
${CMAKE_CURRENT_SOURCE_DIR}/src/GUI/GUIManager.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/GUI/GUIManager.h
${CMAKE_CURRENT_SOURCE_DIR}/src/GUI/MyGUIManager.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/GUI/MyGUIManager.h
${CMAKE_CURRENT_SOURCE_DIR}/src/Input/Input.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/Input/Input.h
${CMAKE_CURRENT_SOURCE_DIR}/src/Input/MyInputExample.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/Input/MyInputExample.h
${CMAKE_CURRENT_SOURCE_DIR}/src/Interfaces/GameLogicObjectInterface.h ${CMAKE_CURRENT_SOURCE_DIR}/src/Interfaces/MapAreaInterface.h
${CMAKE_CURRENT_SOURCE_DIR}/src/Interfaces/ObjectCommandInterface.h ${CMAKE_CURRENT_SOURCE_DIR}/src/Interfaces/ObjectEventInterface.h
${CMAKE_CURRENT_SOURCE_DIR}/src/Interfaces/ObjectModifierInterface.h
${CMAKE_CURRENT_SOURCE_DIR}/src/Items/EquipSlot.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/Items/EquipSlot.h
${CMAKE_CURRENT_SOURCE_DIR}/src/Items/InventoryManager.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/Items/InventoryManager.h
${CMAKE_CURRENT_SOURCE_DIR}/src/Items/ObjectModifier.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/Items/ObjectModifier.h
${CMAKE_CURRENT_SOURCE_DIR}/src/Items/Sword.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/Items/Sword.h
${CMAKE_CURRENT_SOURCE_DIR}/src/Map/MapArea.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/Map/MapArea.h
${CMAKE_CURRENT_SOURCE_DIR}/src/Map/MapLoader.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/Map/MapLoader.h
${CMAKE_CURRENT_SOURCE_DIR}/src/Map/MapManager.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/Map/MapManager.h
${CMAKE_CURRENT_SOURCE_DIR}/src/Map/MyMapLoader.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/Map/MyMapLoader.h
${CMAKE_CURRENT_SOURCE_DIR}/src/Utility/Global.h ${CMAKE_CURRENT_SOURCE_DIR}/src/Utility/IniParser.cpp
${CMAKE_CURRENT_SOURCE_DIR}/src/Utility/IniParser.h ${CMAKE_CURRENT_SOURCE_DIR}/src/Utility/Utility.h
${CMAKE_CURRENT_SOURCE_DIR}/DesignPatternDemo.cpp ${CMAKE_CURRENT_SOURCE_DIR}/targetver.h)



source_group(TREE ${PROJECT_SOURCE_DIR} FILES ${AllFiles})


add_executable(DPD
    ${AllFiles}
)

include_directories(DPD ${PROJECT_SOURCE_DIR}/src)

target_compile_features(DPD PUBLIC cxx_std_17)


