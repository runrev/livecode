/* Copyright (C) 2003-2015 LiveCode Ltd.
 
 This file is part of LiveCode.
 
 LiveCode is free software; you can redistribute it and/or modify it under
 the terms of the GNU General Public License v3 as published by the Free
 Software Foundation.
 
 LiveCode is distributed in the hope that it will be useful, but WITHOUT ANY
 WARRANTY; without even the implied warranty of MERCHANTABILITY or
 FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 for more details.
 
 You should have received a copy of the GNU General Public License
 along with LiveCode.  If not see <http://www.gnu.org/licenses/>.  */

#include "prefix.h"

#include "globdefs.h"
#include "filedefs.h"
#include "objdefs.h"
#include "parsedef.h"
#include "mcio.h"

#include "globals.h"
#include "debug.h"
#include "handler.h"

#include "mblsyntax.h"
#include "exec.h"

////////////////////////////////////////////////////////////////////////////////

MC_EXEC_DEFINE_EXEC_METHOD(ToastMessage, ToastMessage, 2)



////////////////////////////////////////////////////////////////////////////////

void MCToastMessage(MCExecContext& ctxt, MCStringRef p_msg, int32_t* p_duration)
{
    int32_t t_duration = 1000;

    if(p_duration != nil)
        t_duration = *p_duration;

    if(MCSystemToastMessage(p_msg, t_duration))
        return;
    
    ctxt.Throw();
}