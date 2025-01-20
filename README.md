# Scotland Yard AI Project
### Created by: Emmet Ritchie, Kennedy Watkins, and Kelly Farran

## Description 
Scotland Yard is a strategy-based board game where one player takes on the role of "Mr. X," a fugitive trying to evade capture, while the remaining players work as detectives, collaborating to track down and capture Mr. X. The game is played on a map of London, with players moving around the board using modes of transportation like taxis, buses, and the underground. Mr. X's location on the board is hidden and is only revealed periodically throughout the game, leaving the detectives to work together and strategize in order to achieve their capture of Mr. X. 

This project is an implementation of Scotland Yard in which the user plays as Mr. X, while the five detectives are controlled by our AI. The user is prompted with available locations to move to on the board, and after selecting a desired move, the detectives respond accordingly, using different intelligent strategies to attempt to trap Mr. X. 

## AI Implementation
The strategies used by the detectives are implemented in the DetectiveStrategy class. Depending on several factors, a different strategy is used in order to determine a detective move which is optimal in the fight to track down Mr. X. 
- If the game has just begun, Mr. X's location has not yet been revealed, and will not be revealed until round 3. Thus, the optimal location for a detective to be at on the start of round 3 is an underground station, as underground stations allow for the most mobility around the board
    - If the game is in round 1 and a detective can reach an underground station in 2 moves, the DetectiveStrategy class recognizes this as an optimal situation, and moves the detective one station in the direction of the underground station
    -  If the game is in round 2 and a detective can reach an underground station in 1 move, the DetectiveStrategy recognizes this as an optimal situation, and moves the detective to that underground station

- If the game has progressed past round 3, Mr. X's location has been revealed at least once. Thus, the GameManager class begins to keep track of all of the possible places that Mr. X could be on the board
   - The possible locations of Mr. X are stored in a tree, where the leaves of the tree are the _current_ possible locations of Mr. X 
   - Each round, the tree is expanded by setting the children of each leaf to be the set of next possible locations available from that leaf
   - Potential child stations that are occupied by another player or are not reachable with the tickets held by the current detective are not added to the tree, pruning the tree
   - Whenever Mr. X's location is revealed, the tree of possible locations resets, with the root becoming the newly revealed actual location of Mr. X

- When a tree of possible Mr. X locations is available, the optimal move for a detective is the move which places that detective closer to the current closest possible Mr. X location
- The distance between a detective and each of the current possible Mr. X locations (leaves of the tree) is assessed, and a closest to station is determined using Dijkstra's Shortest Path Algorithm. The detective then moves to the next available station which places them on track to reach the closest possible Mr. X location 

![Scotland_Yard_schematic svg](https://github.com/user-attachments/assets/c320787c-1991-44aa-84d8-955aaa8bcaec)

## Installation
 
### Prerequisites 
  1.  A C++ compiler
       - On Windows, it is recommended to install [MinGW](https://sourceforge.net/projects/mingw/) 
       - On macOS Clang is usually pre-installed
       - on Linux, GCC is usually pre-installed
  2. Clone this repository into a folder on your machine
       - Open git bash in the desired folder
       - run _git clone https://github.com/klfarran/CS340-Scotland-Yard.git_
    
### Running to game 
1. To compile and run using the command line
      - Open the command line and navigate to the folder of the local respository: run _cd ... /CS340-Scotland-Yard_
      - Compile with g++ on the command line: _g++ DetectiveStrategy.cpp Station.cpp edgefile.cpp Player.cpp GameManager.cpp TreeNode.cpp main.cpp_
      - To run: _./a.exe_


## Presentation Slides
- To view the slides for our presentation of this project, click [here](https://docs.google.com/presentation/d/1AkV6VcrvW1jwjzHmBKtxypRH5w-EuiqhbiH3LU5Re7s/edit?usp=sharing)
