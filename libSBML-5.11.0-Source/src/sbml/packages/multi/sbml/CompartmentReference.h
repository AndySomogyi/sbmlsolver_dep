/**
 * @file:   CompartmentReference.h
 * @brief:  Implementation of the CompartmentReference class
 * @author: SBMLTeam
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML.  Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2009-2013 jointly by the following organizations:
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK
 *
 * Copyright (C) 2006-2008 by the California Institute of Technology,
 *     Pasadena, CA, USA 
 *
 * Copyright (C) 2002-2005 jointly by the following organizations:
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. Japan Science and Technology Agency, Japan
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation.  A copy of the license agreement is provided
 * in the file named "LICENSE.txt" included with this software distribution
 * and also available online as http://sbml.org/software/libsbml/license.html
 * ------------------------------------------------------------------------ -->
 */


#ifndef CompartmentReference_H__
#define CompartmentReference_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/multi/common/multifwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/SBase.h>
#include <sbml/ListOf.h>
#include <sbml/packages/multi/extension/MultiExtension.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN CompartmentReference : public SBase
{

protected:

  std::string   mId;
  std::string   mName;
  std::string   mCompartment;


public:

  /**
   * Creates a new CompartmentReference with the given level, version, and package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this CompartmentReference
   *
   * @param version an unsigned int, the SBML Version to assign to this CompartmentReference
   *
   * @param pkgVersion an unsigned int, the SBML Multi Version to assign to this CompartmentReference
   */
  CompartmentReference(unsigned int level      = MultiExtension::getDefaultLevel(),
                       unsigned int version    = MultiExtension::getDefaultVersion(),
                       unsigned int pkgVersion = MultiExtension::getDefaultPackageVersion());


  /**
   * Creates a new CompartmentReference with the given MultiPkgNamespaces object.
   *
   * @param multins the MultiPkgNamespaces object
   */
  CompartmentReference(MultiPkgNamespaces* multins);


   /**
   * Copy constructor for CompartmentReference.
   *
   * @param orig; the CompartmentReference instance to copy.
   */
  CompartmentReference(const CompartmentReference& orig);


   /**
   * Assignment operator for CompartmentReference.
   *
   * @param rhs; the object whose values are used as the basis
   * of the assignment
   */
  CompartmentReference& operator=(const CompartmentReference& rhs);


   /**
   * Creates and returns a deep copy of this CompartmentReference object.
   *
   * @return a (deep) copy of this CompartmentReference object.
   */
  virtual CompartmentReference* clone () const;


   /**
   * Destructor for CompartmentReference.
   */
  virtual ~CompartmentReference();


   /**
   * Returns the value of the "id" attribute of this CompartmentReference.
   *
   * @return the value of the "id" attribute of this CompartmentReference as a string.
   */
  virtual const std::string& getId() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * CompartmentReference's "id" attribute has been set.
   *
   * @return @c true if this CompartmentReference's "id" attribute has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetId() const;


  /**
   * Sets the value of the "id" attribute of this CompartmentReference.
   *
   * @param id; const std::string& value of the "id" attribute to be set
   *
   * @return integer value indicating success/failure of the
   * function.  @if clike The value is drawn from the
   * enumeration #OperationReturnValues_t. @endif The possible values
   * returned by this function are:
   * @li LIBSBML_OPERATION_SUCCESS
   * @li LIBSBML_INVALID_ATTRIBUTE_VALUE
   */
  virtual int setId(const std::string& id);


  /**
   * Unsets the value of the "id" attribute of this CompartmentReference.
   *
   * @return integer value indicating success/failure of the
   * function.  @if clike The value is drawn from the
   * enumeration #OperationReturnValues_t. @endif The possible values
   * returned by this function are:
   * @li LIBSBML_OPERATION_SUCCESS
   * @li LIBSBML_OPERATION_FAILED
   */
  virtual int unsetId();


  /**
   * Returns the value of the "name" attribute of this CompartmentReference.
   *
   * @return the value of the "name" attribute of this CompartmentReference as a string.
   */
  virtual const std::string& getName() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * CompartmentReference's "name" attribute has been set.
   *
   * @return @c true if this CompartmentReference's "name" attribute has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetName() const;


  /**
   * Sets the value of the "name" attribute of this CompartmentReference.
   *
   * @param name; const std::string& value of the "name" attribute to be set
   *
   * @return integer value indicating success/failure of the
   * function.  @if clike The value is drawn from the
   * enumeration #OperationReturnValues_t. @endif The possible values
   * returned by this function are:
   * @li LIBSBML_OPERATION_SUCCESS
   * @li LIBSBML_INVALID_ATTRIBUTE_VALUE
   */
  virtual int setName(const std::string& name);


  /**
   * Unsets the value of the "name" attribute of this CompartmentReference.
   *
   * @return integer value indicating success/failure of the
   * function.  @if clike The value is drawn from the
   * enumeration #OperationReturnValues_t. @endif The possible values
   * returned by this function are:
   * @li LIBSBML_OPERATION_SUCCESS
   * @li LIBSBML_OPERATION_FAILED
   */
  virtual int unsetName();


  /**
   * Returns the value of the "compartment" attribute of this CompartmentReference.
   *
   * @return the value of the "compartment" attribute of this CompartmentReference as a string.
   */
  virtual const std::string& getCompartment() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * CompartmentReference's "compartment" attribute has been set.
   *
   * @return @c true if this CompartmentReference's "compartment" attribute has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetCompartment() const;


  /**
   * Sets the value of the "compartment" attribute of this CompartmentReference.
   *
   * @param compartment; const std::string& value of the "compartment" attribute to be set
   *
   * @return integer value indicating success/failure of the
   * function.  @if clike The value is drawn from the
   * enumeration #OperationReturnValues_t. @endif The possible values
   * returned by this function are:
   * @li LIBSBML_OPERATION_SUCCESS
   * @li LIBSBML_INVALID_ATTRIBUTE_VALUE
   */
  virtual int setCompartment(const std::string& compartment);


  /**
   * Unsets the value of the "compartment" attribute of this CompartmentReference.
   *
   * @return integer value indicating success/failure of the
   * function.  @if clike The value is drawn from the
   * enumeration #OperationReturnValues_t. @endif The possible values
   * returned by this function are:
   * @li LIBSBML_OPERATION_SUCCESS
   * @li LIBSBML_OPERATION_FAILED
   */
  virtual int unsetCompartment();


  /**
   * Renames all the @c SIdRef attributes on this element, including any
   * found in MathML content (if such exists).
   *
   * This method works by looking at all attributes and (if appropriate)
   * mathematical formulas, comparing the identifiers to the value of @p
   * oldid.  If any matches are found, the matching identifiers are replaced
   * with @p newid.  The method does @em not descend into child elements.
   *
   * @param oldid the old identifier
   * @param newid the new identifier
   */
   virtual void renameSIdRefs(const std::string& oldid, const std::string& newid);


  /**
   * Returns the XML element name of this object, which for CompartmentReference, is
   * always @c "compartmentReference".
   *
   * @return the name of this element, i.e. @c "compartmentReference".
   */
  virtual const std::string& getElementName () const;


  /**
   * Returns the libSBML type code for this SBML object.
   * 
   * @if clike LibSBML attaches an identifying code to every kind of SBML
   * object.  These are known as <em>SBML type codes</em>.  The set of
   * possible type codes is defined in the enumeration #SBMLTypeCode_t.
   * The names of the type codes all begin with the characters @c
   * SBML_. @endif@if java LibSBML attaches an identifying code to every
   * kind of SBML object.  These are known as <em>SBML type codes</em>.  In
   * other languages, the set of type codes is stored in an enumeration; in
   * the Java language interface for libSBML, the type codes are defined as
   * static integer constants in the interface class {@link
   * libsbmlConstants}.  The names of the type codes all begin with the
   * characters @c SBML_. @endif@if python LibSBML attaches an identifying
   * code to every kind of SBML object.  These are known as <em>SBML type
   * codes</em>.  In the Python language interface for libSBML, the type
   * codes are defined as static integer constants in the interface class
   * @link libsbml@endlink.  The names of the type codes all begin with the
   * characters @c SBML_. @endif@if csharp LibSBML attaches an identifying
   * code to every kind of SBML object.  These are known as <em>SBML type
   * codes</em>.  In the C# language interface for libSBML, the type codes
   * are defined as static integer constants in the interface class @link
   * libsbmlcs.libsbml@endlink.  The names of the type codes all begin with
   * the characters @c SBML_. @endif
   *
   * @return the SBML type code for this object, or
   * @link SBMLTypeCode_t#SBML_UNKNOWN SBML_UNKNOWN@endlink (default).
   *
   * @see getElementName()
   */
  virtual int getTypeCode () const;


  /**
   * Predicate returning @c true if all the required attributes
   * for this CompartmentReference object have been set.
   *
   * @note The required attributes for a CompartmentReference object are:
   * @li "compartment"
   *
   * @return a boolean value indicating whether all the required
   * attributes for this object have been defined.
   */
  virtual bool hasRequiredAttributes() const;


  /** @cond doxygenLibsbmlInternal */

  /**
   * Subclasses should override this method to write out their contained
   * SBML objects as XML elements.  Be sure to call your parents
   * implementation of this method as well.
   */
  virtual void writeElements (XMLOutputStream& stream) const;


  /** @endcond doxygenLibsbmlInternal */


  /** @cond doxygenLibsbmlInternal */

  /**
   * Accepts the given SBMLVisitor.
   */
  virtual bool accept (SBMLVisitor& v) const;


  /** @endcond doxygenLibsbmlInternal */


  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the parent SBMLDocument.
   */
  virtual void setSBMLDocument (SBMLDocument* d);


  /** @endcond doxygenLibsbmlInternal */


  /** @cond doxygenLibsbmlInternal */

  /**
   * Enables/Disables the given package with this element.
   */
  virtual void enablePackageInternal(const std::string& pkgURI,
               const std::string& pkgPrefix, bool flag);


  /** @endcond doxygenLibsbmlInternal */


protected:

  /** @cond doxygenLibsbmlInternal */

  /**
   * Get the list of expected attributes for this element.
   */
  virtual void addExpectedAttributes(ExpectedAttributes& attributes);


  /** @endcond doxygenLibsbmlInternal */


  /** @cond doxygenLibsbmlInternal */

  /**
   * Read values from the given XMLAttributes set into their specific fields.
   */
  virtual void readAttributes (const XMLAttributes& attributes,
                               const ExpectedAttributes& expectedAttributes);


  /** @endcond doxygenLibsbmlInternal */


  /** @cond doxygenLibsbmlInternal */

  /**
   * Write values of XMLAttributes to the output stream.
   */
  virtual void writeAttributes (XMLOutputStream& stream) const;


  /** @endcond doxygenLibsbmlInternal */



};

