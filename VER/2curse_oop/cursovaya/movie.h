#ifndef MOVIE_H
#define MOVIE_H

#include <QString>
#include <QDataStream>

class Movie {
public:
    Movie() : year(0) {}
    Movie(const QString &title, const QString &director, int year, const QString &genre)
        : title(title), director(director), year(year), genre(genre) {}

    QString getTitle() const { return title; }
    QString getDirector() const { return director; }
    int getYear() const { return year; }
    QString getGenre() const { return genre; }

    void setTitle(const QString &newTitle) { title = newTitle; }
    void setDirector(const QString &newDirector) { director = newDirector; }
    void setYear(int newYear) { year = newYear; }
    void setGenre(const QString &newGenre) { genre = newGenre; }

private:
    QString title;
    QString director;
    int year;
    QString genre;
};

// Для сериализации в QDataStream
QDataStream &operator<<(QDataStream &out, const Movie &m);
QDataStream &operator>>(QDataStream &in, Movie &m);

#endif // MOVIE_H

