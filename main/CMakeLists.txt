cmake_minimum_required(VERSION 3.4.1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/../SDL2/include

        # SDL_internal.h is located in src required by SDL_android_main.c bridge
        ${CMAKE_CURRENT_SOURCE_DIR}/../SDL2/src

        ${CMAKE_CURRENT_SOURCE_DIR}/../SDL2_image/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../SDL2_gfx/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../SDL2_mixer/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../SDL2_ttf/include
)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../SDL2/ ${CMAKE_CURRENT_SOURCE_DIR}/../SDL2)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../SDL2_image/ ${CMAKE_CURRENT_SOURCE_DIR}/../SDL2_image)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../SDL2_gfx/ ${CMAKE_CURRENT_SOURCE_DIR}/../SDL2_gfx)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../SDL2_mixer/ ${CMAKE_CURRENT_SOURCE_DIR}/../SDL2_mixer)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../SDL2_ttf/ ${CMAKE_CURRENT_SOURCE_DIR}/../SDL2_ttf)

add_library(
        main-lib

        SHARED

        # Provides a relative path to your source file(s).
        src/BlueUp.cpp
        src/Box_Medal.cpp
        src/Box_PowerUp.cpp
        src/Enemy.cpp
        src/Enemy_Bonus_Ship.cpp
        src/Enemy_Boss_Cannon.cpp
        src/Enemy_Boss_Left_Wing.cpp
        src/Enemy_Boss_Main.cpp
        src/Enemy_Boss_Right_Wing.cpp
        src/Enemy_Grey_Tank.cpp
        src/Enemy_Kamikaze.cpp
        src/Enemy_Light_Shooter.cpp
        src/Enemy_Light_Shooter_Kamikaze.cpp
        src/Enemy_Long_Megatank.cpp
        src/Enemy_Medium_Shooter.cpp
        src/Enemy_Megatank.cpp
        src/Enemy_Mine.cpp
        src/Enemy_Ship.cpp
        src/Enemy_Ship_Tank.cpp
        src/Enemy_Train_Coach.cpp
        src/Enemy_Train_Locomotive.cpp
        src/Medals.cpp
        src/MissileUp.cpp
        src/ModuleAudio_2.cpp
        src/ModuleCollision.cpp
        src/ModuleEnemies.cpp
        src/ModuleFadeToBlack.cpp
        src/ModuleGroundEnemies.cpp
        src/ModuleGroundExplosion.cpp
        src/ModuleMap1.cpp
        src/ModuleMap2.cpp
        src/ModuleParticles.cpp
        src/ModulePlayer.cpp
        src/ModulePlayer2.cpp
        src/ModulePowerUps.cpp
        src/ModuleShadows.cpp
        src/ModuleStageClear1.cpp
        src/ModuleWelcomeScreen.cpp
        src/Player.cpp
        src/PowerUp.cpp
        src/RedUp.cpp
        src/Tank.cpp
        src/Turret.cpp
        src/log.cpp
        src/Globals.cpp
        src/ModuleTextures.cpp
        src/main.cpp
        src/ModuleWindow.cpp
        src/ModuleAudio_1.cpp
        src/ModuleRender.cpp
        src/ModuleFonts.cpp
        src/Application.cpp
        src/ModuleInput.cpp
        src/SDL_android_main.c )


find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log )



target_link_libraries( # Specifies the target library.
        main-lib
        SDL2
        SDL2_image
        SDL2_gfx
        SDL2_mixer
        SDL2_ttf

        ${log-lib} )
