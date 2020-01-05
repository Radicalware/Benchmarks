#pragma once

#ifdef __unix__

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

#include <iostream>
#include <vector>

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>


class C_Rex : public BaseRex
{
private:

public:
    C_Rex();
    ~C_Rex();

    virtual void loop_match();
};

#endif