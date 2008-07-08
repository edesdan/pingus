//  Pingus - A free Lemmings clone
//  Copyright (C) 1999 Ingo Ruhnke <grumbel@gmx.de>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//  
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//  
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef HEADER_PINGUS_PINGUS_MENU_HPP
#define HEADER_PINGUS_PINGUS_MENU_HPP

#include <vector>
#include "fonts.hpp"
#include "pingus_sub_menu.hpp"
#include "layer_manager.hpp"
#include "screen/gui_screen.hpp"

class SurfaceButton;
class GameDelta;

namespace GUI {
class GUIManager;
} // namespace GUI

class MenuButton;

class PingusMenu : public GUIScreen
{
public:
  bool is_init;
  std::string hint;
  std::string help;
  float text_scroll_offset;

private:
  LayerManager background;
  Sprite logo;

  MenuButton* start_button;
  MenuButton* quit_button;
  MenuButton* editor_button;
  MenuButton* contrib_button;
  
  void on_resize (int w, int h);

  void show_credits();

  void do_quit();
  void do_start(const std::string &filename);
  void do_edit();

public:
  PingusMenu();
  ~PingusMenu();

  void on_click(MenuButton* button);
  void set_hint(const std::string& str);

  /// Load all images and other stuff for the menu
  void do_contrib(const std::string&);

  void on_escape_press ();
  void draw_background(DrawingContext& gc);

  void update(float delta);
private:
  PingusMenu (const PingusMenu&);
  PingusMenu& operator= (const PingusMenu&);
};

#endif

/* EOF */