class LIBSBML_EXTERN ListOfCompartmentReferences : public ListOf
{

public:

  /**
   * Creates a new ListOfCompartmentReferences with the given level, version, and package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this ListOfCompartmentReferences
   *
   * @param version an unsigned int, the SBML Version to assign to this ListOfCompartmentReferences
   *
   * @param pkgVersion an unsigned int, the SBML Multi Version to assign to this ListOfCompartmentReferences
   */
  ListOfCompartmentReferences(unsigned int level      = MultiExtension::getDefaultLevel(),
                              unsigned int version    = MultiExtension::getDefaultVersion(),
                              unsigned int pkgVersion = MultiExtension::getDefaultPackageVersion());


  /**
   * Creates a new ListOfCompartmentReferences with the given MultiPkgNamespaces object.
   *
   * @param multins the MultiPkgNamespaces object
   */
  ListOfCompartmentReferences(MultiPkgNamespaces* multins);


   /**
   * Creates and returns a deep copy of this ListOfCompartmentReferences object.
   *
   * @return a (deep) copy of this ListOfCompartmentReferences object.
   */
  virtual ListOfCompartmentReferences* clone () const;


   /**
   * Get a CompartmentReference from the ListOfCompartmentReferences.
   *
   * @param n the index number of the CompartmentReference to get.
   *
   * @return the nth CompartmentReference in this ListOfCompartmentReferences.
   *
   * @see size()
   */
  virtual CompartmentReference* get(unsigned int n);


