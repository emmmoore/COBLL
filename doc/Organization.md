The COBLL compiler is run primarily through `COBLL.cpp`, which contains `main`. 
To use, the executable is run from the terminal with file names as command-line arguments.

A Driver (see `Driver.h`, `Driver.cpp`) is created for each file name supplied, and 
the file undergoes a first pass as it is constructed,  in which the Driver locates each 
COBOL Division within the file. After it is constructed, control goes to `DriverMain`,
which, for each division present within the file, calls that division's handler. 
Division handlers have their own files, named `IdentificationHandler.cpp`, etc. 
They are all methods within the Driver so they can share data. The division handlers, 
since they are so different, are not part of a hierarchy that shares any functionality.
For instance, the IdentificationHandler uses key-value pairs, while the Procedure Division
relies on tokens as well as column information.