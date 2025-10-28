#include "fupch.h"
 #include "../../Headers/Layer/Layer.h"

 namespace FalseUnion
 {
     /// <summary>
     /// Constructor for layer can intake name. 
     /// </summary>
     /// @param name string&, string for the layers debug name.
     Layer::Layer(const std::string& name)
     {
         m_DebugName = name;
     }

     Layer::~Layer() = default; // set to default destructor for now


 }
