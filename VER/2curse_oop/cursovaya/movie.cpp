#include "movie.h"

QDataStream &operator<<(QDataStream &out, const Movie &m) {
    out << m.getTitle() << m.getDirector() << m.getYear() << m.getGenre();
    return out;
}

QDataStream &operator>>(QDataStream &in, Movie &m) {
    QString title, director, genre;
    int year;
    in >> title >> director >> year >> genre;
    m.setTitle(title);
    m.setDirector(director);
    m.setYear(year);
    m.setGenre(genre);
    return in;
}
