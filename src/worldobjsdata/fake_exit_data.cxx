//  $Id: fake_exit_data.cxx,v 1.9 2003/02/26 17:08:29 grumbel Exp $
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

#include <iostream>
#include "fake_exit_data.hxx"
#include "../world.hxx"
#include "../xml_helper.hxx"
#include "../xml_file_reader.hxx"
#include "../editorobjs/fake_exit_obj.hxx"
#include "../worldobjs/fake_exit.hxx"
#include "../pingus_resource.hxx"

namespace WorldObjsData {

FakeExitData::FakeExitData ()
{
}

FakeExitData::FakeExitData (xmlDocPtr doc, xmlNodePtr cur) : surface(PingusResource::load_surface("Traps/fake_exit", "traps"))
{
  XMLFileReader reader(doc, cur);
  reader.read_vector("position", pos);
}

FakeExitData::FakeExitData (const FakeExitData& old) : WorldObjData(old),
						       surface(old.surface),
						       pos(old.pos)
{
}

void
FakeExitData::write_xml (std::ostream& xml)
{
  xml << "<worldobj type=\"fake_exit\">\n\t";
  XMLhelper::write_vector_xml(xml, pos);
  xml << "</worldobj>\n\n";
}

void
FakeExitData::insert_WorldObjs (World* world)
{
  world->add_object(new WorldObjs::FakeExit(*this));
}

EditorObjLst
FakeExitData::create_EditorObj ()
{
  return EditorObjLst(1, new EditorObjs::FakeExitObj(*this));
}

} // namespace WorldObjsData

/* EOF */
