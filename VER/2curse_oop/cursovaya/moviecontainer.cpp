#include "moviecontainer.h"
#include <QFile>
#include <QDataStream>

void MovieContainer::addMovie(const Movie &movie) {
    movies.push_back(movie);
}

void MovieContainer::removeMovie(const QString &title) {
    movies.erase_if([&title](const Movie &m){ return m.getTitle() == title; });
}

bool MovieContainer::editMovie(const QString &title, const Movie &newData) {
    for (auto it = movies.begin(); it != movies.end(); ++it) {
        if (it->getTitle() == title) {
            it->setTitle(newData.getTitle());
            it->setDirector(newData.getDirector());
            it->setYear(newData.getYear());
            it->setGenre(newData.getGenre());
            return true;
        }
    }
    return false;
}

MyContainer<Movie> MovieContainer::searchByDirector(const QString &director) const {
    MyContainer<Movie> result;
    for (auto it = movies.begin(); it != movies.end(); ++it) {
        if (it->getDirector() == director) {
            result.push_back(*it);
        }
    }
    return result;
}

MyContainer<Movie> MovieContainer::searchByYear(int year) const {
    MyContainer<Movie> result;
    for (auto it = movies.begin(); it != movies.end(); ++it) {
        if (it->getYear() == year) {
            result.push_back(*it);
        }
    }
    return result;
}

const MyContainer<Movie> &MovieContainer::getAllMovies() const {
    return movies;
}

void MovieContainer::clear() {
    movies.clear();
}

bool MovieContainer::saveToFile(const QString &filename) const {
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly))
        return false;
    QDataStream out(&file);
    out << moviesCount();
    for (auto it = movies.begin(); it != movies.end(); ++it) {
        out << *it;
    }
    return true;
}

bool MovieContainer::loadFromFile(const QString &filename) {
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly))
        return false;
    QDataStream in(&file);
    int count;
    in >> count;
    movies.clear();
    for (int i=0; i<count; ++i) {
        Movie m;
        in >> m;
        movies.push_back(m);
    }
    return true;
}

void MovieContainer::mergeWith(const MovieContainer &other) {
    for (auto it = other.getAllMovies().begin(); it != other.getAllMovies().end(); ++it) {
        movies.push_back(*it);
    }
}

int MovieContainer::moviesCount() const {
    return movies.size();
}

