//  $Id: bmp_map.hxx,v 1.3 2002/08/23 15:49:48 torangan Exp $
//
//  Pingus - A free Lemmings clone
//  Copyright (C) 1999 Ingo Ruhnke <grumbel@gmx.de>
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

#ifndef HEADER_PINGUS_BMP_MAP_HXX
#define HEADER_PINGUS_BMP_MAP_HXX

#include <ClanLib/Display/Display/surface.h>

#include "pingu_map.hxx"

class ColMap;
class ResDescriptor;

///
class PinguBmpMap : public PinguMap 
{
private:
  ///
  CL_Surface surface;
  ///
  ColMap*     colmap;
public:
  ///
  PinguBmpMap();
  ///
  PinguBmpMap(ResDescriptor fg);
  ///
  virtual ~PinguBmpMap();

  ///
  void draw_offset(int x, int y, float s=1.0);
  ///
  int  get_width(void);
  ///
  int  get_height(void);
  ///
  ColMap* get_colmap(void);
  ///
  CL_Surface get_surface(void);
  
private:
  PinguBmpMap (const PinguBmpMap&);
  PinguBmpMap operator= (const PinguBmpMap&); 
};

#endif

/* EOF */

