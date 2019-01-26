#include <vector>
#include <algorithm>
#include <iostream>

#include "Movie.h"
#include "Movies.h"


Movies::Movies()
{
}

Movies::~Movies()
{
}

bool Movies::addMovie(Movie &new_movie) {
    // first, check wheter new_movie already exists
    if (std::find(m_collection.begin(), m_collection.end(), new_movie) != m_collection.end()) {
        std::cout << new_movie.getName() << " has already been added!" << std::endl;
        return true;
    }
    std::cout << "Adding - " << new_movie.getName() << " -"<< std::endl;
    m_collection.push_back(new_movie);
    return false;
}

bool Movies::incrementWatchedCount(std::string &movie_name) {
    for (Movie &movie : m_collection) {
        if (movie.getName() == movie_name) {
            movie.incrementWatchedCount();
            return true;
        }
    }
    return false;
}


void Movies::displayAll() const {
    std::cout << "\n======================================= " << std::endl;
    for (const Movie &m : m_collection) {
        m.getInfo();
    }
    std::cout << std::endl;
    std::cout << "=======================================" << std::endl;
}
