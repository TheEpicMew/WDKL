# WDKL (Windows Driver Kernel Level)

* `DriverObject`: Contains a set of pointers to driver routines
* `IoCreateDevice`: Allocates and initializes a device object for the driver
* `DriverUnload`: Cleans up driver

* `Driver Entry`: Sets up driver structures, like the dispatch table and device objects
------------------------------------------------
# How to compile

* Install the WDK and make sure that the project is configured to build for x64 or x86
* Create a new Kernel Mode Driver project
* Add the entry.cpp, main.cpp, and includes.h files to the project
* Build the driver using the WDK environment
------------------------------------------------
# Note

To load the driver, the driver needs to have a digital signature
If the driver is not signed, you will need to disable Driver Signature Enforcement (DSE)
------------------------------------------------
# How to install (without OSR loader)

* Open Command Prompt as Administrator
* Create a service for the driver: `sc create Driver type= kernel binPath= "enter path here"`
* Start driver: `sc start Driver`
------------------------------------------------
# How to unload

* Stop driver: `sc stop Driver`
* Delete service: `sc delete Driver`
------------------------------------------------

# I'd appreciate if you star this project!
