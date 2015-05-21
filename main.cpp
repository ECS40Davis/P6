// Author: Sean Davis 

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <climits>
#include "list.h"
#include "city.h"
#include "plane.h"
using namespace std;

template <typename T>
void calcAirportTraffic(const List<T> &cities, int index);
template <typename T>
void calcDistance(const List<T> &cities, int index1, int index2, 
                  int *distance, int *passengers, bool display);
template <typename T>
void cleanCities(List<T> &cities);
template <typename T>
int findAirport(const List<T> &cities, const char *airport);
template <typename T>
void readAirports(List<T> &cities);
template <typename T>
void readCities(List<T> &cities);


// DO SOMETHING!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
template <typename T>
void addPlaneInformation(List<T> &planes)
{
  Plane tempPlane;
  tempPlane.getPlane();
  ofstream outf("planes.dat", ios::app | ios::binary);
  outf.write((char*) &planes[planes.getCount()], sizeof(Plane));
  outf.close();
}  // addPlaneInformation()


template <typename T>
void calcDistance(const List<T> &cities)
{
  char airport1[80], airport2[80];
  int index1, index2, distance, passengers;
  cout << "\nPlease enter two airport abbreviations (XXX XXX): ";
  cin >> airport1 >> airport2;
  index1 = findAirport(cities, airport1);
  index2 = findAirport(cities, airport2);

  if (index1 >= 0 && index2 >= 0)
    calcDistance(cities, index1, index2, &distance, &passengers, true);
}  // calcDistance())


template <typename T>
void determineAirportTraffic(const List<T> &cities)
{
  char airport[80];
  int index;
  cout << "\nPlease enter an airport abbreviation (XXX): ";
  cin >> airport;
  index = findAirport(cities, airport);

  if (index >= 0 && index >= 0)
    calcAirportTraffic(cities, index);
}  // determinAirportTraffic()


template <typename T, typename P>
void determineBestPlane(const List<T> &cities, const List<P> &planes)
{
  char airport1[80], airport2[80];
  int index1, index2, distance, passengers, minIndex = -1, minCost = INT_MAX, 
    minTrips, trips, cost;
  cout << "\nPlease enter two airport abbreviations (XXX XXX): ";
  cin >> airport1 >> airport2;
  index1 = findAirport(cities, airport1);
  index2 = findAirport(cities, airport2);

  if (index1 >= 0 && index2 >= 0)
  {
    calcDistance(cities, index1, index2, &distance, &passengers, false);
      
    for (int i = 0; i < planes.getCount(); i++)
    {
       cost = planes[i].calcCost(distance, passengers, &trips);
       
       if (trips > 0 && cost < minCost)
       {
         minTrips = trips;
         minCost = cost;
         minIndex = i;
       }  // if lower cost
    }  // for each plane
    
    if (minIndex == -1)
      cout << "No planes available\n";
    else // else found a plane
    {
      cout << "Passengers Miles  Trips Name      Cost\n";
      cout << left << setw(11) << passengers << setw(7) << distance << setw(6) 
        << minTrips << setw(10) << planes[minIndex].getName() << '$' << minCost 
        << endl;
    } // else found a plane
  }   // if valid inputs  
}  //  determineBestPlane()

template <typename T>
void displayPlaneInformation(const List<T> &planes)
{
  cout << "\nPlane Information\n";
  cout << "Name        Pass. Range Speed Fuel   MPG   $/mi  Price * 10^6\n";
  
  for (int i = 0; i < planes.getCount(); i++)
    cout << planes[i];

}  // displayPlaneInformation()


int getChoice()
{
  int choice;

  do
  {
    cout << "\nFlight Simulator Menu\n";
    cout << "0. Done.\n";
    cout << "1. Determine distance and passengers between two airports.\n";
    cout << "2. Determine all traffic from one airport.\n";
    cout << "3. Display planes information.\n";
    cout << "4. Add plane information.\n";
    cout << "5. Determine best plane between two airports.\n\n";

    cout << "Your choice (0 - 5): ";
    cin >> choice;
    cin.ignore(1000, '\n');
   
    if  (choice < 0 || choice > 5)
      cout << "Your choice must be between 0 and 5. Please try again.\n";
  } while(choice < 0 || choice > 5);
   
  return choice;
}  // getChoice()  


