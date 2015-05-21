# P6
Flights are added so that they pass through multiple airports.

Completed:
- Created a template (2)
- Create a sorted list for City (3)

To do:
- Change Plane to template

References:
- 

**Again, this looks way better in edit mode**

Convert CityList and CityNode to templace classes List and ListNode
  Copy citylist.h to list.h
  Copy citylist.cpp to list.cpp
    Global search/replace
      Will need <T>
      Change ListNode data members' name from city to data
      #include "list.cpp" in list.h
  Remove any reference to citylist.o in Makefile.
    Wherever citylist.h is mentioned, change to list.h and follow with list.cpp
    Adjust class names to List<T> and ListNode<T>
    In main.cpp, global replace
Make city list sorted by population from largest to smallest
  Utilize < operator of data in += of List
  Remove tail pointer from List class
  Add overloaded < operator to City
Make Planes array a List<Plane> that is sorted by name.
  Add operator < to Plane class that compares the names of the planes.
  Don't pass number of planes in list
  addPlaneInformation() and readPlanes() need to utilize local Plane variable
Create empty Airport class that is publicly derived from City
  change private data in City to protected
  gloabl search and replace any mention of City in main.cpp to Airport
  Remove #include "city.h" and #include "airport.h" from main.cpp
Enhance Airport class so it can store information contained in airline file whose name is passed as a command line argument
  Airline file format::
    Ignore first ten lines.
    Origin Airport, # of flights from airport, airline/destination airport pairs
    Seven airlines: United, Delta, Alaska, Southwest, JetBlue, SkyWest, Virgin
Add List<Flight> to Airport to keep track of flights of airlines from it.
  Create Flight class in airport.h that has Airport as a friend
  Write overloaded < for Flight ((6.2.2     will be tricky))
Add readAirlines() to main.cpp that is called from main()
  This will read and insert flight information into Airport list
      Sean only reads origin in readAirlines(). The rest is read in an Airport method
Add option to menu to print out airport abbreviations and their flights.
  Add overloaded << operator friends to List, Airport, Flight classes so that run() in main.cpp only needs to have cout
  << operator takes List<T> as parameter must be friend of List and ListNode classes. ((7.2      also will be tricky))
Add option in menu to find route between two airports that calls determineRoute() of main.cpp
  Assume user will enter valid airports and airline, though there may not be a route
  Make count and getCount() non-static
  get rid of declaration of count at the top of list.cpp
  Initialize count to zero in List constructor
  If getCount called with class name, change them to actually using a List object
    Sean had 4 instances of this
  Call recurisve Airport function called findRoute() that takes original List<Airport> cities, List<Flight> and others. This   will require playing with operator< of Flight class.
