#ifndef MOVIE_H
#define MOVIE_H

#include <string>

//enum MovieRating {
//    very_bad,
//    bad,
//    ok,
//    good,
//    very_good,
//    excellent,
//};
class Movie
{
    
private:
    std::string m_name;
    std::string m_rating;
    int *m_watched;
    
public:
    Movie(std::string name, std::string rating, int watched = 0);
    Movie(const Movie &source);  // copy constructor
    Movie(Movie &&source) noexcept;  // move constructor 
    ~Movie();
    
    bool operator==(const Movie &other) const;
    
    int getWatched() const {return *m_watched;}
    std::string getRating() const {return m_rating;}
    std::string getName() const {return m_name;}
    void getInfo() const;
    
    void incrementWatchedCount() {++(*m_watched);}
    
};

#endif // MOVIE_H
