//
// Created by SkyTFB on 10/7/2025.
//

#include "../../Headers/Graphics/Colour.h"

namespace FalseUnion
{
    /// <summary>
    /// Default constructor for colour, sets r, g, b, and a equal to 0
    /// </summary>
    Colour::Colour()
    {
        r = 0;
        g = 0;
        b = 0;
        a = 0;
    }

    /// <summary>
    /// Default virtual deconstructor for colour in case of inheritance.
    /// </summary>
    Colour::~Colour() = default;

    /// <summary>
    /// Colour constructor with params for r, g, b and a
    /// </summary>
    /// @param newR int, sets the r value to match this int.
    /// @param newG int, sets the g value to match this int.
    /// @param newB int, sets the b value to match this int.
    /// @param newA int, sets the a value to match this int.
    Colour::Colour(int newR, int newG, int newB, int newA)
    {
        r = newR;
        g = newG;
        b = newB;
        a = newA;
    }

    /// <summary>
    /// Setter for r
    /// </summary>
    /// @param newR int, the int representing hte new value of r
    void Colour::setR(int newR)
    {
        r = newR;
    }

    /// <summary>
    /// Setter for G
    /// </summary>
    /// @param newG int, the int representing hte new value of g
    void Colour::setG(int newG)
    {
        g = newG;
    }

    /// <summary>
    /// Setter for b
    /// </summary>
    /// @param newB int, the int representing hte new value of b
    void Colour::setB(int newB)
    {
        b = newB;
    }

    /// <summary>
    /// Setter for a
    /// </summary>
    /// @param newA int, the int representing hte new value of a
    void Colour::setA(int newA)
    {
        a = newA;
    }

    /// <summary>
    /// Returns the int value for r
    /// </summary>
    int Colour::getR()
    {
        return r;
    }

    /// <summary>
    /// Returns the int value for g
    /// </summary>
    int Colour::getG()
    {
        return g;
    }

    /// <summary>
    /// Returns the int value for b
    /// </summary>
    int Colour::getB()
    {
        return b;
    }

    /// <summary>
    /// Returns the int value for a
    /// </summary>
    int Colour::getA()
    {
        return a;
    }
}
