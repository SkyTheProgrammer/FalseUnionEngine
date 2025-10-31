// //
// // Created by SkyTFB on 10/6/2025.
// //
// #pragma once
//
// namespace FalseUnion
// {
//     class Colour {
//     public:
//         Colour(); // default colour constructor
//         Colour(unsigned short int newR = 0, unsigned short int newG = 0, unsigned short int newB, unsigned short int newA); // colour constructor with ints for values
//         virtual ~Colour(); // virtual destructor for use in case of inheratence
//         //
//         void setR(unsigned short int newR);
//         void setG(unsigned short int newG);
//         void setB(unsigned short int newB);
//         void setA(unsigned short int newA) const;
//         unsigned short int getR() const;
//         unsigned short int getG() const;
//         unsigned short int getB() const;
//         unsigned short int getA() const;
//         // getters and setters for r g b and a
//
//     private:
//         unsigned short int r; //int representing red
//         unsigned short int g; //int representing green
//         unsigned short int b; //int representing blue
//         unsigned short int a; //int representing alpha
//
//         //move to a colour implementation that fits better with GLFW
//         //move colour to a header only file.
//     };
// }
