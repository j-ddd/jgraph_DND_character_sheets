# jgraph_DND_character_sheets (Jackson Dodd's JGraph Lab)
This program will use Professor Plank's proprietary graphing program to create custom DND character sheets based off a custom input file containing all character information.

# TO USE THIS PROGRAM:
- first, make a djdc file according the specs I have written, or reference one of the pre-written examples.
- Then you can add a section to the Makefile to run that given djdc file just like the others I have listed.
- In case you want to just see the result of some pre-written characters, simply load this repo into a folder on the Hydra/Tesla machines.
- Then type: `make examples`.
- You will then generate five jpgs according to the makefiles referenced djdc files.

# How this works.
- This program first transforms your file from a djdc file format into a populated jgr file with a lot of pre-processing.
- Then it will reference other symbols that are postscripts in the symbols folder.
- It will then turn your jgraph into postscript
- Then postscript to pdf
- Then finally pdf to the resulting jpg character sheet!


- Wish I could've had more time to make it prettier, but in case you really wanted to make a dnd character sheet with no internet on a computer from the 80's, then this is the one for you.
