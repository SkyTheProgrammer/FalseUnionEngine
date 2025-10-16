//
// Created by SkyTFB on 10/6/2025.
//
#pragma once

namespace FalseUnion
{
    class FALSEUNION_API Colour
    {
    public:
        Colour(); // default colour constructor
        Colour(int newR, int newG, int newB, int newA); // colour constructor with ints for values
        virtual ~Colour(); // virtual destructor for use in case of inheratence
        //
        void setR(int newR);
        void setG(int newG);
        void setB(int newB);
        void setA(int newA);
        int getR();
        int getG();
        int getB();
        int getA();
        // getters and setters for r g b and a

    private:
        int r; //int representing red
        int g; //int representing green
        int b; //int representing blue
        int a; //int representing alpha
    };
}
