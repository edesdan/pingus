//  $Id: joystick_button.cxx,v 1.5 2003/10/20 13:33:44 grumbel Exp $
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

//#include <ClanLib/Display/input.h>
#include <ClanLib/Display/input_device.h>
//#include <ClanLib/Display/input_button.h>
#include "joystick_button.hxx"
#include "../../string_converter.hxx"
#include "../../pingus_error.hxx"

namespace Pingus {
namespace Input {
namespace Buttons {

JoystickButton::JoystickButton(int id_, int button_) : id(id_), button(button_)
{
#ifdef CLANLIB_0_6
  if (static_cast<unsigned int>(id) >= CL_Input::joysticks.size())
    PingusError::raise("JoystickButton: Invalid joystick id: " + to_string(id));

  if (button > CL_Input::joysticks[id]->get_num_buttons())
    PingusError::raise("JoystickButton: Invalid joystick button id: " + to_string(button));
#endif
}

void
JoystickButton::update(float)
{
}

bool
JoystickButton::is_pressed() const
{
#ifdef CLANLIB_0_6
  return CL_Input::joysticks[id]->get_button(button)->is_pressed();
#else
  return false;
#endif
}

} // namespace Buttons
} // namespace Input
} // namespace Pingus

/* EOF */
