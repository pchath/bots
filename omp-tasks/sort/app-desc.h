/**********************************************************************************************/
/*  This program is part of the Barcelona OpenMP Tasks Suite                                  */
/*  Copyright (C) 2009 Barcelona Supercomputing Center - Centro Nacional de Supercomputacion  */
/*  Copyright (C) 2009 Universitat Politecnica de Catalunya                                   */
/*                                                                                            */
/*  This program is free software; you can redistribute it and/or modify                      */
/*  it under the terms of the GNU General Public License as published by                      */
/*  the Free Software Foundation; either version 2 of the License, or                         */
/*  (at your option) any later version.                                                       */
/*                                                                                            */
/*  This program is distributed in the hope that it will be useful,                           */
/*  but WITHOUT ANY WARRANTY; without even the implied warranty of                            */
/*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                             */
/*  GNU General Public License for more details.                                              */
/*                                                                                            */
/*  You should have received a copy of the GNU General Public License                         */
/*  along with this program; if not, write to the Free Software                               */
/*  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA            */
/**********************************************************************************************/

#include "omp-tasks-app.h"

#define BOTS_APP_NAME "Sort"
#define BOTS_APP_PARAMETERS_DESC "N=%d:"
#define BOTS_APP_PARAMETERS_LIST ,bots_arg_size

#define BOTS_APP_USES_ARG_SIZE
#define BOTS_APP_DEF_ARG_SIZE (32*1024*1024)
#define BOTS_APP_DESC_ARG_SIZE "Array size"

void sort_seq (int);
void sort_par (int);
void sort_init (int);
int sort_verify(int);

#define BOTS_APP_INIT sort_init(bots_arg_size)

#define KERNEL_INIT scramble_array(bots_arg_size)
#define KERNEL_CALL sort_par(bots_arg_size)
#define KERNEL_CHECK sort_verify(bots_arg_size)

#define KERNEL_SEQ_INIT scramble_array(bots_arg_size)
#define KERNEL_SEQ_CALL sort_seq(bots_arg_size)
#define KERNEL_SEQ_CHECK sort_verify(bots_arg_size)

