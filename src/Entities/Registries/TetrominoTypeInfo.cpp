#include "TetrominoTypeInfo.h"

TetrominoTypeInfo::TetrominoTypeInfo() 
        : id(0), name(""), description(""), defaultColor(1), 
          canRotate(true), rotatorType("") {}
          
TetrominoTypeInfo::TetrominoTypeInfo(int _id, const std::string& _name, const std::string& _desc, int _color, bool _canRotate, const std::string& _rotatorType)
        : id(_id), name(_name), description(_desc), defaultColor(_color),
          canRotate(_canRotate), rotatorType(_rotatorType) {}