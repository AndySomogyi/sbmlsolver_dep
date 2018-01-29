/**
 * @file:   SpeciesFeature.h
 * @brief:  Implementation of the SpeciesFeature class
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


#ifndef SpeciesFeature_H__
#define SpeciesFeature_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/multi/common/multifwd.h>

typedef enum
{
    MULTI_RELATION_AND
  , MULTI_RELATION_OR
  , MULTI_RELATION_NOT
  , MULTI_RELATION_UNKNOWN
} Relation_t;



#ifdef __cplusplus


#include <string>


#include <sbml/SBase.h>
#include <sbml/ListOf.h>
#include <sbml/packages/multi/extension/MultiExtension.h>

#include <sbml/packages/multi/sbml/SpeciesFeatureValue.h>

LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN SpeciesFeature : public SBase
{

protected:

  std::string   mId;
  std::string   mSpeciesFeatureType;
  unsigned int  mOccur;
  bool          mIsSetOccur;
  std::string   mComponent;
  ListOfSpeciesFeatureValues   mSpeciesFeatureValues;


public:

  /**
   * Creates a new SpeciesFeature with the given level, version, and package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this SpeciesFeature
   *
   * @param version an unsigned int, the SBML Version to assign to this SpeciesFeature
   *
   * @param pkgVersion an unsigned int, the SBML Multi Version to assign to this SpeciesFeature
   */
  SpeciesFeature(unsigned int level      = MultiExtension::getDefaultLevel(),
                 unsigned int version    = MultiExtension::getDefaultVersion(),
                 unsigned int pkgVersion = MultiExtension::getDefaultPackageVersion());


  /**
   * Creates a new SpeciesFeature with the given MultiPkgNamespaces object.
   *
   * @param multins the MultiPkgNamespaces object
   */
  SpeciesFeature(MultiPkgNamespaces* multins);


   /**
   * Copy constructor for SpeciesFeature.
   *
   * @param orig; the SpeciesFeature instance to copy.
   */
  SpeciesFeature(const SpeciesFeature& orig);


   /**
   * Assignment operator for SpeciesFeature.
   *
   * @param rhs; the object whose values are used as the basis
   * of the assignment
   */
  SpeciesFeature& operator=(const SpeciesFeature& rhs);


   /**
   * Creates and returns a deep copy of this SpeciesFeature object.
   *
   * @return a (deep) copy of this SpeciesFeature object.
   */
  virtual SpeciesFeature* clone () const;


   /**
   * Destructor for SpeciesFeature.
   */
  virtual ~SpeciesFeature();


   /**
   * Returns the value of the "id" attribute of this SpeciesFeature.
   *
   * @return the value of the "id" attribute of this SpeciesFeature as a string.
   */
  virtual const std::string& getId() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * SpeciesFeature's "id" attribute has been set.
   *
   * @return @c true if this SpeciesFeature's "id" attribute has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetId() const;


  /**
   * Sets the value of the "id" attribute of this SpeciesFeature.
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
   * Unsets the value of the "id" attribute of this SpeciesFeature.
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
   * Returns the value of the "speciesFeatureType" attribute of this SpeciesFeature.
   *
   * @return the value of the "speciesFeatureType" attribute of this SpeciesFeature as a string.
   */
  virtual const std::string& getSpeciesFeatureType() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * SpeciesFeature's "speciesFeatureType" attribute has been set.
   *
   * @return @c true if this SpeciesFeature's "speciesFeatureType" attribute has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetSpeciesFeatureType() const;


  /**
   * Sets the value of the "speciesFeatureType" attribute of this SpeciesFeature.
   *
   * @param speciesFeatureType; const std::string& value of the "speciesFeatureType" attribute to be set
   *
   * @return integer value indicating success/failure of the
   * function.  @if clike The value is drawn from the
   * enumeration #OperationReturnValues_t. @endif The possible values
   * returned by this function are:
   * @li LIBSBML_OPERATION_SUCCESS
   * @li LIBSBML_INVALID_ATTRIBUTE_VALUE
   */
  virtual int setSpeciesFeatureType(const std::string& speciesFeatureType);


  /**
   * Unsets the value of the "speciesFeatureType" attribute of this SpeciesFeature.
   *
   * @return integer value indicating success/failure of the
   * function.  @if clike The value is drawn from the
   * enumeration #OperationReturnValues_t. @endif The possible values
   * returned by this function are:
   * @li LIBSBML_OPERATION_SUCCESS
   * @li LIBSBML_OPERATION_FAILED
   */
  virtual int unsetSpeciesFeatureType();


  /**
   * Returns the value of the "occur" attribute of this SpeciesFeature.
   *
   * @return the value of the "occur" attribute of this SpeciesFeature as a unsigned integer.
   */
  virtual unsigned int getOccur() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * SpeciesFeature's "occur" attribute has been set.
   *
   * @return @c true if this SpeciesFeature's "occur" attribute has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetOccur() const;


  /**
   * Sets the value of the "occur" attribute of this SpeciesFeature.
   *
   * @param occur; unsigned int value of the "occur" attribute to be set
   *
   * @return integer value indicating success/failure of the
   * function.  @if clike The value is drawn from the
   * enumeration #OperationReturnValues_t. @endif The possible values
   * returned by this function are:
   * @li LIBSBML_OPERATION_SUCCESS
   * @li LIBSBML_INVALID_ATTRIBUTE_VALUE
   */
  virtual int setOccur(unsigned int occur);


  /**
   * Unsets the value of the "occur" attribute of this SpeciesFeature.
   *
   * @return integer value indicating success/failure of the
   * function.  @if clike The value is drawn from the
   * enumeration #OperationReturnValues_t. @endif The possible values
   * returned by this function are:
   * @li LIBSBML_OPERATION_SUCCESS
   * @li LIBSBML_OPERATION_FAILED
   */
  virtual int unsetOccur();


  /**
   * Returns the value of the "component" attribute of this SpeciesFeature.
   *
   * @return the value of the "component" attribute of this SpeciesFeature as a string.
   */
  virtual const std::string& getComponent() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * SpeciesFeature's "component" attribute has been set.
   *
   * @return @c true if this SpeciesFeature's "component" attribute has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetComponent() const;


  /**
   * Sets the value of the "component" attribute of this SpeciesFeature.
   *
   * @param component; const std::string& value of the "component" attribute to be set
   *
   * @return integer value indicating success/failure of the
   * function.  @if clike The value is drawn from the
   * enumeration #OperationReturnValues_t. @endif The possible values
   * returned by this function are:
   * @li LIBSBML_OPERATION_SUCCESS
   * @li LIBSBML_INVALID_ATTRIBUTE_VALUE
   */
  virtual int setComponent(const std::string& component);


  /**
   * Unsets the value of the "component" attribute of this SpeciesFeature.
   *
   * @return integer value indicating success/failure of the
   * function.  @if clike The value is drawn from the
   * enumeration #OperationReturnValues_t. @endif The possible values
   * returned by this function are:
   * @li LIBSBML_OPERATION_SUCCESS
   * @li LIBSBML_OPERATION_FAILED
   */
  virtual int unsetComponent();


  /**
   * Returns the  "ListOfSpeciesFeatureValues" in this SpeciesFeature object.
   *
   * @return the "ListOfSpeciesFeatureValues" attribute of this SpeciesFeature.
   */
  const ListOfSpeciesFeatureValues* getListOfSpeciesFeatureValues() const;


  /**
   * Returns the  "ListOfSpeciesFeatureValues" in this SpeciesFeature object.
   *
   * @return the "ListOfSpeciesFeatureValues" attribute of this SpeciesFeature.
   */
  ListOfSpeciesFeatureValues* getListOfSpeciesFeatureValues();


  /**
   * Get a SpeciesFeatureValue from the ListOfSpeciesFeatureValues.
   *
   * @param n the index number of the SpeciesFeatureValue to get.
   *
   * @return the nth SpeciesFeatureValue in the ListOfSpeciesFeatureValues within this SpeciesFeature.
   *
   * @see getNumSpeciesFeatureValues()
   */
  SpeciesFeatureValue* getSpeciesFeatureValue(unsigned int n);


  /**
   * Get a SpeciesFeatureValue from the ListOfSpeciesFeatureValues.
   *
   * @param n the index number of the SpeciesFeatureValue to get.
   *
   * @return the nth SpeciesFeatureValue in the ListOfSpeciesFeatureValues within this SpeciesFeature.
   *
   * @see getNumSpeciesFeatureValues()
   */
  const SpeciesFeatureValue* getSpeciesFeatureValue(unsigned int n) const;


  /**
   * Get a SpeciesFeatureValue from the ListOfSpeciesFeatureValues
   * based on its identifier.
   *
   * @param sid a string representing the identifier
   * of the SpeciesFeatureValue to get.
   *
   * @return the SpeciesFeatureValue in the ListOfSpeciesFeatureValues
   * with the given id or NULL if no such
   * SpeciesFeatureValue exists.
   *
   * @see getSpeciesFeatureValue(unsigned int n)
   *
   * @see getNumSpeciesFeatureValues()
   */
  SpeciesFeatureValue* getSpeciesFeatureValue(const std::string& sid);


  /**
   * Get a SpeciesFeatureValue from the ListOfSpeciesFeatureValues
   * based on its identifier.
   *
   * @param sid a string representing the identifier
   * of the SpeciesFeatureValue to get.
   *
   * @return the SpeciesFeatureValue in the ListOfSpeciesFeatureValues
   * with the given id or NULL if no such
   * SpeciesFeatureValue exists.
   *
   * @see getSpeciesFeatureValue(unsigned int n)
   *
   * @see getNumSpeciesFeatureValues()
   */
  const SpeciesFeatureValue* getSpeciesFeatureValue(const std::string& sid) const;


  /**
   * Adds a copy the given "SpeciesFeatureValue" to this SpeciesFeature.
   *
   * @param sfv; the SpeciesFeatureValue object to add
   *
   * @return integer value indicating success/failure of the
   * function.  @if clike The value is drawn from the
   * enumeration #OperationReturnValues_t. @endif The possible values
   * returned by this function are:
   * @li LIBSBML_OPERATION_SUCCESS
   * @li LIBSBML_INVALID_ATTRIBUTE_VALUE
   */
  int addSpeciesFeatureValue(const SpeciesFeatureValue* sfv);


  /**
   * Get the number of SpeciesFeatureValue objects in this SpeciesFeature.
   *
   * @return the number of SpeciesFeatureValue objects in this SpeciesFeature
   */
  unsigned int getNumSpeciesFeatureValues() const;


  /**
   * Creates a new SpeciesFeatureValue object, adds it to this SpeciesFeatures
   * ListOfSpeciesFeatureValues and returns the SpeciesFeatureValue object created. 
   *
   * @return a new SpeciesFeatureValue object instance
   *
   * @see addSpeciesFeatureValue(const SpeciesFeatureValue* sfv)
   */
  SpeciesFeatureValue* createSpeciesFeatureValue();


  /**
   * Removes the nth SpeciesFeatureValue from the ListOfSpeciesFeatureValues within this SpeciesFeature.
   * and returns a pointer to it.
   *
   * The caller owns the returned item and is responsible for deleting it.
   *
   * @param n the index of the SpeciesFeatureValue to remove.
   *
   * @see getNumSpeciesFeatureValues()
   */
  SpeciesFeatureValue* removeSpeciesFeatureValue(unsigned int n);


  /**
   * Removes the SpeciesFeatureValue with the given identifier from the ListOfSpeciesFeatureValues within this SpeciesFeature
   * and returns a pointer to it.
   *
   * The caller owns the returned item and is responsible for deleting it.
   * If none of the items in this list have the identifier @p sid, then
   * @c NULL is returned.
   *
   * @param sid the identifier of the SpeciesFeatureValue to remove.
   *
   * @return the SpeciesFeatureValue removed. As mentioned above, the caller owns the
   * returned item.
   */
  SpeciesFeatureValue* removeSpeciesFeatureValue(const std::string& sid);


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
   * Returns a List of all child SBase objects, including those nested to an
   * arbitary depth.
   *
   * @return a List* of pointers to all child objects.
   */
   virtual List* getAllElements(ElementFilter * filter = NULL);


  /**
   * Returns the XML element name of this object, which for SpeciesFeature, is
   * always @c "speciesFeature".
   *
   * @return the name of this element, i.e. @c "speciesFeature".
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
   * for this SpeciesFeature object have been set.
   *
   * @note The required attributes for a SpeciesFeature object are:
   * @li "speciesFeatureType"
   * @li "occur"
   *
   * @return a boolean value indicating whether all the required
   * attributes for this object have been defined.
   */
  virtual bool hasRequiredAttributes() const;


  /**
   * Predicate returning @c true if all the required elements
   * for this SpeciesFeature object have been set.
   *
   * @note The required elements for a SpeciesFeature object are:
   *
   * @return a boolean value indicating whether all the required
   * elements for this object have been defined.
   */
  virtual bool hasRequiredElements() const;


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
   * Connects to child elements.
   */
  virtual void connectToChild ();


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
   * return the SBML object corresponding to next XMLToken.
   */
  virtual SBase* createObject(XMLInputStream& stream);


  /** @endcond doxygenLibsbmlInternal */


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

