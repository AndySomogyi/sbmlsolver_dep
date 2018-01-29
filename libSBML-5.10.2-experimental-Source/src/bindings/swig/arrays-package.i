/**
 * Filename    : arrays.i
 * Description : arrays swig file for bindings.
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation; either version 2.1 of the License, or
 * any later version.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY, WITHOUT EVEN THE IMPLIED WARRANTY OF
 * MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.  The software and
 * documentation provided hereunder is on an as is" basis, and the European
 * Media Laboratories gGmbH have no obligations to provide maintenance,
 * support, updates, enhancements or modifications.  In no event shall the
 * European Media Laboratory gGmbH be liable to any party for direct,
 * indirect, special, incidental or consequential damages, including lost
 * profits, arising out of the use of this software and its documentation,
 * even if the European Media Laboratories gGmbH have been advised of the
 * possibility of such damage.  See the GNU Lesser General Public License
 * for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.
 *
 */

#ifdef USE_ARRAYS

%newobject removeDimension;
%newobject removeIndex;

%template(ArraysPkgNamespaces) SBMLExtensionNamespaces<ArraysExtension>;

%include <sbml/packages/arrays/extension/ArraysExtension.h>
%include <sbml/packages/arrays/extension/ArraysSBasePlugin.h>
%include <sbml/packages/arrays/extension/ArraysASTPlugin.h>

%include <sbml/packages/arrays/common/ArraysExtensionTypes.h>

%include <sbml/packages/arrays/sbml/Dimension.h>
%include <sbml/packages/arrays/sbml/Index.h>

#endif /* USE_ARRAYS */