  /**
   * Get a CompartmentReference from the ListOfCompartmentReferences.
   *
   * @param n the index number of the CompartmentReference to get.
   *
   * @return the nth CompartmentReference in this ListOfCompartmentReferences.
   *
   * @see size()
   */
  virtual const CompartmentReference* get(unsigned int n) const;


  /**
   * Get a CompartmentReference from the ListOfCompartmentReferences
   * based on its identifier.
   *
   * @param sid a string representing the identifier
   * of the CompartmentReference to get.
   *
   * @return CompartmentReference in this ListOfCompartmentReferences
   * with the given id or NULL if no such
   * CompartmentReference exists.
   *
   * @see get(unsigned int n)   *
   * @see size()
   */
  virtual CompartmentReference* get(const std::string& sid);


  /**
   * Get a CompartmentReference from the ListOfCompartmentReferences
   * based on its identifier.
   *
   * @param sid a string representing the identifier
   * of the CompartmentReference to get.
   *
   * @return CompartmentReference in this ListOfCompartmentReferences
   * with the given id or NULL if no such
   * CompartmentReference exists.
   *
   * @see get(unsigned int n)   *
   * @see size()
   */
  virtual const CompartmentReference* get(const std::string& sid) const;


  /**
   * Removes the nth CompartmentReference from this ListOfCompartmentReferences
   * and returns a pointer to it.
   *
   * The caller owns the returned item and is responsible for deleting it.
   *
   * @param n the index of the CompartmentReference to remove.
   *
   * @see size()
   */
  virtual CompartmentReference* remove(unsigned int n);


