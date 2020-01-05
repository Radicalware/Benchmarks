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

#include "re2/re2.h"


class re2_Rex : public BaseRex
{
public:
    re2_Rex();
    ~re2_Rex();
    virtual void loop_match();
};