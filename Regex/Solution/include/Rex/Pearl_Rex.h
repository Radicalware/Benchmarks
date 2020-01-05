#pragma once
//#pragma comment(lib, "C:/Source/CMake/Radicalware/Libraries/Build/Release/lib/pcre.lib")

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
//  pcre.h    pcrecpp.h    pcrecpparg.h    pcreposix.h    pcre_scanner.h    pcre_stringpiece.h
#include "pcre.h"               /* PCRE lib        NONE  */
//#include "pcrecpp.h"
//#include "pcrecpp.h"
//#include "pcreposix.h"
//#include "pcre_scanner.h"
//#include "pcre_stringpiece.h"

#include <stdio.h>              /* I/O lib         C89   */
#include <stdlib.h>             /* Standard Lib    C89   */
#include <string.h>             /* Strings         C89   */


class Pearl_Rex : public BaseRex
{
private:
    struct Rex
    {
        pcre *obj;
        xstring rex;
        pcre_extra* extra;
        const char* error_str;
        int error_offset;
        int result;

        Rex(const char* str){
            this->set(str);
        }

        void set(const char* str)
        {
            rex = str;
            this->obj = pcre_compile(this->rex.c_str(), 0, &this->error_str, &this->error_offset, NULL);

            /* pcre_compile OPTIONS (second argument) (||'ed together) can be:
                PCRE_ANCHORED       -- Like adding ^ at start of pattern.
                PCRE_CASELESS       -- Like m//i
                PCRE_DOLLAR_ENDONLY -- Make $ match end of string regardless of \n's
                                        No Perl equivalent.
                PCRE_DOTALL         -- Makes . match newlins too.  Like m//s
                PCRE_EXTENDED       -- Like m//x
                PCRE_EXTRA          -- 
                PCRE_MULTILINE      -- Like m//m
                PCRE_UNGREEDY       -- Set quantifiers to be ungreedy.  Individual quantifiers
                                        may be set to be greedy if they are followed by "?".
                PCRE_UTF8           -- Work with UTF8 strings.
            */        
            if(this->obj == nullptr)
            {
                throw std::runtime_error("! (pcre_compile) Failed to Compile!\n");
            }
            extra = pcre_study(this->obj, 0, &this->error_str);
            if(error_str != nullptr)
            {
                auto err = xstring("ERROR: Could not study ") + rex + " : " +  this->error_str;
                throw std::runtime_error(err.c_str());
            }
            
        }

        bool match(const xstring& str)
        {
            int* str_match = new int[str.size()];
            result = pcre_exec(this->obj,
                                this->extra,
                                str.c_str(), 
                                str.size(),  // length of string
                                0,           // Start looking at this point
                                0,           // OPTIONS
                                str_match,
                                str.size()   // Length of str_match
            );                   

            delete[] str_match;
            if(result < 0)
                return false;
            else
                return true;

        }

        ~Rex()
        {
            if(this->obj != nullptr)
                pcre_free(this->obj);
                
            // Free up the EXTRA PCRE value (may be NULL at this point)
            if(this->extra != nullptr) 
            {
                #ifdef PCRE_CONFIG_JIT
                    pcre_free_study(this->extra);
                #else
                    pcre_free(this->extra);
                #endif
            }
        }
    };

public:
    Pearl_Rex();
    ~Pearl_Rex();
    virtual void loop_match();
};