  /**
   * Removes the CompartmentReference from this ListOfCompartmentReferences with the given identifier
   * and returns a pointer to it.
   *
   * The caller owns the returned item and is responsible for deleting it.
   * If none of the items in this list have the identifier @p sid, then
   * @c NULL is returned.
   *
   * @param sid the identifier of the CompartmentReference to remove.
   *
   * @return the CompartmentReference removed. As mentioned above, the caller owns the
   * returned item.
   */
  virtual CompartmentReference* remove(const std::string& sid);


  /**
   * Returns the XML element name of this object, which for ListOfCompartmentReferences, is
   * always @c "listOfCompartmentReferences".
   *
   * @return the name of this element, i.e. @c "listOfCompartmentReferences".
   */
  virtual const std::string& getElementName () const;


  /**
   * Returns the libSBML type code for this SBML object.
   * 
   * @if clike LibSBML attaches an identifying code to every kind of SBML
   * object.  These are known as <em>SBML type codes</em>.  The set of
   * possible type codes is defined in the enumeration #SBMLTypeCode_t.
   * The names of the type codes all begin with the characters @c
   * SBML_. @endif@if java LibSBML attaches an identifying code to every
   * kind of SBML object.  These are known as <em>SBML type codes</em>.  In
   * other languages, the set of type codes is stored in an enumeration; in
   * the Java language interface for libSBML, the type codes are defined as
   * static integer constants in the interface class {@link
   * libsbmlConstants}.  The names of the type codes all begin with the
   * characters @c SBML_. @endif@if python LibSBML attaches an identifying
   * code to every kind of SBML object.  These are known as <em>SBML type
   * codes</em>.  In the Python language interface for libSBML, the type
   * codes are defined as static integer constants in the interface class
   * @link libsbml@endlink.  The names of the type codes all begin with the
   * characters @c SBML_. @endif@if csharp LibSBML attaches an identifying
   * code to every kind of SBML object.  These are known as <em>SBML type
   * codes</em>.  In the C# language interface for libSBML, the type codes
   * are defined as static integer constants in the interface class @link
   * libsbmlcs.libsbml@endlink.  The names of the type codes all begin with
   * the characters @c SBML_. @endif
   *
   * @return the SBML type code for this object, or
   * @link SBMLTypeCode_t#SBML_UNKNOWN SBML_UNKNOWN@endlink (default).
   *
   * @see getElementName()
   */
  virtual int getTypeCode () const;


