/* 
* Displays cities alongside their latitude and longitude
* In a chart formation, neatly spaced.
* Then, for each city, it lists the direction it is 
* from every single other city in the list.
* 
* M. Ivanov June 30, 2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct city 
{
    char name [20];
    double latitude;
    double longitude;
};

//displays the cities
void display_city(struct city city)
{
    char s[50]; //used for counting the number of characters used in latitude
    int whitespace = 20;
    printf("%s",city.name);

    //used to create an imaginary column seperating the city from the direction
    for(int x=0; x< strlen(city.name); x++)
    {
        whitespace --;
    }
    for(int x = 0; x < whitespace; x++)
    {
        printf(" ");
    }
    printf(" | ");

    //used to cast the double as a string
    sprintf(s,"%0.2f", city.latitude);
    printf("%0.2f\u00b0", city.latitude); //i am not sure if the degree sign will work
    whitespace = 6;

    //casted double is now used to find the length of it
    //make it look good and well spaced in product
    for(int x=0; x< strlen(s); x++)
    {
        whitespace--;
    }
    for(int x = 0; x < whitespace; x++)
    {
        printf(" ");
    }
    printf(" | ");
    printf("%0.2f\u00b0",city.longitude); //i am not sure if the degree sign will work
    
}

//displays direction to a city
void display_direction_to(struct city destination_city, struct city starting_city)
{
    if (starting_city.latitude > destination_city.latitude)
    {
        printf("north");
    }
    else if (starting_city.latitude < destination_city.latitude)
    {
        printf("south");
    }
    if (starting_city.longitude > destination_city.longitude)
    {
        printf("east");
    }
    else if (starting_city.longitude < destination_city.longitude)
    {
        printf("west");
    }

    
    printf(" of %s", destination_city.name);

}

int main(void)
{  
    //lists all of the cities
    struct city cities[] = 
    {
        {"Paris", 48.85, 2.35},
        {"Antananarivo", -18.933, 47.517},
        {"Reno", 39.517	, -119.817},
        {"Los Angeles", 34.050, -118.250},
        {"Detroit", 42.333, -83.033},
        {"Windsor (Ontario)", 42.283, -83.000},
    };
    //prints the cities themselves
    for(int x =0; x<6; x++)
    {
        display_city(cities[x]);
        printf("\n");
    }
    //prints the info - first outer loop is the starting city
    for(int x =0; x<6; x++)
    {
        printf("%s is ...\n",cities[x].name);
        for(int y = 0; y <6; y++)//inner loop is the collecitn of cities travelled to from start
        {
            if(x!=y)
            {
                printf("    ");
                display_direction_to(cities[y],cities[x]);
                printf("\n");
            }
        }
        printf("\n");
    }
}