class LIBSBML_EXTERN ListOfSpeciesFeatures : public ListOf
{

public:

  /**
   * Creates a new ListOfSpeciesFeatures with the given level, version, and package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this ListOfSpeciesFeatures
   *
   * @param version an unsigned int, the SBML Version to assign to this ListOfSpeciesFeatures
   *
   * @param pkgVersion an unsigned int, the SBML Multi Version to assign to this ListOfSpeciesFeatures
   */
  ListOfSpeciesFeatures(unsigned int level      = MultiExtension::getDefaultLevel(),
                        unsigned int version    = MultiExtension::getDefaultVersion(),
                        unsigned int pkgVersion = MultiExtension::getDefaultPackageVersion());


  /**
   * Creates a new ListOfSpeciesFeatures with the given MultiPkgNamespaces object.
   *
   * @param multins the MultiPkgNamespaces object
   */
  ListOfSpeciesFeatures(MultiPkgNamespaces* multins);


   /**
   * Creates and returns a deep copy of this ListOfSpeciesFeatures object.
   *
   * @return a (deep) copy of this ListOfSpeciesFeatures object.
   */
  virtual ListOfSpeciesFeatures* clone () const;


   /**
   * Get a SpeciesFeature from the ListOfSpeciesFeatures.
   *
   * @param n the index number of the SpeciesFeature to get.
   *
   * @return the nth SpeciesFeature in this ListOfSpeciesFeatures.
   *
   * @see size()
   */
  virtual SpeciesFeature* get(unsigned int n);


