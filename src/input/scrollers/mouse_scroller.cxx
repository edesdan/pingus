//  $Id: mouse_scroller.cxx,v 1.3 2003/10/20 13:33:44 grumbel Exp $
//
//  Pingus - A free Lemmings clone
//  Copyright (C) 2000 Ingo Ruhnke <grumbel@gmx.de>
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 2
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

#include <ClanLib/Display/mouse.h>
#include "mouse_scroller.hxx"

namespace Input {
namespace Scrollers {

MouseScroller::MouseScroller () : old_x(0), old_y(0), x_delta(0), y_delta(0)
{
}

const float&
MouseScroller::get_x_delta () const
{
  return x_delta;
}

const float&
MouseScroller::get_y_delta () const
{
  return y_delta;
}

void
MouseScroller::get_delta (float& x, float& y) const
{
  x = x_delta;
  y = y_delta;
}

void
MouseScroller::update (float)
{
  x_delta = CL_Mouse::get_x() - old_x;
  y_delta = CL_Mouse::get_y() - old_y;

  old_x = CL_Mouse::get_x();
  old_y = CL_Mouse::get_y();
}

}
}

/* EOF */

