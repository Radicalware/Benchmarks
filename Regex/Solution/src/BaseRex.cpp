
#include "BaseRex.h"


BaseRex::BaseRex()
{
    this->allocate_email_list();
}

BaseRex::~BaseRex()
{
    
}

void BaseRex::allocate_email_list()
{
    for (int i = 0; i < m_max_loop; i++)
        m_emails << (xstring("name.last@gmail.") + to_xstring(i) + ".com");
}

