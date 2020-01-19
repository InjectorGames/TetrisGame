#ifndef ARRAY_2D_H
#define ARRAY_2D_H

#include <QException>

template<typename T>
class Array2D
{
public:
    explicit Array2D(size_t sizeX, size_t sizeY);
    explicit Array2D(size_t sizeX, size_t sizeY, T** items);
    ~Array2D();

    T get(size_t x, size_t y);
    void set(size_t x, size_t y, T item);

    T getUnsafe(size_t x, size_t y);
    void setUnsafe(size_t x, size_t y, T item);

    T** getArray();

protected:
    size_t sizeX;
    size_t sizeY;

    T** items;
};

#endif // ARRAY_2D_H
