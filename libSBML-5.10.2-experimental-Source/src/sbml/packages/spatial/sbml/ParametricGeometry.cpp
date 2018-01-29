/**
 * @file:   ParametricGeometry.cpp
 * @brief:  Implementation of the ParametricGeometry class
 * @author: SBMLTeam
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML.  Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2013-2014 jointly by the following organizations:
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK
 *     3. University of Heidelberg, Heidelberg, Germany
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


#include <sbml/packages/spatial/sbml/ParametricGeometry.h>
#include <sbml/packages/spatial/validator/SpatialSBMLError.h>
#include <sbml/util/ElementFilter.h>


using namespace std;


LIBSBML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new ParametricGeometry with the given level, version, and package version.
 */
ParametricGeometry::ParametricGeometry (unsigned int level, unsigned int version, unsigned int pkgVersion)
  : GeometryDefinition(level, version)
  , mSpatialPoints (level, version, pkgVersion)
  , mParametricObject (NULL)
{
  // set an SBMLNamespaces derived object of this package
  setSBMLNamespacesAndOwn(new SpatialPkgNamespaces(level, version, pkgVersion));

  // connect to child objects
  connectToChild();
}


/*
 * Creates a new ParametricGeometry with the given SpatialPkgNamespaces object.
 */
ParametricGeometry::ParametricGeometry (SpatialPkgNamespaces* spatialns)
  : GeometryDefinition(spatialns)
  , mSpatialPoints (spatialns)
  , mParametricObject (NULL)
{
  // set the element namespace of this object
  setElementNamespace(spatialns->getURI());

  // connect to child objects
  connectToChild();

  // load package extensions bound with this object (if any) 
  loadPlugins(spatialns);
}


/*
 * Copy constructor for ParametricGeometry.
 */
ParametricGeometry::ParametricGeometry (const ParametricGeometry& orig)
  : GeometryDefinition(orig)
{
  if (&orig == NULL)
  {
    throw SBMLConstructorException("Null argument to copy constructor");
  }
  else
  {
    mSpatialPoints  = orig.mSpatialPoints;
    if (orig.mParametricObject != NULL)
    {
      mParametricObject = orig.mParametricObject->clone();
    }
    else
    {
      mParametricObject = NULL;
    }

    // connect to child objects
    connectToChild();
  }
}


/*
 * Assignment for ParametricGeometry.
 */
ParametricGeometry&
ParametricGeometry::operator=(const ParametricGeometry& rhs)
{
  if (&rhs == NULL)
  {
    throw SBMLConstructorException("Null argument to assignment");
  }
  else if (&rhs != this)
  {
    GeometryDefinition::operator=(rhs);
    mSpatialPoints  = rhs.mSpatialPoints;
    if (rhs.mParametricObject != NULL)
    {
      mParametricObject = rhs.mParametricObject->clone();
    }
    else
    {
      mParametricObject = NULL;
    }

    // connect to child objects
    connectToChild();
  }
  return *this;
}


/*
 * Clone for ParametricGeometry.
 */
ParametricGeometry*
ParametricGeometry::clone () const
{
  return new ParametricGeometry(*this);
}


/*
 * Destructor for ParametricGeometry.
 */
ParametricGeometry::~ParametricGeometry ()
{
  delete mParametricObject;
  mParametricObject = NULL;
}


/*
 * Returns the value of the "parametricObject" attribute of this ParametricGeometry.
 */
const ParametricObject*
ParametricGeometry::getParametricObject() const
{
  return mParametricObject;
}


/*
 * Returns the value of the "parametricObject" attribute of this ParametricGeometry.
 */
ParametricObject*
ParametricGeometry::getParametricObject()
{
  return mParametricObject;
}


/*
 * Creates a new "parametricObject" element of this ParametricGeometry and returns it.
 */
ParametricObject*
ParametricGeometry::createParametricObject()
{
  if (mParametricObject != NULL) delete mParametricObject;
  SPATIAL_CREATE_NS(spatialns, getSBMLNamespaces());
  mParametricObject = new ParametricObject(spatialns);
  delete spatialns;
  connectToChild();
  return mParametricObject;
}


/*
 * Returns true/false if parametricObject is set.
 */
bool
ParametricGeometry::isSetParametricObject() const
{
  return (mParametricObject != NULL);
}


/*
 * Sets parametricObject and returns value indicating success.
 */