// DO SOMETHING!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
template <typename T>
void readPlanes(List<T> &planes)
{
  Plane tempPlane;
  ifstream inf("planes.dat", ios::binary);
  
  if (! inf)
    return;

  while (inf.read((char*) &tempPlane, sizeof(Plane)))
  {
      planes += tempPlane;
  } // while not the end of the file

  
  inf.close();
} // readPlanes()


template <typename T, typename P>
void run(const List<T> &cities, List<P> &planes)
{
  int choice;
  
//  for(index1 = 0; index1 < cities->List<T>::getCount(); index1++)
//    for(index2 = index1 + 1; index2  < cities->List<T>::getCount(); index2++)
//      calcDistance(cities, index1, index2);

  do
  {
    choice = getChoice();
    
    switch(choice)
    {
      case 1 : calcDistance(cities); break;
      case 2 : determineAirportTraffic(cities); break;
      case 3 : displayPlaneInformation(planes); break;
      case 4 : addPlaneInformation(planes); break;
      case 5 : determineBestPlane(cities, planes); break;
    }  // switch
  } while(choice != 0);
}  // run())

template <typename T>
void calcAirportTraffic(const List<T> &cities, int index)
{
  int total = 0;
  
  for (int i = 0; i < List<T>::getCount(); i++)
    if (i != index)
      total += cities[index].showTraffic(cities[i]);
  
  cout << "Total passengers: " << total << endl;
}  // calcAirportTraffic()


template <typename T>
void calcDistance(const List<T> &cities, int index1, int index2, 
                  int *distance, int *passengers, bool display)
{
  cities[index1].calcDistance( &cities[index2], distance, passengers,
    display);
}  // calcDistance()

template <typename T>
void cleanCities(List<T> &cities)
{
  int i = 0;
  
  while (i < List<T>::getCount())
  {
    if (!cities[i].hasAirport())
      cities -= cities[i];
    else // city has an airport
      i++;
  }  // while more in array
}  // cleanCities())


template <typename T>
int findAirport(const List<T> &cities, const char *airport)
{
  City city;
  
  city.setAirport(airport);
  
  for (int i = 0; i < List<T>::getCount(); i++)
    if (cities[i] == city)
      return i;
  
  cout << airport << " is not a valid airport.\n";
  return -1;
}  // findAirport()


template <typename T>
void readAirports(List<T> &cities)
{
  char line[1000], state2[80];
  City city;
  ifstream inf("airportLL.txt");

  while (inf.getline(line, 1000))
  {
    if (isalpha(line[0]))
      strcpy(state2, strtok(line, "\n"));
    
    if (line[0] == '[')
    {
      city.readAirport(line, state2);
      
      for (int i = 0; i < List<T>::getCount(); i++)
        if (cities[i] == city)
        {
          cities[i].copyLocation(&city);
          break;
        }  // if found a matching name
      
      city.deallocate();
    }  // if an airport line
  }  // while
}  // readAirports()


template <typename T>
void readCities(List<T> &cities)
{
  ifstream inf("citypopulations.csv");
  City city;
  
  while(!inf.eof())
  {
    inf >> city;
    cities += city;
  } // while more in file
  
  inf.close();
}  // readCities()


int main(int argc, char** argv) 
{
  List<City> cities;
  List<Plane> planes;
  readCities(cities);
  readAirports(cities);
  cleanCities(cities);
  
  readPlanes(planes); // DO <--------------------------
 
//  srand(1);
//  for(int i = 0; i < cities.List<T>::getCount(); i++)
//    cout << "1\n" << cities.cities[i].airport << ' ' << cities.cities[rand() % cities.List<T>::getCount()].airport << endl;
//  printf("%s %s %lf %lf\n", cities.cities[i].name, cities.cities[i].airport, cities.cities[i].latitude, cities.cities[i].longitude);
  run(cities, planes);
  return 0;
} // main())