  /**
   * Get a SpeciesFeature from the ListOfSpeciesFeatures.
   *
   * @param n the index number of the SpeciesFeature to get.
   *
   * @return the nth SpeciesFeature in this ListOfSpeciesFeatures.
   *
   * @see size()
   */
  virtual const SpeciesFeature* get(unsigned int n) const;


  /**
   * Get a SpeciesFeature from the ListOfSpeciesFeatures
   * based on its identifier.
   *
   * @param sid a string representing the identifier
   * of the SpeciesFeature to get.
   *
   * @return SpeciesFeature in this ListOfSpeciesFeatures
   * with the given id or NULL if no such
   * SpeciesFeature exists.
   *
   * @see get(unsigned int n)   *
   * @see size()
   */
  virtual SpeciesFeature* get(const std::string& sid);


  /**
   * Get a SpeciesFeature from the ListOfSpeciesFeatures
   * based on its identifier.
   *
   * @param sid a string representing the identifier
   * of the SpeciesFeature to get.
   *
   * @return SpeciesFeature in this ListOfSpeciesFeatures
   * with the given id or NULL if no such
   * SpeciesFeature exists.
   *
   * @see get(unsigned int n)   *
   * @see size()
   */
  virtual const SpeciesFeature* get(const std::string& sid) const;


