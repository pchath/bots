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

#include "serial-app.h"

#define BOTS_APP_NAME "SparseLU"
#define BOTS_APP_PARAMETERS_DESC "S1=%dx%d, S2=%dx%d"
#define BOTS_APP_PARAMETERS_LIST ,bots_arg_size,bots_arg_size,bots_arg_size_1,bots_arg_size_1

#define BOTS_APP_SELF_TIMING

#define BOTS_APP_USES_ARG_SIZE
#define BOTS_APP_DEF_ARG_SIZE 50
#define BOTS_APP_DESC_ARG_SIZE "Matrix Size"

#define BOTS_APP_USES_ARG_SIZE_1
#define BOTS_APP_DEF_ARG_SIZE_1 100
#define BOTS_APP_DESC_ARG_SIZE_1 "Submatrix Size"

#define BOTS_APP_INIT float **SEQ;

int checkmat (float *M, float *N);
void genmat (float *M[]);
void print_structure(char *name, float *M[]);
float * allocate_clean_block();
void lu0(float *diag);
void bdiv(float *diag, float *row);
void bmod(float *row, float *col, float *inner);
void fwd(float *diag, float *col);
double sparselu(float ***SEQ);

#define KERNEL_INIT
#define KERNEL_CALL sparselu(&SEQ);
#define KERNEL_FINI

#define KERNEL_SEQ_INIT
#define KERNEL_SEQ_CALL 0
#define KERNEL_SEQ_FINI

#define KERNEL_CHECK BOTS_RESULT_NA;

