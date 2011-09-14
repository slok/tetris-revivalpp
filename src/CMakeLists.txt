#
# Tetris revival++ cmake build script
# (C) 2011 - Xabier (sLoK) Larrakoetxea <slok69@gmail.com>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program; if not, see <http://www.gnu.org/licenses/>.
#

#A variable of the folder for clearness
set(SRC_ROOT_UTIL ${PROJECT_SOURCE_DIR}/src)


#Set all the sources to build
set(SRC_SRC
    #${SRC_ROOT_UTIL}/Ayuda.cpp
    #${SRC_ROOT_UTIL}/Tetris_Revival___v0_1Main.h  
    ${SRC_ROOT_UTIL}/cMatriz.h    
    ${SRC_ROOT_UTIL}/cPieza.h         
    ${SRC_ROOT_UTIL}/uContenedor.h  
    ${SRC_ROOT_UTIL}/uImagenes.h
    #${SRC_ROOT_UTIL}/Ayuda.h                        
    ${SRC_ROOT_UTIL}/cBloque.cpp                  
    ${SRC_ROOT_UTIL}/cMusica.cpp  
    ${SRC_ROOT_UTIL}/cPuntuacion.cpp  
    ${SRC_ROOT_UTIL}/uFicheros.cpp  
    ${SRC_ROOT_UTIL}/uMain.cpp
    ${SRC_ROOT_UTIL}/cBloque.h                    
    ${SRC_ROOT_UTIL}/cMusica.h    
    ${SRC_ROOT_UTIL}/cPuntuacion.h    
    ${SRC_ROOT_UTIL}/uFicheros.h    
    ${SRC_ROOT_UTIL}/uMain.h
    #${SRC_ROOT_UTIL}/Tetris_Revival___v0_1App.cpp   
    ${SRC_ROOT_UTIL}/cInsercionString.cpp         
    ${SRC_ROOT_UTIL}/cNivel.cpp   
    ${SRC_ROOT_UTIL}/main.cpp         
    ${SRC_ROOT_UTIL}/uFuentes.cpp   
    ${SRC_ROOT_UTIL}/uMenu.cpp
    #${SRC_ROOT_UTIL}/Tetris_Revival___v0_1App.h     
    ${SRC_ROOT_UTIL}/cInsercionString.h           
    ${SRC_ROOT_UTIL}/cNivel.h     
    ${SRC_ROOT_UTIL}/main.h           
    ${SRC_ROOT_UTIL}/uFuentes.h     
    ${SRC_ROOT_UTIL}/uMenu.h
    #${SRC_ROOT_UTIL}/Tetris_Revival___v0_1Main.cpp  
    ${SRC_ROOT_UTIL}/cMatriz.cpp                  
    ${SRC_ROOT_UTIL}/cPieza.cpp   
    ${SRC_ROOT_UTIL}/uContenedor.cpp  
    ${SRC_ROOT_UTIL}/uImagenes.cpp  
    #${SRC_ROOT_UTIL}/wx_pch.h
    ${SRC_ROOT_UTIL}//iniciar.cpp
)

#SET(wxWidgets_USE_LIBS base core)

#Find pthreads dependency, sqlite and dl (we need it)
find_package(SDL REQUIRED)
find_package(SDL_image REQUIRED)
find_package(SDL_sound REQUIRED)
find_package(SDL_mixer REQUIRED)
find_package(SDL_ttf REQUIRED)
#find_package(wxWidgets)

#set the needed headers
set(INCLUDE_DIRS
    ${SDL_INCLUDE_DIR}
    ${SDLIMAGE_INCLUDE_DIR}
    ${SDLSOUND_INCLUDE_DIR}
    ${SDLMIXER_INCLUDE_DIR}
    ${SDLTTF_INCLUDE_DIR}
    #${wxWidgets_INCLUDE_DIRS}
    #${wxWidgets_USE_FILE}
)

set(DEPEND_LIBS
    ${SDL_LIBRARY}
    ${SDLIMAGE_LIBRARY}
    ${SDLSOUND_LIBRARY}
    ${SDLMIXER_LIBRARY}
    ${SDLTTF_LIBRARY}
    #${wxWidgets_LIBRARIES}
)
include_directories(${INCLUDE_DIRS})


add_executable(tetrisRevivalpp ${SRC_SRC})

#Link the libs that require

target_link_libraries(tetrisRevivalpp ${DEPEND_LIBS})

