#include "array_2d.h"

template<typename T>
Array2D<T>::Array2D(size_t _sizeX, size_t _sizeY)
{
    sizeX = _sizeX;
    sizeY = _sizeY;
    items = new T*[_sizeY];
    for(size_t i = 0; i < _sizeY; i++)
        items[i] = new T[_sizeX]();
}
template<typename T>
Array2D<T>::Array2D(size_t _sizeX, size_t _sizeY, T** _items)
{
    sizeX = _sizeX;
    sizeY = _sizeY;
    items = _items;
}

template<typename T>
Array2D<T>::~Array2D()
{
    for(size_t i = 0; i < sizeY; i++)
        delete items[i];
    delete items;
}

template<typename T>
T Array2D<T>::get(size_t x, size_t y)
{
    if(x >= sizeX || y >= sizeY)
        throw QException();
    return items[y][x];
}
template<typename T>
void Array2D<T>::set(size_t x, size_t y, T item)
{
    if(x >= sizeX || y >= sizeY)
        throw QException();
    items[y][x] = item;
}

template<typename T>
T Array2D<T>::getUnsafe(size_t x, size_t y)
{
   return items[y][x];
}
template<typename T>
void Array2D<T>::setUnsafe(size_t x, size_t y, T item)
{
    items[y][x] = item;
}

template<typename T>
T** Array2D<T>::getArray()
{
    return items;
}