  /**
   * Removes the nth SpeciesFeature from this ListOfSpeciesFeatures
   * and returns a pointer to it.
   *
   * The caller owns the returned item and is responsible for deleting it.
   *
   * @param n the index of the SpeciesFeature to remove.
   *
   * @see size()
   */
  virtual SpeciesFeature* remove(unsigned int n);


  /**
   * Removes the SpeciesFeature from this ListOfSpeciesFeatures with the given identifier
   * and returns a pointer to it.
   *
   * The caller owns the returned item and is responsible for deleting it.
   * If none of the items in this list have the identifier @p sid, then
   * @c NULL is returned.
   *
   * @param sid the identifier of the SpeciesFeature to remove.
   *
   * @return the SpeciesFeature removed. As mentioned above, the caller owns the
   * returned item.
   */
  virtual SpeciesFeature* remove(const std::string& sid);


  int addSubListOfSpeciesFeatures(ListOfSpeciesFeatures* losf);

  unsigned int getNumSubListOfSpeciesFeatures() const;


   /**
   * Returns the value of the "relation" attribute of this ListOfSpeciesFeatures.
   *
   * @return the value of the "relation" attribute of this ListOfSpeciesFeatures as a FIX ME.
   */
  Relation_t getRelation() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * ListOfSpeciesFeatures's "relation" attribute has been set.
   *
   * @return @c true if this ListOfSpeciesFeatures's "relation" attribute has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetRelation() const;


