# COBLL
# Introduction
COBLL is (aspirationally) an LLVM-based compiler for COBOL. 

This project was initially created for a Computer Science Research & Development course at Phillips Academy. 

Doxygen documentation of the code for COBLL can be found in `docs`. A brief and informal text-based description of the layout, focusing on the `Driver` class, can also be found in `Organization.md`. 

# Progress 
COBOL files have four divisions: The Identification Division, Environment Division, Data Division, and Procedure Division. The Identification Division is the only division which is required in every COBOL file.

COBLL currently supports complete compilation of the Identification Division. The Procedure Division has some lexing functionality, and the nodes for the Abstract Syntax Tree generation are complete. Further work will focus on the Procedure Division, eventually moving to the Environment and Data Divisions.

## To-Do
 - [] Procedure Division
	 - [] Handle parsing of Procedure Tokens & AST generation
	 - [] Procedure Division code generation
	 - [] Procedure Division optimization 
 - [] Support Environment Division
 - [] Support Data Division