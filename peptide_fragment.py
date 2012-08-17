####
#Copyright 2011 Gene Selkov, Samuel Volchenboum
#
#This file is part of Fragment-Singleton.
#
#Fragment-Singleton is free software: you can redistribute it and/or modify
#it under the terms of the GNU General Public License as published by
#the Free Software Foundation, either version 3 of the License, or
#(at your option) any later version.
#
#Fragment-Singleton is distributed in the hope that it will be useful,
#but WITHOUT ANY WARRANTY; without even the implied warranty of
#MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#GNU General Public License for more details.
#
#You should have received a copy of the GNU General Public License
#along with Fragment-Singleton.  If not, see <http://www.gnu.org/licenses/>.
#####

import sys, pybindgen
from pybindgen import *

mod = Module('PeptideFragmentSingleton')
mod.add_include('"peptide_fragment.hpp"')
mod.add_container('ListD', ReturnValue.new('double'), 'list')
c = mod.add_class('PeptideFragment')
c.add_constructor([
        param('int',    'massType', default_value="1"),
        ])
c.add_instance_attribute('a', 'ListD')
c.add_instance_attribute('b', 'ListD')
c.add_instance_attribute('c', 'ListD')
c.add_instance_attribute('x', 'ListD')
c.add_instance_attribute('y', 'ListD')
c.add_instance_attribute('z', 'ListD')
c.add_instance_attribute('zdot', 'ListD')
c.add_instance_attribute('mass', 'ListD')
c.add_method('composition',  retval('std::string'),  [])
c.add_method('sequence',     retval('std::string'),  [], is_const=True)
c.add_method('a_ions',       ReturnValue.new('ListD'),  [], is_virtual=True)
c.add_method('b_ions',       ReturnValue.new('ListD'),  [], is_virtual=True)
c.add_method('c_ions',       ReturnValue.new('ListD'),  [], is_virtual=True)
c.add_method('x_ions',       ReturnValue.new('ListD'),  [], is_virtual=True)
c.add_method('y_ions',       ReturnValue.new('ListD'),  [], is_virtual=True)
c.add_method('z_ions',       ReturnValue.new('ListD'),  [], is_virtual=True)
c.add_method('zdot_ions',       ReturnValue.new('ListD'),  [], is_virtual=True)
c.add_method('peptide_mass', ReturnValue.new('ListD'),  [], is_virtual=True)
c.add_method('analyze', None, [
        param('char *', 'peptide'),
        param('int',    'charge',   default_value="1"),
        param('char *', 'modification',   default_value='(char *)""')
        ])
mod.generate(sys.stdout)