  /**
   * Sets the value of the "relation" attribute of this ListOfSpeciesFeatures.
   *
   * @param relation; FIX ME value of the "relation" attribute to be set
   *
   * @return integer value indicating success/failure of the
   * function.  @if clike The value is drawn from the
   * enumeration #OperationReturnValues_t. @endif The possible values
   * returned by this function are:
   * @li LIBSBML_OPERATION_SUCCESS
   * @li LIBSBML_INVALID_ATTRIBUTE_VALUE
   */
  virtual int setRelation(Relation_t relation);


  /**
   * Unsets the value of the "relation" attribute of this ListOfSpeciesFeatures.
   *
   * @return integer value indicating success/failure of the
   * function.  @if clike The value is drawn from the
   * enumeration #OperationReturnValues_t. @endif The possible values
   * returned by this function are:
   * @li LIBSBML_OPERATION_SUCCESS
   * @li LIBSBML_OPERATION_FAILED
   */
  virtual int unsetRelation();


  /**
   * Returns the XML element name of this object, which for ListOfSpeciesFeatures, is
   * always @c "listOfSpeciesFeatures".
   *
   * @return the name of this element, i.e. @c "listOfSpeciesFeatures".
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

  /** @cond doxygenLibsbmlInternal */

  /**
   * Connects to child elements.
   */
  virtual void connectToChild ();


  /** @endcond doxygenLibsbmlInternal */



protected:

  /** @cond doxygenLibsbmlInternal */

  /**
   * Creates a new SpeciesFeature in this ListOfSpeciesFeatures
   */
  virtual SBase* createObject(XMLInputStream& stream);


  /** @endcond doxygenLibsbmlInternal */


  /** @cond doxygenLibsbmlInternal */

  /**
   * Write the namespace for the Multi package.
   */
  virtual void writeXMLNS(XMLOutputStream& stream) const;


  /** @endcond doxygenLibsbmlInternal */

  /** @cond doxygenLibsbmlInternal */
  /**
   * Subclasses should override this method to get the list of
   * expected attributes.
   * This function is invoked from corresponding readAttributes()
   * function.
   */
  virtual void addExpectedAttributes(ExpectedAttributes& attributes);
  /** @endcond */


  /** @cond doxygenLibsbmlInternal */
  /**
   * Reads the attributes of corresponding package in SBMLDocument element.
   */
  virtual void readAttributes (const XMLAttributes& attributes,
                               const ExpectedAttributes& expectedAttributes);
  /** @endcond */


  /** @cond doxygenLibsbmlInternal */
  /**
   * Writes the attributes of corresponding package in SBMLDocument element.
   */
  virtual void writeAttributes (XMLOutputStream& stream) const;  
  
  /** @endcond */

  /** @cond doxygenLibsbmlInternal */
  /**
   */
  virtual void writeElements (XMLOutputStream& stream) const;  
  
  void setIsSubList() { mIsSubList = true; };
  bool getIsSubList() const { return mIsSubList; };

  /** @endcond */

    /** @cond doxygenLibsbmlInternal */

  List * mSubListOfSpeciesFeatures;

  Relation_t mRelation;

  bool mIsSubList;


  /** @endcond */


};



LIBSBML_CPP_NAMESPACE_END

#endif  /*  __cplusplus  */

#ifndef SWIG

LIBSBML_CPP_NAMESPACE_BEGIN
BEGIN_C_DECLS

LIBSBML_EXTERN
SpeciesFeature_t *
SpeciesFeature_create(unsigned int level, unsigned int version,
                      unsigned int pkgVersion);


LIBSBML_EXTERN
void
SpeciesFeature_free(SpeciesFeature_t * sf);


LIBSBML_EXTERN
SpeciesFeature_t *
SpeciesFeature_clone(SpeciesFeature_t * sf);


LIBSBML_EXTERN
char *
SpeciesFeature_getId(SpeciesFeature_t * sf);