  /**
   * Returns the libSBML type code for the SBML objects
   * contained in this ListOf object
   * 
   * @if clike LibSBML attaches an identifying code to every kind of SBML
   * object.  These are known as <em>SBML type codes</em>.  The set of
   * possible type codes is defined in the enumeration #SBMLTypeCode_t.
   * The names of the type codes all begin with the characters @c
   * SBML_. @endif@if java LibSBML attaches an identifying code to every
   * kind of SBML object.  These are known as <em>SBML type codes</em>.  In
   * other languages, the set of type codes is stored in an enumeration; in
   * the Java language interface for libSBML, the type codes are defined as
   * static integer constants in the interface class {@link
   * libsbmlConstants}.  The names of the type codes all begin with the
   * characters @c SBML_. @endif@if python LibSBML attaches an identifying
   * code to every kind of SBML object.  These are known as <em>SBML type
   * codes</em>.  In the Python language interface for libSBML, the type
   * codes are defined as static integer constants in the interface class
   * @link libsbml@endlink.  The names of the type codes all begin with the
   * characters @c SBML_. @endif@if csharp LibSBML attaches an identifying
   * code to every kind of SBML object.  These are known as <em>SBML type
   * codes</em>.  In the C# language interface for libSBML, the type codes
   * are defined as static integer constants in the interface class @link
   * libsbmlcs.libsbml@endlink.  The names of the type codes all begin with
   * the characters @c SBML_. @endif
   *
   * @return the SBML type code for the objects in this ListOf instance, or
   * @link SBMLTypeCode_t#SBML_UNKNOWN SBML_UNKNOWN@endlink (default).
   *
   * @see getElementName()
   */
  virtual int getItemTypeCode () const;


protected:

  /** @cond doxygenLibsbmlInternal */

  /**
   * Creates a new CompartmentReference in this ListOfCompartmentReferences
   */
  virtual SBase* createObject(XMLInputStream& stream);


  /** @endcond doxygenLibsbmlInternal */


  /** @cond doxygenLibsbmlInternal */

  /**
   * Write the namespace for the Multi package.
   */
  virtual void writeXMLNS(XMLOutputStream& stream) const;


  /** @endcond doxygenLibsbmlInternal */



};



LIBSBML_CPP_NAMESPACE_END

#endif  /*  __cplusplus  */

#ifndef SWIG

LIBSBML_CPP_NAMESPACE_BEGIN
BEGIN_C_DECLS

LIBSBML_EXTERN
CompartmentReference_t *
CompartmentReference_create(unsigned int level, unsigned int version,
                            unsigned int pkgVersion);


LIBSBML_EXTERN
void
CompartmentReference_free(CompartmentReference_t * cr);


LIBSBML_EXTERN
CompartmentReference_t *
CompartmentReference_clone(CompartmentReference_t * cr);


LIBSBML_EXTERN
char *
CompartmentReference_getId(CompartmentReference_t * cr);


LIBSBML_EXTERN
char *
CompartmentReference_getName(CompartmentReference_t * cr);


LIBSBML_EXTERN
char *
CompartmentReference_getCompartment(CompartmentReference_t * cr);


LIBSBML_EXTERN
int
CompartmentReference_isSetId(CompartmentReference_t * cr);


LIBSBML_EXTERN
int
CompartmentReference_isSetName(CompartmentReference_t * cr);


LIBSBML_EXTERN
int
CompartmentReference_isSetCompartment(CompartmentReference_t * cr);


LIBSBML_EXTERN
int
CompartmentReference_setId(CompartmentReference_t * cr, const char * id);


LIBSBML_EXTERN
int
CompartmentReference_setName(CompartmentReference_t * cr, const char * name);


LIBSBML_EXTERN
int
CompartmentReference_setCompartment(CompartmentReference_t * cr, const char * compartment);


LIBSBML_EXTERN
int
CompartmentReference_unsetId(CompartmentReference_t * cr);


LIBSBML_EXTERN
int
CompartmentReference_unsetName(CompartmentReference_t * cr);


LIBSBML_EXTERN
int
CompartmentReference_unsetCompartment(CompartmentReference_t * cr);


LIBSBML_EXTERN
int
CompartmentReference_hasRequiredAttributes(CompartmentReference_t * cr);


LIBSBML_EXTERN
CompartmentReference_t *
ListOfCompartmentReferences_getById(ListOf_t * lo, const char * sid);


LIBSBML_EXTERN
CompartmentReference_t *
ListOfCompartmentReferences_removeById(ListOf_t * lo, const char * sid);




END_C_DECLS
LIBSBML_CPP_NAMESPACE_END

#endif  /*  !SWIG  */

#endif /*  CompartmentReference_H__  */