int
ParametricGeometry::setParametricObject(ParametricObject* parametricObject)
{
  if (mParametricObject == parametricObject)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else if (parametricObject == NULL)
  {
    delete mParametricObject;
    mParametricObject = NULL;
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    delete mParametricObject;
    mParametricObject = (parametricObject != NULL) ?
      static_cast<ParametricObject*>(parametricObject->clone()) : NULL;
    if (mParametricObject != NULL)
    {
      mParametricObject->connectToParent(this);
    }
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Unsets parametricObject and returns value indicating success.
 */
int
ParametricGeometry::unsetParametricObject()
{
  delete mParametricObject;
  mParametricObject = NULL;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Returns the  "ListOfSpatialPoints" in this ParametricGeometry object.
 */
const ListOfSpatialPoints*
ParametricGeometry::getListOfSpatialPoints() const
{
  return &mSpatialPoints;
}


/*
 * Returns the  "ListOfSpatialPoints" in this ParametricGeometry object.
 */
ListOfSpatialPoints*
ParametricGeometry::getListOfSpatialPoints()
{
  return &mSpatialPoints;
}


/*
 * Removes the nth SpatialPoint from the ListOfSpatialPoints.
 */
SpatialPoint*
ParametricGeometry::removeSpatialPoint(unsigned int n)
{
	return mSpatialPoints.remove(n);
}


/*
 * Removes the a SpatialPoint with given id from the ListOfSpatialPoints.
 */
SpatialPoint*
ParametricGeometry::removeSpatialPoint(const std::string& sid)
{
	return mSpatialPoints.remove(sid);
}


/*
 * Return the nth SpatialPoint in the ListOfSpatialPoints within this ParametricGeometry.
 */
SpatialPoint*
ParametricGeometry::getSpatialPoint(unsigned int n)
{
	return mSpatialPoints.get(n);
}


/*
 * Return the nth SpatialPoint in the ListOfSpatialPoints within this ParametricGeometry.
 */
const SpatialPoint*
ParametricGeometry::getSpatialPoint(unsigned int n) const
{
	return mSpatialPoints.get(n);
}


/*
 * Return a SpatialPoint from the ListOfSpatialPoints by id.
 */
SpatialPoint*
ParametricGeometry::getSpatialPoint(const std::string& sid)
{
	return mSpatialPoints.get(sid);
}


/*
 * Return a SpatialPoint from the ListOfSpatialPoints by id.
 */
const SpatialPoint*
ParametricGeometry::getSpatialPoint(const std::string& sid) const
{
	return mSpatialPoints.get(sid);
}


/*
 * Adds a copy the given "SpatialPoint" to this ParametricGeometry.
 *
 * @param sp; the SpatialPoint object to add
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li LIBSBML_OPERATION_SUCCESS
 * @li LIBSBML_INVALID_ATTRIBUTE_VALUE
 */
int
ParametricGeometry::addSpatialPoint(const SpatialPoint* sp)
{
  if (sp == NULL)
  {
    return LIBSBML_OPERATION_FAILED;
  }
  else if (sp->hasRequiredAttributes() == false)
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else if (getLevel() != sp->getLevel())
  {
    return LIBSBML_LEVEL_MISMATCH;
  }
  else if (getVersion() != sp->getVersion())
  {
    return LIBSBML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSBMLNamespacesForAddition(static_cast<const SBase *>(sp)) == false)
  {
    return LIBSBML_NAMESPACES_MISMATCH;
  }
  else
  {
    mSpatialPoints.append(sp);
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Get the number of SpatialPoint objects in this ParametricGeometry.
 *
 * @return the number of SpatialPoint objects in this ParametricGeometry
 */
unsigned int
ParametricGeometry::getNumSpatialPoints() const
{
  return mSpatialPoints.size();
}


/*
 * Creates a new SpatialPoint object, adds it to this ParametricGeometrys
 * ParametricGeometry and returns the SpatialPoint object created. 
 *
 * @return a new SpatialPoint object instance
 *
 * @see addSpatialPoint(const SpatialPoint* sp)
 */
SpatialPoint*
ParametricGeometry::createSpatialPoint()
{
  SpatialPoint* sp = NULL;

  try
  {
    SPATIAL_CREATE_NS(spatialns, getSBMLNamespaces());
    sp = new SpatialPoint(spatialns);
    delete spatialns;
  }
  catch (...)
  {
    /* here we do not create a default object as the level/version must
     * match the parent object
     *
     * do nothing
     */
  }

  if(sp != NULL)
  {
    mSpatialPoints.appendAndOwn(sp);
  }

  return sp;
}


List*
ParametricGeometry::getAllElements(ElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;

  ADD_FILTERED_POINTER(ret, sublist, mParametricObject, filter);

  ADD_FILTERED_FROM_PLUGIN(ret, sublist, filter);

  return ret;
}


/*
 * Returns the XML element name of this object
 */
const std::string&
ParametricGeometry::getElementName () const
{
  static const string name = "parametricGeometry";
  return name;
}


/*
 * Returns the libSBML type code for this SBML object.
 */
int
ParametricGeometry::getTypeCode () const
{
  return SBML_SPATIAL_PARAMETRICGEOMETRY;
}


/*
 * check if all the required attributes are set
 */
bool
ParametricGeometry::hasRequiredAttributes () const
{
  bool allPresent = GeometryDefinition::hasRequiredAttributes();

  return allPresent;
}


/*
 * check if all the required elements are set
 */
bool
ParametricGeometry::hasRequiredElements () const
{
  bool allPresent = GeometryDefinition::hasRequiredElements();

  return allPresent;
}


  /** @cond doxygenLibsbmlInternal */

/*
 * write contained elements
 */
void
ParametricGeometry::writeElements (XMLOutputStream& stream) const
{
  GeometryDefinition::writeElements(stream);
  if (getNumSpatialPoints() > 0)
  {
    mSpatialPoints.write(stream);
  }

  if (isSetParametricObject() == true)
  {
    mParametricObject->write(stream);
  }
  SBase::writeExtensionElements(stream);
}


  /** @endcond doxygenLibsbmlInternal */


  /** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor.
 */
bool
ParametricGeometry::accept (SBMLVisitor& v) const
{
  v.visit(*this);

/* VISIT CHILDREN */

  v.leave(*this);

  return true;
}


  /** @endcond doxygenLibsbmlInternal */


  /** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument.
 */
void
ParametricGeometry::setSBMLDocument (SBMLDocument* d)
{
  GeometryDefinition::setSBMLDocument(d);
  mSpatialPoints.setSBMLDocument(d);
  if (mParametricObject != NULL)
    mParametricObject->setSBMLDocument(d);
}


  /** @endcond doxygenLibsbmlInternal */


  /** @cond doxygenLibsbmlInternal */

/*
   * Connects to child elements.
 */
void
ParametricGeometry::connectToChild()
{
  GeometryDefinition::connectToChild();

  mSpatialPoints.connectToParent(this);
  if (mParametricObject != NULL)
    mParametricObject->connectToParent(this);
}


  /** @endcond doxygenLibsbmlInternal */


  /** @cond doxygenLibsbmlInternal */

/*
 * Enables/Disables the given package with this element.
 */
void
ParametricGeometry::enablePackageInternal(const std::string& pkgURI,
             const std::string& pkgPrefix, bool flag)
{
  GeometryDefinition::enablePackageInternal(pkgURI, pkgPrefix, flag);
  mSpatialPoints.enablePackageInternal(pkgURI, pkgPrefix, flag);
}


  /** @endcond doxygenLibsbmlInternal */


  /** @cond doxygenLibsbmlInternal */

/*
 * creates object.
 */
SBase*
ParametricGeometry::createObject(XMLInputStream& stream)
{
  SBase* object = GeometryDefinition::createObject(stream);

  const string& name = stream.peek().getName();

  SPATIAL_CREATE_NS(spatialns, getSBMLNamespaces());

  if (name == "listOfSpatialPoints")
  {
    object = &mSpatialPoints;
  }
  else if (name == "parametricObject")
  {
    mParametricObject = new ParametricObject(spatialns);
    object = mParametricObject;
  }

  delete spatialns;

  connectToChild();


  return object;
}


  /** @endcond doxygenLibsbmlInternal */


  /** @cond doxygenLibsbmlInternal */

/*
 * Get the list of expected attributes for this element.
 */
void
ParametricGeometry::addExpectedAttributes(ExpectedAttributes& attributes)
{
  GeometryDefinition::addExpectedAttributes(attributes);

}


  /** @endcond doxygenLibsbmlInternal */


  /** @cond doxygenLibsbmlInternal */

/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
ParametricGeometry::readAttributes (const XMLAttributes& attributes,
                             const ExpectedAttributes& expectedAttributes)
{
  const unsigned int sbmlLevel   = getLevel  ();
  const unsigned int sbmlVersion = getVersion();

  unsigned int numErrs;

  GeometryDefinition::readAttributes(attributes, expectedAttributes);

  // look to see whether an unknown attribute error was logged
  if (getErrorLog() != NULL)
  {
    numErrs = getErrorLog()->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (getErrorLog()->getError(n)->getErrorId() == UnknownPackageAttribute)
      {
        const std::string details =
                          getErrorLog()->getError(n)->getMessage();
        getErrorLog()->remove(UnknownPackageAttribute);
        getErrorLog()->logPackageError("spatial", SpatialUnknownError,
                       getPackageVersion(), sbmlLevel, sbmlVersion, details);
      }
      else if (getErrorLog()->getError(n)->getErrorId() == UnknownCoreAttribute)
      {
        const std::string details =
                          getErrorLog()->getError(n)->getMessage();
        getErrorLog()->remove(UnknownCoreAttribute);
        getErrorLog()->logPackageError("spatial", SpatialUnknownError,
                       getPackageVersion(), sbmlLevel, sbmlVersion, details);
      }
    }
  }

  bool assigned = false;

}


  /** @endcond doxygenLibsbmlInternal */


  /** @cond doxygenLibsbmlInternal */

/*
 * Write values of XMLAttributes to the output stream.
 */
  void
ParametricGeometry::writeAttributes (XMLOutputStream& stream) const
{
  GeometryDefinition::writeAttributes(stream);

}


  /** @endcond doxygenLibsbmlInternal */


LIBSBML_EXTERN
ParametricGeometry_t *
ParametricGeometry_create(unsigned int level, unsigned int version,
                          unsigned int pkgVersion)
{
  return new ParametricGeometry(level, version, pkgVersion);
}


LIBSBML_EXTERN
void
ParametricGeometry_free(ParametricGeometry_t * pg)
{
  if (pg != NULL)
    delete pg;
}


LIBSBML_EXTERN
ParametricGeometry_t *
ParametricGeometry_clone(ParametricGeometry_t * pg)
{
  if (pg != NULL)
  {
    return static_cast<ParametricGeometry_t*>(pg->clone());
  }
  else
  {
    return NULL;
  }
}


LIBSBML_EXTERN
ParametricObject_t*
ParametricGeometry_getParametricObject(ParametricGeometry_t * pg)
{
	if (pg == NULL)
		return NULL;

	return (ParametricObject_t*)pg->getParametricObject();
}


LIBSBML_EXTERN
ParametricObject_t*
ParametricGeometry_createParametricObject(ParametricGeometry_t * pg)
{
	if (pg == NULL)
		return NULL;

	return (ParametricObject_t*)pg->createParametricObject();
}


LIBSBML_EXTERN
int
ParametricGeometry_isSetParametricObject(const ParametricGeometry_t * pg)
{
  return (pg != NULL) ? static_cast<int>(pg->isSetParametricObject()) : 0;
}


LIBSBML_EXTERN
int
ParametricGeometry_setParametricObject(ParametricGeometry_t * pg, ParametricObject_t* parametricObject)
{
	return (pg != NULL) ? pg->setParametricObject(parametricObject) : LIBSBML_INVALID_OBJECT;
}


LIBSBML_EXTERN
int
ParametricGeometry_addSpatialPoint(ParametricGeometry_t * pg, SpatialPoint_t * sp)
{
	return  (pg != NULL) ? pg->addSpatialPoint(sp) : LIBSBML_INVALID_OBJECT;
}

LIBSBML_EXTERN
SpatialPoint_t *
ParametricGeometry_createSpatialPoint(ParametricGeometry_t * pg)
{
	return  (pg != NULL) ? pg->createSpatialPoint() : NULL;
}

LIBSBML_EXTERN
ListOf_t *
ParametricGeometry_getListOfSpatialPoints(ParametricGeometry_t * pg)
{
	return  (pg != NULL) ? (ListOf_t *)pg->getListOfSpatialPoints() : NULL;
}

LIBSBML_EXTERN
SpatialPoint_t *
ParametricGeometry_getSpatialPoint(ParametricGeometry_t * pg, unsigned int n)
{
	return  (pg != NULL) ? pg->getSpatialPoint(n) : NULL;
}

LIBSBML_EXTERN
SpatialPoint_t *
ParametricGeometry_getSpatialPointById(ParametricGeometry_t * pg, const char * sid)
{
	return  (pg != NULL) ? pg->getSpatialPoint(sid) : NULL;
}

LIBSBML_EXTERN
unsigned int
ParametricGeometry_getNumSpatialPoints(ParametricGeometry_t * pg)
{
	return  (pg != NULL) ? pg->getNumSpatialPoints() : SBML_INT_MAX;
}

LIBSBML_EXTERN
SpatialPoint_t *
ParametricGeometry_removeSpatialPoint(ParametricGeometry_t * pg, unsigned int n)
{
	return  (pg != NULL) ? pg->removeSpatialPoint(n) : NULL;
}

LIBSBML_EXTERN
SpatialPoint_t *
ParametricGeometry_removeSpatialPointById(ParametricGeometry_t * pg, const char * sid)
{
	return  (pg != NULL) ? pg->removeSpatialPoint(sid) : NULL;
}

LIBSBML_EXTERN
int
ParametricGeometry_hasRequiredAttributes(const ParametricGeometry_t * pg)
{
  return (pg != NULL) ? static_cast<int>(pg->hasRequiredAttributes()) : 0;
}


LIBSBML_EXTERN
int
ParametricGeometry_hasRequiredElements(const ParametricGeometry_t * pg)
{
	return (pg != NULL) ? static_cast<int>(pg->hasRequiredElements()) : 0;
}




LIBSBML_CPP_NAMESPACE_END


