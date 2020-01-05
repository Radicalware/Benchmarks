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
#include "Timer.h"
// ---------- RADICALWARE ---------------



class BaseRex
{
protected:
    Timer m_timer;

    const int m_max_loop = 1000;
    bool m_printed = false;

    xvector<xstring> m_emails;
    const char* m_regex_str = R"(^name\.([\w]{0,1}[cCbBaA](s7|st|sT))\@([yo0Og](ahoo|utlook|mail))\.(999).com$)";
    //const char* m_regex_str = R"(.*999.*)";
public:
    typedef BaseRex value_type; // required for Nix
    BaseRex();
    ~BaseRex();

    void allocate_email_list();

    virtual void loop_match() { throw "Acting Abstract Class"; };

};