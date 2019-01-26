#include <iostream>
#include "Movie.h"


Movie::Movie(std::string name, std::string rating, int watched)    
    : m_name(name), m_rating(rating) {
        m_watched = new int;
        *m_watched = watched;
}

Movie::Movie(const Movie &source) 
    : Movie(source.m_name, source.m_rating, *source.m_watched)
{
    std::cout << "Movie - Copy constructor" << std::endl;
}

// move constructor
Movie::Movie(Movie &&source) noexcept
    : m_name(source.m_name), m_rating(source.m_rating), m_watched(source.m_watched)
{
    source.m_watched = nullptr;
    std::cout << "Movie - Move constructor" << std::endl;
}

Movie::~Movie()
{
    delete m_watched;
}

bool Movie::operator==(const Movie &other) const {
    if (m_name == other.getName()) {
        return true;
    }
    return false;
}


void Movie::getInfo() const {
    std::cout << "Movie(";
    std::cout << "Name: " << m_name << ", ";
    std::cout << "Rating: " << m_rating << ", ";
    std::cout << "Watched: " << *m_watched << ", ";
    std::cout << "Address: " << m_watched << ")" << std::endl;
}


