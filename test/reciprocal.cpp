/*
 * =====================================================================================
 *
 *       Filename:  reciprocal.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/07/2014 02:18:52 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cassert>
#include "reciprocal.hpp"

double reciprocal (int i)
{
	assert(i != 0);
	return 1.0/i;
}
