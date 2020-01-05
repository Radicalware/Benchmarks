#pragma once

// Copyright under the Apache v2 Licence
// Created by Joel Leaugues in 2020

// -------------- STL -------------------
#include <iostream>
using std::cout;
using std::endl;
// -------------- STL -------------------
// ---------- RADICALWARE ---------------
#include "Nexus.h"
#include "xvector.h"
#include "xstring.h"
#include "xmap.h"
// ---------- RADICALWARE ---------------

#include "BaseRex.h"

class STL_Rex : public BaseRex
{
private:


public:
    STL_Rex();
    ~STL_Rex();
    virtual void loop_match();
};