#include <stdio.h>
#include <string>
#include <iostream>
#include "Movie.h"
#include "Movies.h"

int main(int argc, char **argv)
{
    Movie m1("Interstellar", "Great", 2);
    m1.getInfo();
    std::cout << std::endl;
    
    std::cout << "Creating Movies object" << std::endl;
    Movies my_movies;
    my_movies.addMovie(m1);
    my_movies.addMovie(m1);
    
    
    my_movies.displayAll();
    
    std::string movie_name = "Interstellar";
    my_movies.incrementWatchedCount(movie_name);
    my_movies.incrementWatchedCount(movie_name);
    my_movies.displayAll();
    
    
    m1.getInfo();
	
    m1.incrementWatchedCount();
    m1.getInfo();
    
//   my_movies.addMovie(Movie("Admiral", "Great", 1));
    
    return 0;
}
