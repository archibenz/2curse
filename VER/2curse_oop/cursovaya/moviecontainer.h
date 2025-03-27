#ifndef MOVIECONTAINER_H
#define MOVIECONTAINER_H

#include "movie.h"
#include "mycontainer.h"
#include <QString>

class MovieContainer {
public:
    void addMovie(const Movie &movie);
    void removeMovie(const QString &title);
    bool editMovie(const QString &title, const Movie &newData);

    MyContainer<Movie> searchByDirector(const QString &director) const;
    MyContainer<Movie> searchByYear(int year) const;

    const MyContainer<Movie> &getAllMovies() const;

    void clear();
    bool saveToFile(const QString &filename) const;
    bool loadFromFile(const QString &filename);
    void mergeWith(const MovieContainer &other);
    int moviesCount() const;

private:
    MyContainer<Movie> movies;
};

#endif // MOVIECONTAINER_H