LIBSBML_EXTERN
char *
SpeciesFeature_getSpeciesFeatureType(SpeciesFeature_t * sf);


LIBSBML_EXTERN
unsigned int
SpeciesFeature_getOccur(SpeciesFeature_t * sf);


LIBSBML_EXTERN
char *
SpeciesFeature_getComponent(SpeciesFeature_t * sf);


LIBSBML_EXTERN
int
SpeciesFeature_isSetId(SpeciesFeature_t * sf);


LIBSBML_EXTERN
int
SpeciesFeature_isSetSpeciesFeatureType(SpeciesFeature_t * sf);


LIBSBML_EXTERN
int
SpeciesFeature_isSetOccur(SpeciesFeature_t * sf);


LIBSBML_EXTERN
int
SpeciesFeature_isSetComponent(SpeciesFeature_t * sf);


LIBSBML_EXTERN
int
SpeciesFeature_setId(SpeciesFeature_t * sf, const char * id);


LIBSBML_EXTERN
int
SpeciesFeature_setSpeciesFeatureType(SpeciesFeature_t * sf, const char * speciesFeatureType);


LIBSBML_EXTERN
int
SpeciesFeature_setOccur(SpeciesFeature_t * sf, unsigned int occur);


LIBSBML_EXTERN
int
SpeciesFeature_setComponent(SpeciesFeature_t * sf, const char * component);


LIBSBML_EXTERN
int
SpeciesFeature_unsetId(SpeciesFeature_t * sf);


LIBSBML_EXTERN
int
SpeciesFeature_unsetSpeciesFeatureType(SpeciesFeature_t * sf);


LIBSBML_EXTERN
int
SpeciesFeature_unsetOccur(SpeciesFeature_t * sf);


LIBSBML_EXTERN
int
SpeciesFeature_unsetComponent(SpeciesFeature_t * sf);


LIBSBML_EXTERN
int
SpeciesFeature_addSpeciesFeatureValue(SpeciesFeature_t * sf, SpeciesFeatureValue_t * sfv);


LIBSBML_EXTERN
SpeciesFeatureValue_t *
SpeciesFeature_createSpeciesFeatureValue(SpeciesFeature_t * sf);


LIBSBML_EXTERN
ListOf_t *
SpeciesFeature_getListOfSpeciesFeatureValues(SpeciesFeature_t * sf) ;


LIBSBML_EXTERN
SpeciesFeatureValue_t *
SpeciesFeature_getSpeciesFeatureValue(SpeciesFeature_t * sf, unsigned int n);


LIBSBML_EXTERN
SpeciesFeatureValue_t *
SpeciesFeature_getSpeciesFeatureValueById(SpeciesFeature_t * sf, const char * sid);


LIBSBML_EXTERN
unsigned int
SpeciesFeature_getNumSpeciesFeatureValues(SpeciesFeature_t * sf);


LIBSBML_EXTERN
SpeciesFeatureValue_t *
SpeciesFeature_removeSpeciesFeatureValue(SpeciesFeature_t * sf, unsigned int n);


LIBSBML_EXTERN
SpeciesFeatureValue_t *
SpeciesFeature_removeSpeciesFeatureValueById(SpeciesFeature_t * sf, const char * sid);


LIBSBML_EXTERN
int
SpeciesFeature_hasRequiredAttributes(SpeciesFeature_t * sf);


LIBSBML_EXTERN
int
SpeciesFeature_hasRequiredElements(SpeciesFeature_t * sf);


LIBSBML_EXTERN
SpeciesFeature_t *
ListOfSpeciesFeatures_getById(ListOf_t * lo, const char * sid);


LIBSBML_EXTERN
SpeciesFeature_t *
ListOfSpeciesFeatures_removeById(ListOf_t * lo, const char * sid);


LIBSBML_EXTERN
int 
SpeciesFeature_isValidRelation(Relation_t relation);


LIBSBML_EXTERN
int 
SpeciesFeature_isValidRelationString(const char* s);


LIBSBML_EXTERN
const char* 
Relation_toString(Relation_t relation);


LIBSBML_EXTERN
Relation_t 
Relation_fromString(const char* s);




END_C_DECLS
LIBSBML_CPP_NAMESPACE_END

#endif  /*  !SWIG  */

#endif /*  SpeciesFeature_H__  */

