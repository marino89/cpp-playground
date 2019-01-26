#ifndef MOVIES_H
#define MOVIES_H
#include <vector>
#include <string>
#include "Movie.h"


class Movies
{
private:
    std::vector<Movie> m_collection;
    
public:
    Movies();
    ~Movies();
    
    bool addMovie(Movie &new_movie);
    bool incrementWatchedCount(std::string &movie_name);
    void displayAll() const;
    std::size_t getTotalNumber() const {return m_collection.size();}

};

#endif // MOVIES_H
